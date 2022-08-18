#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "dinamo.h"

#pragma comment(lib, "tacndlib.lib")

#define HOST_ADDR       "192.168.88.97"
#define USER_ID         "master"
#define USER_PWD        "12345678"



void main()
{
    int nRet;
    struct AUTH_PWD authPwd;
    HSESSIONCTX hSession = NULL;
    BYTE randomNumberBuffer[BUFFER_SIZE] = {0};
    FILE *arquivo_bytes;

    //Inicializa as bibliotecas do Dinamo
    nRet = DInitialize(0);

    if (nRet) {
        printf("Falha na funcao: DInitialize \nCodigo de erro: %d\n", nRet);
        exit(1);
    }

    printf("Bibliotecas inicializadas.\n");

    strncpy(authPwd.szAddr, HOST_ADDR, sizeof(authPwd.szAddr));
    authPwd.nPort = DEFAULT_PORT;
    strncpy(authPwd.szUserId, USER_ID, sizeof(authPwd.szUserId));
    strncpy(authPwd.szPassword, USER_PWD, sizeof(authPwd.szPassword));

    nRet = DOpenSession(&hSession, SS_USER_PWD, (BYTE*)&authPwd, sizeof(authPwd), ENCRYPTED_CONN);

    if (nRet) {
        printf("Falha na funcao: DOpenSession \nCodigo de erro: %d\n", nRet);
        goto clean;
    }

    printf("Sessao com o Dinamo estabelecida.\n");

    nRet = DAdmOperation(hSession, AO_KEEPALIVE, NULL, 0, 0);

    if (nRet) {
        printf("Falha na funcao: DAdmOperation \nCodigo de erro: %d\n", nRet);
        goto clean;
    }

    printf("O Dinamo esta operacional.\n");

    

clean:

    if (hSession) {
        DCloseSession(&hSession, 0);
        printf("Sessao encerrada.\n");
    }

    DFinalize();
    printf("Bibliotecas finalizada.\n");
}
