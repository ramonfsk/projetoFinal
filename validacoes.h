#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leValidaOpcao(char *msg, char *opcaoUsuario, char *opcoes);
void leValidaSigla(char *msg, char *msgErro, char *sigla);
void leValidaString(char *msg, char *msgErro, char *string, int tipoString);
void leValidaFloat(char *msg, char *msgErro, float *numero, float vlrMin, float vlrMax);
void leValidaInt(char *msg, char *msgErro, int *numero, int vlrMin, int vlrMax);
