#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "dinamo.h"
#include "functions.h"

int AAP_API ListObjsCallback(char* szObjName, void* pParam, BOOL bFinal)
{
    UNUSED(pParam);

    if (!bFinal)
        fprintf(stdout, "\t%s\n", szObjName);

    return 0;
}

void CreateSampleUsers(HSESSIONCTX* session) {
    struct USER_INFO userInfo[2] = { 0 };
    int nRet;

    // user "ensaios01" configs
    strncpy(userInfo[0].szUserId, USER1_ID, sizeof(userInfo[0].szUserId));
    strncpy(userInfo[0].szPassword, GENERAL_PWD, sizeof(userInfo[0].szPassword));

    userInfo[0].dwAuthMask = ACL_OBJ_DEL | ACL_OBJ_READ | ACL_OBJ_CREATE | ACL_OBJ_UPDATE;

    // user "ensaios02" configs
    strncpy(userInfo[1].szUserId, USER2_ID, sizeof(userInfo[1].szUserId));
    strncpy(userInfo[1].szPassword, GENERAL_PWD, sizeof(userInfo[1].szPassword));

    userInfo[0].dwAuthMask = ACL_OBJ_DEL | ACL_OBJ_READ | ACL_OBJ_CREATE | ACL_OBJ_UPDATE;

    // cria os usuarios "ensaios01" e "ensaios02"
    for (int i = 0; i < 2; i++) {
        printf("Criando usuario %d.\n", i + 1);
        nRet = DCreateUser(*session, userInfo[i]);

        if (nRet) {
            printf("Falha na funcao: DCreateUser \nCodigo de erro: %d.\n", nRet);
            clean(session);
        }
    }
}

void RandomGeneratorAnalysis(HSESSIONCTX *session, unsigned int buffer_length, unsigned long sample_amount, char *filename){
    BYTE *randomNumberBuffer = NULL;
    FILE *output_file = NULL;
    char name[50];
    int return_code;

    printf("\n-------- Extraindo numeros aleatorios. --------\n");
    randomNumberBuffer = (BYTE*) malloc(buffer_length);

    if (randomNumberBuffer == NULL) {
        printf("Erro alocando o buffer de dados.\n");
        clean(session);
    }

    strcpy_s(name, sizeof(name), filename);

    output_file = fopen(name, "w");

    if (output_file == NULL) {
        printf("Falha na criação do arquivo de saída.\n");
        clean(session);
    }

    for (unsigned int i = 0; i < sample_amount; i += buffer_length) {
        return_code = DGetRandom(*session, randomNumberBuffer, buffer_length);
        if (return_code) {
            printf("Falha na extração: DGetRandom \nCodigo de erro: %d\n", return_code);
            clean(session);
        }

        fwrite(randomNumberBuffer, sizeof(BYTE), buffer_length, output_file);
    }

    fclose(output_file);
    free(randomNumberBuffer);
    printf("-------- Fim da extracao de numeros aleatorios --------\n");
}

void clean(HSESSIONCTX *session) {
    HSESSIONCTX hSession = NULL;

    printf("\n-------- Limpando sessao, removendo usuarios e objetos e finalizando programa --------\n");

    LogInHSM(&hSession, GENERAL_PWD, MASTER_ID, HOST_ADDR);
    DRemoveUser(hSession, USER1_ID);
    DRemoveUser(hSession, USER2_ID);
    DRemoveObj(hSession, "CHAVEA3");
    DRemoveObj(hSession, "CHAVES3");
    DRemoveObj(hSession, "CHAVESIMETRICA");
    DCloseSession(&hSession, 0);

    if (*session) {
        DCloseSession(session, 0);
        printf("Sessao encerrada.\n");
    }

    DFinalize();
    printf("Bibliotecas liberadas.\n");

    printf("Encerrando programa.\n");
    exit(1);
}

void LogInHSM(HSESSIONCTX *session, char *password, char *ID, char *address){
    
    struct AUTH_PWD authPwd;
    int nRet;
    
    printf("\nLogando no usuario \"%s\"\n", ID);

    if (*session) {
        DCloseSession(session, 0);
        printf("Sessões previas encerradas.\n");
    }

    strncpy(authPwd.szAddr, address, sizeof(authPwd.szAddr));
    authPwd.nPort = DEFAULT_PORT;
    strncpy(authPwd.szUserId, ID, sizeof(authPwd.szUserId));
    strncpy(authPwd.szPassword, password, sizeof(authPwd.szPassword));

    nRet = DOpenSession(session, SS_USER_PWD, (BYTE*)&authPwd, sizeof(authPwd), ENCRYPTED_CONN);

    if (nRet) {
        printf("Falha na funcao: DOpenSession \nCodigo de erro: %d\n", nRet);
        clean(session);
    }

    printf("Sessao com o Dinamo estabelecida.\n");
}

