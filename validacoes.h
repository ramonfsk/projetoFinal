


void leValidaData(char *data, , int *dataValida, int tipoData){
	
}

//Objetivo	: Ler e validar opção do usuário.
//Parâmetros: Referência a três vetores de caracteres, sendo eles a opção desejada a as disponíveis.
//Retorno	: ***
void leValidaOpcao(char *msg, char *opcaoUsuario, char *opcoes){
	int contQtdChars, validaOpcoes;
	
	do{
		validaOpcoes = 1;
		fflush(stdin);
		printf(msg);
		scanf(" %c", opcaoUsuario);
		*opcaoUsuario = toupper(*opcaoUsuario);
		for(contQtdChars = 0; contQtdChars < strlen(opcoes); contQtdChars++){
			if(*opcaoUsuario == opcoes[contQtdChars]){
				validaOpcoes = 0;
				break;
			}
		}
		if(validaOpcoes == 1){
			printf("\n*** Opcao invalida! ***\n\n");
		}
	}while(validaOpcoes == 1);
}

//Objetivo	: Ler e validar uma string.
//Parâmetros: Referência a dois vetores de caracteres, a string a ser validada, o seu tamanho e o tipo de string(0 - Qualquer, 1 - Nome).
//Retorno	: ***
void leValidaString(char *msg, char *msgErro, char *string, int tipoString){
	int contQtdChars, contQtdEspacos, validaString;
	
	do{
		validaString = 1;
		contQtdEspacos = 0;
		fflush(stdin);
		printf(msg);
		if(tipoString == 0){
			scanf("%[^\n]s", string);
		}else{
			scanf("%[a-zA-Z ][^\n]s", string);
		}
		for(contQtdChars = 0; contQtdChars < (strlen(string)-1); contQtdChars++){
			if(string[contQtdChars] == ' '){
				contQtdEspacos++;
			}
		}
		if(contQtdEspacos == (strlen(string)-1)){
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
	do{
		fflush(stdin);
		printf(msg);
		scanf("%f", numero);
		if(*numero < vlrMin || *numero > vlrMax){
			printf(msgErro);
		}
	}while(*numero < vlrMin || *numero > vlrMax);
}

//Objetivo	: Ler a validar um número inteiro.
//Parâmetros: Referência a dois vetores de caracteres, o número e seus limites.
//Retorno	: ***
void leValidaInt(char *msg, char *msgErro, int *numero, int vlrMin, int vlrMax){
	do{
		fflush(stdin);
		printf(msg);
		scanf("%i", numero);
		if(*numero < vlrMin || *numero > vlrMax){
			printf(msgErro);
		}
	}while(*numero < vlrMin || *numero > vlrMax);
}
