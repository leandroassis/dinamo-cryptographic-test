#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "dinamo.h"
#include "functions.h"

#pragma comment(lib, "tacndlib.lib")

int main(int argc, char *argv) {
    int nRet;
    struct AUTH_PWD authPwd;
    HSESSIONCTX hSession = NULL;

    //Inicializa as bibliotecas do Dinamo
    nRet = DInitialize(0);

    if (nRet) {
        printf("Falha na funcao: DInitialize \nCodigo de erro: %d\n", nRet);
        exit(1);
    }

    printf("Bibliotecas inicializadas.\n");

    // Inicia sessão no HSM
    LogInHSM(&hSession, GENERAL_PWD, MASTER_ID, HOST_ADDR);

    // Verifica se o HSM está operacional
    nRet = DAdmOperation(hSession, AO_KEEPALIVE, NULL, 0, 0);

    if (nRet) {
        printf("Falha na funcao: DAdmOperation \nCodigo de erro: %d\n", nRet);
        clean(&hSession);
    }
    printf("O Dinamo esta operacional.\n");
    
    // REQUISITO III.7.1 e REQUISITO III.7.2
    VerifySecretContentProtection(&hSession);

    // REQUISITO III.7.6
    RandomGeneratorAnalysis(&hSession, BUFFER_SIZE, SIZE_OF_RANDOM_FILE, "dinamo_XP");

    // REQUISITO III.7.16
    ImportExportConformityCheck(&hSession);

    printf("\n-------- Teste de atributos de exportacao das chaves --------\n");
    // REQUISITO III.7.21
    CreateA3Like(&hSession);

    // REQUISITO III.7.22.1
    CreateNonExportableSymmetricKey(&hSession);

    // REQUISITO III.7.22.2
    CreateS3Like(&hSession);
    printf("\n-------- Fim do teste de atributos de exportacao das chaves --------\n");
    
    // REQUISITO III.7.23
    ExportPublicKey();

    clean(&hSession);
    return 0;
}