void VerifySecretContentProtection(HSESSIONCTX *session) {

    HSESSIONCTX local_session = NULL;
    HKEYCTX RSA_key = NULL;
    int nRet;

    CreateSampleUsers(session);
    printf("\n-------- Teste de gerenciamento de chaves --------\n");
    
    printf("Deslogando do operador \"master\" e logando no usuario \"%s\".\n", USER1_ID);
    DCloseSession(session, 0); // fecha a sessão anterior (master)

    // loga no usuario 1
    LogInHSM(&local_session, GENERAL_PWD, USER1_ID, HOST_ADDR);
    printf("Logado com sucesso no usuario \"%s\".\n", USER1_ID);

    // cria a chave RSA
    printf("Criando chave RSA \"CHAVEASSIMETRICA\" no usuario \"%s\"\n", USER1_ID);
    nRet = DGenerateKey(local_session, "CHAVEASSIMETRICA", ALG_RSA_1024, FLAGS, &RSA_key);
    if (nRet) {
        printf("Falha na funcao: DGenerateKey \nCodigo de erro: %d\n", nRet);
        clean(&local_session);
    }
    printf("Chave RSA \"CHAVEASSIMETRICA\" criada no usuario \"%s\".\n", USER1_ID);

    printf("Deslogando do operador \"%s\" e logando no usuario \"%s\".\n", USER1_ID, USER2_ID);
    DCloseSession(&local_session, 0); // fecha a sessão anterior (ensaios01)

    // loga no usuario 2
    LogInHSM(&local_session, GENERAL_PWD, USER2_ID, HOST_ADDR);
    printf("Logado com sucesso no usuario \"%s\".\n", USER2_ID);

    // lista as chaves no usuario 2
    printf("Invocando comando de leitura das chaves para tentar ler as chaves do usuario anterior.\n");
    nRet = DListObjs(local_session, ListObjsCallback, NULL);
    if (nRet) {
        printf("Falha na funcao: DListObjs \nCodigo de erro: %d\n", nRet);
        clean(&local_session);
    }

    // tenta deletar as chaves do usuario 1
    printf("Invocando comando de deletar o par de chave \"CHAVEASSIMETRICA\" criado no usuario \"%s\" logado como usuario \"%s\".\n", USER1_ID, USER2_ID);
    nRet = DRemoveObj(local_session, "CHAVEASSIMETRICA");
    if (nRet) {
        printf("Falha na funcao: DRemoveObj \nCodigo de erro: %d\n", nRet);
        if(nRet != 5004) clean(&local_session);
    }
    
    // libera o contexto da chave
    DDestroyKey(&RSA_key, 0);

    // encerra a sessão local e loga novamente no operador master
    DCloseSession(&local_session, 0);

    printf("\n-------- Fim do teste de gerenciamento de chaves --------\n");

    LogInHSM(session, GENERAL_PWD, MASTER_ID, HOST_ADDR);
}

void ExportPublicKey() {
    HSESSIONCTX local_session = NULL;
    HKEYCTX keyPair = NULL;
    BYTE pubKey[1024] = { 0 };
    DWORD pubKeyLen = sizeof(pubKey);
    int nRet;

    printf("\n-------- Teste de exportacao de chaves publicas --------\n");
    printf("Logando no usuario \"%s\".\n", USER1_ID);
    LogInHSM(&local_session, GENERAL_PWD, USER1_ID, HOST_ADDR);

    // recupera o contexto da chave criada antes
    nRet = DGetUserKey(local_session, "CHAVEASSIMETRICA", 0, &keyPair);
    if (nRet) {
        printf("Falha na funcao: DGetUserKey \nCodigo de erro: %d\n.", nRet);
        clean(&local_session);
    }

    // exporta o keypair RSA
    printf("Exportando chave publica RSA 1024 bits do usuario \"%s\".\n", USER1_ID);
    nRet = DExportKey(keyPair, NULL, PUBLICKEY_BLOB, 0, pubKey, &pubKeyLen);
    if (nRet) {
        printf("Falha na funcao: DExportKey \nCodigo de erro: %d\n.", nRet);
        clean(&local_session);
    }
    // mostra a chave pública exportada

    printf("Chave publica exportada:\n\n");
    for (DWORD i = 0; i < pubKeyLen; i++) printf("%X", pubKey[i]);
    printf("\n-------- Teste de exportacao de chaves publicas --------\n");

    DDestroyKey(&keyPair, 0);
    DCloseSession(&local_session, 0);
}

