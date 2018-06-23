//

/*void escolhePais(char *paisEscolhido){
	unsigned int contQtdLinhas;
	unsigned char caracter;
	FILE *arqvPaises;
	
	if((arqvPaises = fopen(ARQV_PAISES, "r")) == NULL){
		printf("\n*** Erro ao abrir arquivo paises! ***\n\n");
		return;
	}else{
		contQtdLinhas = 0;
		while(!feof(arqvPaises)){
			if(caracter == '\n'){
				contQtdLinhas++;
			}
		}
	}
	
}*/

//Objetivo	: Ler e validar uma data.
//Parâmetros: Referência a uma string de data, flag de validação e o tipo da data. (0 - DataNaascimento, 1 - Data Volta)
//Retonno	: ***
void leValidaData(char *msg, char *msgErro, char *data, int *dataValida, int tipoData){
	unsigned int dia, mes, ano, validaScanf;
	unsigned int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char tempData[4];
	//Lendo a data
	do{
		fflush(stdin);
		printf(msg);
		validaScanf = scanf("%i/%i/%i", &dia, &mes, &ano);
		if(validaScanf != 3){
			printf(msgErro);
		}
	}while(validaScanf != 3);
	//Validando data
	if(tipoData == 0){
		if(dia < 4 && mes < 6 && ano < 2017){
			*dataValida = 1;
			return;
		}else{
			if(ano % 400 == 0 || (ano % 100 !=0 && ano % 4 == 0)){
				diasMes[1] = 29;
			}
			if(mes < 13){
				if(dia < diasMes[mes]){
					*dataValida = 0;
				}
			}
		}
	}else{
		if(ano % 400 == 0 || (ano % 100 !=0 && ano % 4 == 0)){
			diasMes[1] = 29;
		}
		if(mes < 13){
			if(dia < diasMes[mes]){
				*dataValida = 0;
			}
		}
	}
	//Após validação, escreve a data na string
	if(*dataValida == 1){
		printf(msgErro);
		return;
	}else{
		itoa(dia, tempData, 10);
		strcat(data, tempData);
		strcat(data, "/");
		itoa(mes, tempData, 10);
		strcat(data, tempData);
		strcat(data, "/");
		itoa(ano, tempData, 10);
		strcat(data, tempData);
	}
}



//Objetivo	: Abrir ou criar um arquivo binário.
//Parâmetros: Referência a um ponteiro de arquivos.
//Retorno	: ***
void abreArqvBinario(FILE *arqv){
	if((arqv = fopen(ARQV_PILOTO, "rb")) == NULL){
		if((arqv = fopen(ARQV_PILOTO, "wb")) == NULL){
			printf("\n*** FALHA AO CRIAR ARQUIVO! ***\n\n");
			exit(1);
		}
	}else{
		if((arqv = fopen(ARQV_PILOTO, "a+b")) == NULL){
			printf("\n*** FALHA AO ABRIR ARQUIVO! ***\n\n");
			exit(1);
		}
	}
}

//Objetivo	: Ler e validar opção do usuário.
//Parâmetros: Referência a três vetores de caracteres, sendo eles a opção desejada a as disponíveis.
//Retorno	: ***
void leValidaOpcao(char *msg, char *opcaoUsuario, char *opcoes){
	unsigned int contQtdChars, validaOpcoes;
	
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
	unsigned int contQtdChars, contQtdEspacos, validaString, validaScanf;
	
	do{
		do{
			validaString = 1;
			contQtdEspacos = 0;
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
			scanf("%i", numero);
		}while(validaScanf != 1);
		if(*numero < vlrMin || *numero > vlrMax){
			printf(msgErro);
		}
	}while(*numero < vlrMin || *numero > vlrMax);
}
