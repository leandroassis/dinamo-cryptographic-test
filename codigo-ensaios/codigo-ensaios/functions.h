#pragma once

#include "dinamo.h"

#define HOST_ADDR       "192.168.88.97"

// constantes de usuarios para os ensaios
#define MASTER_ID       "master"
#define USER1_ID	    "ensaios01"
#define USER2_ID		"ensaios02"
#define GENERAL_PWD     "12345678"

// constantes de extração de numeros aleatórios
#define SIZE_OF_RANDOM_FILE 200*1024*1024
#define BUFFER_SIZE         1024

// constante de geração de chaves
#define FLAGS       EXPORTABLE_KEY | NO_CRYPTO

#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

#define KEY_ID          "CHAVE_CVV"
#define KEY_VALUE       { 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10 }
#define KEY_TYPE        ALG_3DES_112

void CreateSampleUsers(HSESSIONCTX* session);

// extração de números aleatórios
void RandomGeneratorAnalysis(HSESSIONCTX* session, unsigned int buffer_length, unsigned long sample_amount, char* filename);

// abrir sessao em diferentes usuarios
void LogInHSM(HSESSIONCTX* session, char* password, char* ID, char* address);

// limpar sessoes
void clean(HSESSIONCTX* session);

void VerifySecretContentProtection(HSESSIONCTX* session);

void ExportPublicKey();

void ImportExportConformityCheck(HSESSIONCTX* session);

void CreateA3Like(HSESSIONCTX *session);

void CreateNonExportableSymmetricKey(HSESSIONCTX* session);

void CreateS3Like(HSESSIONCTX* session);