void ImportExportConformityCheck(HSESSIONCTX *session) {

    HSESSIONCTX local_session = NULL;
    HKEYCTX keyPair, ImportedKey = NULL;
    BYTE privKey[1024] = { 0 };
    DWORD privKeyLen = sizeof(privKey);
    int nRet;

    printf("\n-------- Teste de exportacao e importacao de chaves --------\n");
    // encerra sessões previas
    if (*session) DCloseSession(session, 0);

    // loga no user "ensaios 01"
    printf("Logando no usuario \"%s\".\n", USER1_ID);
    LogInHSM(&local_session, GENERAL_PWD, USER1_ID, HOST_ADDR);

    // recupera o contexto da chave criada antes
    nRet = DGetUserKey(local_session, "CHAVEASSIMETRICA", 0, &keyPair);
    if (nRet) {
        printf("Falha na funcao: DGetuserKey \nCodigo de erro: %d\n.", nRet);
        clean(&local_session);
    }

    // exporta o keypair RSA
    printf("Exportando chave privada RSA 1024 bits do usuario \"%s\".\n", USER1_ID);
    nRet = DExportKey(keyPair, NULL, PRIVATEKEY_BLOB, 0, privKey, &privKeyLen);
    if (nRet) {
        printf("Falha na funcao: DExportKey \nCodigo de erro: %d\n.", nRet);
        clean(&local_session);
    }

    // encerra a sessao no user "ensaios01"
    DCloseSession(&local_session, 0);

    // loga no user "ensaios02"
    printf("Logando no usuario \"%s\".\n", USER2_ID);
    LogInHSM(&local_session, GENERAL_PWD, USER2_ID, HOST_ADDR);

    // tenta importar a chave exportada do usuario "ensaios01"
    printf("Tentativa de importar a chave privada RSA 1024 bits do usuario \"%s\".\n", USER1_ID);
    nRet = DImportKey(local_session, "CHAVEIMPORTADA", NULL, PRIVATEKEY_BLOB, D_IMPORT_ALG_PRIV_KEY_RSA, 0, privKey, privKeyLen, &ImportedKey);
    if (nRet) {
        printf("Falha na funcao: DImportKey\nCodigo de erro: %d\n", nRet);
        clean(&local_session);
    }

    // importa uma chave 
    // loga em outro usuario
    // tenta exportar a chave importada


    // libera o contexto das chaves
    DDestroyKey(&keyPair, 0);
    DDestroyKey(&ImportedKey, 0);

    // encerra a sessão local e loga novamente no operador master
    DCloseSession(&local_session, 0);
    printf("\n-------- Fim do teste de exportacao e importacao de chaves --------\n");

    LogInHSM(session, GENERAL_PWD, MASTER_ID, HOST_ADDR);
}

void CreateA3Like(HSESSIONCTX *session) {
    HKEYCTX A3_Key = NULL;
    int nRet;

    LogInHSM(session, GENERAL_PWD, MASTER_ID, HOST_ADDR);

    // gerando chave do tipo RSA 1024 bits nao exportavel (dwFlags = 0)
    printf("Criando chave assimetrica privada nao exportavel A3.\n");
    nRet = DGenerateKey(*session, "CHAVEA3", ALG_RSA_1024, 0, &A3_Key);
    if ((nRet)&&(nRet != 5022)) {
        printf("Falha na funcao: DGenerateKey \nCodigo de erro: %d.\n", nRet);
        clean(session);
    }

    printf("Chave RSA privada A3 e nao exportavel criada com sucesso.");
    DDestroyKey(&A3_Key, 0);
}

void CreateNonExportableSymmetricKey(HSESSIONCTX* session) {
    HKEYCTX sym_key = NULL;
    int nRet;

    LogInHSM(session, GENERAL_PWD, MASTER_ID, HOST_ADDR);

    // gerando chave do tipo DES nao exportavel (dwFlags = 0)
    printf("Criando chave simetrica nao exportavel.\n");
    nRet = DGenerateKey(*session, "CHAVESIMETRICA", ALG_3DES_168, 0, &sym_key);
    if ((nRet) && (nRet != 5022)) {
        printf("Falha na funcao: DGenerateKey \nCodigo de erro: %d.\n", nRet);
        clean(session);
    }

    printf("Chave simétrica e nao exportavel criada com sucesso.");
    DDestroyKey(&sym_key, 0);
}

void CreateS3Like(HSESSIONCTX* session) {
    HKEYCTX S3_Key = NULL;
    int nRet;

    LogInHSM(session, GENERAL_PWD, MASTER_ID, HOST_ADDR);

    // gerando chave do tipo RSA 1024 bits nao exportavel (dwFlags = 0)
    printf("Criando chave assimetrica privada nao exportavel S3.\n");
    nRet = DGenerateKey(*session, "CHAVES3", ALG_RSA_1024, 0, &S3_Key);
    if ((nRet) && (nRet != 5022)) {
        printf("Falha na funcao: DGenerateKey \nCodigo de erro: %d.\n", nRet);
        clean(session);
    }

    printf("Chave RSA privada S3 e nao exportavel criada com sucesso.");
    DDestroyKey(&S3_Key, 0);
}