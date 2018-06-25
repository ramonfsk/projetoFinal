#include "validacoes.h"

//Objetivo	: Ler e validar opção do usuário.
//Parâmetros: Referência a três vetores de caracteres, sendo eles a opção desejada a as disponíveis.
//Retorno	: ***
void leValidaOpcao(char *msg, char *opcaoUsuario, char *opcoes){
	unsigned int contQtdChars, validaOpcoes, validaScanf;
	
	do{
		do{
			validaOpcoes = 1;
			validaScanf = 1;
			fflush(stdin);
			printf(msg);
			validaScanf = scanf(" %c", opcaoUsuario);
			if(validaScanf != 1){
				printf("\n\n*** Leitura invalida! ***\n");
			}
		}while(validaScanf != 1);
		*opcaoUsuario = toupper(*opcaoUsuario);
		for(contQtdChars = 0; contQtdChars < strlen(opcoes); contQtdChars++){
			if(*opcaoUsuario == opcoes[contQtdChars]){
				validaOpcoes = 0;
				break;
			}
		}
	}while(validaOpcoes == 1);
}
//Objetivo	: Ler e validar uma sigla com três caracteres maíusculos.
//Parâmetros: Mensagem de apresentação, mensagem de erro e ponteiro para sigla.
//Retorno	: ***
void leValidaSigla(char *msg, char *msgErro, char *sigla){
	unsigned int contQtdChars, contQtdEspacos, validaScanf, validaSigla;
	
	do{
		validaSigla = 1;
		contQtdEspacos = 0;
		do{
			fflush(stdin);
			printf(msg);
			validaScanf = scanf("%[A-Z][^\n]s", sigla);
			if(validaScanf != 1){
				printf(msgErro);
			}
		}while(validaScanf != 1);
		*sigla = toupper(*sigla);
		if(strlen(sigla) > 3){
			printf(msgErro);
		}else{
			for(contQtdChars = 0; contQtdChars < (strlen(sigla)-1); contQtdChars++){
				if(sigla[contQtdChars] == ' '){
					contQtdEspacos++;
				}
			}
			if(contQtdEspacos == (strlen(sigla))){
				printf("\n\n*** Sigla em branco! ***\n");
			}else{
				validaSigla = 0;
			}			
		}
	}while(validaSigla == 1);
}

//Objetivo	: Ler e validar uma string.
//Parâmetros: Referência a dois vetores de caracteres, a string a ser validada, o seu tamanho e o tipo de string(0 - Qualquer, 1 - Nome).
//Retorno	: ***
void leValidaString(char *msg, char *msgErro, char *string, int tipoString){
	unsigned int contQtdChars, contQtdEspacos, validaString, validaScanf;
	
	do{
		validaString = 1;
		contQtdEspacos = 0;
		do{
			fflush(stdin);
			printf(msg);
			if(tipoString == 0){
				validaScanf = scanf("%[^\n]s", string);
			}else{
				validaScanf = scanf("%[a-zA-Z ][^\n]s", string);
			}
		}while(validaScanf != 1);

		for(contQtdChars = 0; contQtdChars < (strlen(string)-1); contQtdChars++){
			if(string[contQtdChars] == ' '){
				contQtdEspacos++;
			}
		}
		if(contQtdEspacos == (strlen(string))){
			printf("\n\n*** String em branco! ***\n");
		}else{
			validaString = 0;
		}
	}while(validaString == 1);
}

//Objetivo	: Ler a validar um número real.
//Parâmetros: Referência a dois vetores de caracteres, o número e seus limites.
//Retorno	: ***
void leValidaFloat(char *msg, char *msgErro, float *numero, float vlrMin, float vlrMax){
	unsigned int validaScanf;
	
	do{
		do{
			fflush(stdin);
			printf(msg);
			validaScanf = scanf("%f", numero);
		}while(validaScanf != 1);
		if(*numero < vlrMin || *numero > vlrMax){
			printf(msgErro);
		}
	}while(*numero < vlrMin || *numero > vlrMax);
}

//Objetivo	: Ler a validar um número inteiro.
//Parâmetros: Referência a dois vetores de caracteres, o número e seus limites.
//Retorno	: ***
void leValidaInt(char *msg, char *msgErro, int *numero, int vlrMin, int vlrMax){
	unsigned int validaScanf;
	
	do{
		do{
			fflush(stdin);
			printf(msg);
			validaScanf = scanf("%i", numero);
		}while(validaScanf != 1);
		if(*numero < vlrMin || *numero > vlrMax){
			printf(msgErro);
		}
	}while(*numero < vlrMin || *numero > vlrMax);
}
