#include <windows.h>
#include <stdio.h>
 
#include <dinamo.h> /* header do Dinamo */
 
#define HOST_ADDR       "10.10.4.13"
#define USER_ID         "master"
#define USER_PWD        "12345678"
 
#define HASH_ID    ALG_SHA1

#define SYMMETRIC_KEY_ID      "KEY_AES"
#define SYMMETRIC_KEY_TYPE    ALG_AES_128
 
#define ASSYMETRIC_KEY_ID      "KEY_RSA"
#define ASSYMETRIC_KEY_TYPE    ALG_RSA_1024

#define FLAGS       EXPORTABLE_KEY | NO_CRYPTO 

void main ()
{
    int nRet;
    struct AUTH_PWD authPwd;
    HHASHCTX hHash = NULL;
    HSESSIONCTX hSession = NULL;
    HKEYCTX Symmetric_Key = NULL;
    HKEYCTX Assymmetric_Key = NULL;
    DWORD dwDataLen, 
          dwKeyType, 
          dwPadding, 
          dwReadLocked, 
          dwKeyLen,
          dwMode;
    BYTE *pbData;
    DWORD cbData;
    BYTE *pbSignature = NULL;
    DWORD cbSignature;
    int i;
     
    //Inicializa as bibliotecas do Dinamo
    nRet = DInitialize(0);
     
    if (nRet){
        printf("Falha na funcao: DInitialize \nCodigo de erro: %d\n",nRet);
        exit(1);
    }
     
    printf("Bibliotecas inicializadas.\n");
     
    //Inicializa a estrutura para conexão com o HSM
    strncpy(authPwd.szAddr, HOST_ADDR, sizeof(authPwd.szAddr));
    authPwd.nPort = DEFAULT_PORT;
    strncpy(authPwd.szUserId, USER_ID, sizeof(authPwd.szUserId));
    strncpy(authPwd.szPassword, USER_PWD, sizeof(authPwd.szPassword));
     
    nRet = DOpenSession(&hSession, SS_USER_PWD, (BYTE *)&authPwd, sizeof(authPwd), ENCRYPTED_CONN);
     
    if (nRet){
        printf("Falha na funcao: DOpenSession \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Sessao com o Dinamo estabelecida.\n");
    
    // Geração de chave simétrica
    printf("==== Gerando chave simétrica AES 128 bits no módulo ====\n");
    nRet = DGenerateKey(hSession, SYMMETRIC_KEY_ID, SYMMETRIC_KEY_TYPE, FLAGS, &Symmetric_Key); 
     
    if (nRet){
        printf("Falha na funcao: DGenerateKey \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
    else printf("Chave simétrica gerada com sucesso.")
    printf("==== Fim da geração de chave simétrica ====\n");
    
    // Geração de chave assimetrica
    printf("==== Gerando chave assimétrica RSA 1024 bits no módulo ====\n");
    nRet = DGenerateKey(hSession, ASSYMETRIC_KEY_ID, ASSYMETRIC_KEY_TYPE, FLAGS, &Assymmetric_Key); 
     
    if (nRet){
        printf("Falha na funcao: DGenerateKey \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
    else printf("Chave assimétrica gerada com sucesso.");
    printf("==== Fim da geração de chave assimétrica ====");
     
    // Lista chaves criadas no módulo
    printf("==== Lista das chaves no módulo ====\n");
     
    nRet = DListObjs(hSession, ListObjsCallback, NULL);
     
    if (nRet) {
       printf("Falha na funcao: DListObjs \nCodigo de erro: %d\n",nRet);
       goto clean;
    }
    printf("==== Fim da listagem de chaves no módulo ====\n");

    // Lista parâmetros da chave simétrica
    printf("==== Parâmetros da chave simétrica ====\n");
    nRet = DGetUserKey(hSession, KEY_ID, 0, &Symmetric_Key);
     
    if (nRet){
        printf("Falha na funcao: DGetUserKey \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    /* Algoritmo */ 
    dwDataLen = sizeof(DWORD);
    nRet = DGetKeyParam(Symmetric_Key, DKP_ALGID, (BYTE *)&dwKeyType, &dwDataLen, 0);
     
    if (nRet){
        printf("Falha na funcao: DGetKeyParam \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Tipo da chave %d\n", dwKeyType);
     
    /* Tamanho */ 
    dwDataLen = sizeof(DWORD);
    nRet = DGetKeyParam(Symmetric_Key, DKP_KEYLEN, (BYTE *)&dwKeyLen, &dwDataLen, 0);
     
    if (nRet){
        printf("Falha na funcao: DGetKeyParam \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Tamanho da chave %d bits\n", dwKeyLen * 8);
     
    dwDataLen = sizeof(dwReadLocked);
    nRet = DGetKeyParam(Symmetric_Key, DKP_READ_LOCK, (BYTE *)&dwReadLocked, &dwDataLen, 0);
     
    if (nRet){
        printf("Falha na funcao: DGetKeyParam \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Chave exportavel? %s\n", dwReadLocked == 1 ? "Nao" : "Sim"); 
     
    if (IsRSAKey(dwKeyType)){
        printf("Fim dos atributos de chaves assimetricas.\n");
        goto clean;
    }
     
    /* IV */
    //Recupera o tamanho do IV (memória necessária)
    dwDataLen = 0;
    nRet = DGetKeyParam(Symmetric_Key, DKP_IV, NULL, &dwDataLen, 0);
     
    if (nRet){
        printf("Falha na funcao: DGetKeyParam \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    pbData = (BYTE *)malloc(dwDataLen);
     
    nRet = DGetKeyParam(Symmetric_Key, DKP_IV, pbData, &dwDataLen, 0);
     
    if (nRet){
        printf("Falha na funcao: DGetKeyParam \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("IV: ");
    for (i = 0; i < (int)dwDataLen; i++) printf("%02x ", pbData[i]);
    printf("\n");
     
    free(pbData);
     
    /* Padding */
    dwDataLen = sizeof(DWORD);
    nRet = DGetKeyParam(Symmetric_Key, DKP_PADDING, (BYTE *)&dwPadding, &dwDataLen, 0);
     
    if (nRet){
        printf("Falha na funcao: DGetKeyParam \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Tipo Padding %d\n", dwPadding); 
     
    /* Modo de operacao de criptografia simetrica */
    dwDataLen = sizeof(dwMode);
    nRet = DGetKeyParam(Symmetric_Key, DKP_MODE, (BYTE *)&dwMode, &dwDataLen, 0);
     
    if (nRet){
        printf("Falha na funcao: DGetKeyParam \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Modo de operacao %d\n", dwMode)
    printf("==== Fim dos parâmetros da chave simétrica ====\n");

    // Lista parâmetros da chave assimétrica
    printf("==== Parâmetros da chave assimétrica ====\n");
    nRet = DGetUserKey(hSession, KEY_ID, 0, &Assymmetric_Key);
     
    if (nRet){
        printf("Falha na funcao: DGetUserKey \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    /* Algoritmo */
    dwDataLen = sizeof(DWORD);
    nRet = DGetKeyParam(Assymmetric_Key, DKP_ALGID, (BYTE *)&dwKeyType, &dwDataLen, 0);
     
    if (nRet){
        printf("Falha na funcao: DGetKeyParam \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Tipo da chave %d\n", dwKeyType);
     
    /* Tamanho */
    dwDataLen = sizeof(DWORD);
    nRet = DGetKeyParam(Assymmetric_Key, DKP_KEYLEN, (BYTE *)&dwKeyLen, &dwDataLen, 0);
     
    if (nRet){
        printf("Falha na funcao: DGetKeyParam \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Tamanho da chave %d bits\n", dwKeyLen * 8);
     
    dwDataLen = sizeof(dwReadLocked);
    nRet = DGetKeyParam(Assymmetric_Key, DKP_READ_LOCK, (BYTE *)&dwReadLocked, &dwDataLen, 0);
     
    if (nRet){
        printf("Falha na funcao: DGetKeyParam \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Chave exportavel? %s\n", dwReadLocked == 1 ? "Nao" : "Sim"); 
    printf("==== Fim dos parâmetros da chave assimétrica ====\n");

    // Assina e verifica com chave simétrica
    printf("==== Assinatura e verificação de um hash com a chave simétrica ====\n");
    nRet = DCreateHash(hSession, HASH_ID, 0, 0, &hHash);
     
    if (nRet){
        printf("Falha na funcao: DCreateHash \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
    printf("Hash criado\n");

    cbData = sizeof(pbData);
    memset(pbData, 'A', cbData);
 
    nRet = DHashData(hHash, pbData, cbData, 0);
     
    if (nRet){
        printf("Falha na funcao: DHashData \nCodigo de erro: %d\n",nRet);
        goto clean;
    } 
    printf("Dados adicionados ao hash.\n");
     
    nRet = DSignHash(hHash, Symmetric_Key, 0, NULL, &cbSignature);
     
    if (D_MORE_DATA != nRet){
        printf("Falha na funcao: DSignHash \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Tamanho da assinatura: %d bytes.\n", cbSignature);
     
    pbSignature = NULL;
    pbSignature = malloc(cbSignature);
     
    nRet = DSignHash(hHash, Symmetric_Key, 0, pbSignature, &cbSignature);
     
    if (nRet){
        printf("Falha na funcao: DSignHash \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
    printf("Buffer assinado.\n");
     
    nRet = DVerifySignature(hHash, pbSignature, cbSignature, Symmetric_Key, 0);
     
    if (nRet){
        printf("Falha na funcao: DVerifySignature \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
    printf("Assinatura verificada com sucesso.\n");
    printf("==== Fim da assinatura e verificação com chave simétrica====\n");

    // Assina e verifica um hash com a chave assimétrica
    printf("==== Assinatura e verificação de um hash com a chave assimétrica ====\n");     
    nRet = DSignHash(hHash, Assymmetric_Key, 0, NULL, &cbSignature);
     
    if (D_MORE_DATA != nRet){
        printf("Falha na funcao: DSignHash \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Tamanho da assinatura: %d bytes.\n", cbSignature);
     
    pbSignature = NULL;
    pbSignature = malloc(cbSignature);
     
    nRet = DSignHash(hHash, Assymmetric_Key, 0, pbSignature, &cbSignature);
     
    if (nRet){
        printf("Falha na funcao: DSignHash \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
    printf("Buffer assinado.\n");
     
    nRet = DVerifySignature(hHash, pbSignature, cbSignature, Assymmetric_Key, 0);
     
    if (nRet){
        printf("Falha na funcao: DVerifySignature \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
    printf("Assinatura verificada com sucesso.\n");
    printf("==== Fim da assinatura e verificação com chave assimétrica====\n");

    // Importar e exportar chave assimétrica

    // Gerar cópia da chave assimétrica privada

    //Remove as chaves do HSM
    printf("==== Remoção da chave simétrica ====\n");
    nRet = DDestroyKey(&Symmetric_Key, REMOVE_FROM_HCM);
    if (nRet){
        printf("Falha na funcao: DDestroyKey \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Chave removida com sucesso.\n");
    printf("==== Fim da remoção da chave simétrica ====\n");

    printf("==== Remoção da chave assimétrica ====\n");
    nRet = DDestroyKey(&Assymmetric_Key, REMOVE_FROM_HCM);
    if (nRet){
        printf("Falha na funcao: DDestroyKey \nCodigo de erro: %d\n",nRet);
        goto clean;
    }
     
    printf("Chave removida com sucesso.\n");
    printf("==== Fim da remoção da chave simétrica ====\n");

    clean: 
    if (pbSignature)
        free(pbSignature);

    if (Assymmetric_Key){
        DDestroyKey(&Assymmetric_Key, 0);
        printf("Contexto da chave assimétrica liberado.\n");
    }
     
    if (Symmetric_Key){
        DDestroyKey(&Symmetric_Key, 0);
        printf("Contexto da chave simétrica liberado.\n");
    }

    if (hSession){
        DCloseSession(&hSession, 0);
        printf("Sessao encerrada.\n");
    }
     
    DFinalize();
    printf("Bibliotecas finalizada.\n");
 
}