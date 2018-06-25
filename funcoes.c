#include "funcoes.h"

void abreArqvBinario(FILE *arqv, char *nomeArqv){
	if((arqv = fopen(nomeArqv, "r")) == NULL){
		if((arqv = fopen(nomeArqv, "wb+")) == NULL){
			printf("\n*** FALHA AO CRIAR O ARQUIVO! ***\n\n");
			getch();
			return;
		}
	}else{
		if((arqv = fopen(nomeArqv, "rb+")) == NULL){
			printf("\n*** FALHA AO ABRIR O ARQUIVO! ***\n\n");
			getch();
			return;
		}
	}
}
