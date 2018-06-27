//Classe: Piloto

/* Struct */
typedef struct Piloto{
	int id;
	char nome[TAM_NOMECOMPLETO], sigla[TAM_SIGLA], paisOrigem[TAM_NOMEPAIS], dataNascimento[TAM_DATA];
	char sexo;
}tPiloto;

/* Protótipos das Funções & Procedimentos */
void validaNumRepetido(struct Piloto *pilotos, int qtdMax, int *validaRepetido);
void gerarIdsRand(int qtdIdsRand, int qtdMaxIds, int *idEscolhido);
void leValidaOpcao(char *msg, char *opcaoUsuario, char *opcoes);
void leValidaString(char *msg, char *msgErro, char *string, int tipoString);

// Cadastro de Pilotos
void cadastraPiloto(){
	int validaRepetido, validaData, qtdPilotos;
	char opcaoUsuario;
	
	tPiloto *pPilotos, tempPiloto;
	FILE *arqvPilotos;
	//Criando ou abrindo o arquivo
	if((arqvPilotos = fopen(ARQV_PILOTOS, "r")) == NULL){
		if((arqvPilotos = fopen(ARQV_PILOTOS, "wb")) == NULL){
			printf("\n*** FALHA AO CRIAR O ARQUIVO! ***\n\n");
			return;
		}else{
			rewind(arqvPilotos);
		}
	}else{
		if((arqvPilotos = fopen(ARQV_PILOTOS, "ab")) == NULL){
			printf("\n*** FALHA AO ABRIR O ARQUIVO! ***\n\n");
			return;
		}
	}
	//Obtem a quantidade de pilotos e aloca a memoria necessaria
	fseek(arqvPilotos, 0, SEEK_END);
	if((fread(&tempPiloto, sizeof(tPiloto), 1, arqvPilotos) == 1) != 1){
		qtdPilotos = 1;
	}else{
		while(fread(&tempPiloto, sizeof(tPiloto), 1, arqvPilotos) == 1){
			qtdPilotos++;
			if(qtdPilotos != 0){
				if((pPilotos = (tPiloto *) calloc(qtdPilotos, sizeof(tPiloto))) == NULL){
					printf("\n*** ERROR AO ALOCAR MEMORIA! ***\n\n");
					return;
				}
			}
		}		
	}

	printf("Alocado %i bytes | qtdpilotos: %i\n\n", qtdPilotos * sizeof(*pPilotos), qtdPilotos);
	getch();
	//Cadastrando pilotos
	do{
		system("cls");
		//Cadastro do ID
		do{
			validaRepetido = 0;
			gerarIdsRand(QTD_IDSRAND, MAX_IDSRAND, &pPilotos[qtdPilotos-1].id);
			validaNumRepetido(pPilotos, qtdPilotos, &validaRepetido);
			if(validaRepetido == 1){
				printf("\n*** O ID %i ja esta sendo utilizado! ***\n\n", pPilotos[qtdPilotos-1].id);
			}
		}while(validaRepetido == 1);
		//Cadastro do Nome
		leValidaString("Agora, insira o nome do piloto: ", MSG_ERRO, pPilotos[qtdPilotos-1].nome, 1);
		//Cadastro da Sigla
		//Cadastro da Data
		do{
			validaData = 1;
			leValidaData("Informe a data de nascimento[DD/MM/AAAA]: ", "\n*** Data invalida! ***\n\n", pPilotos[qtdPilotos-1].dataNascimento, &validaData, 0);
		}while(validaData == 1);
		//Cadastro do Sexo
		leValidaOpcao("Qual o sexo do piloto[M/F]? ", &pPilotos[qtdPilotos-1].sexo, "MF");
		//Cadastro do País
		leValidaOpcao("Deseja cadastrar mais um piloto[S/N]? ", &opcaoUsuario, "SN");
		if(opcaoUsuario == 'S'){
			//Incremento da quantidade de pilotos
			qtdPilotos++;
			//Realocando e memória
			if((pPilotos = (tPiloto *) realloc(pPilotos, qtdPilotos * sizeof(tPiloto))) == NULL){
				printf("\n*** FALHA AO REALOCAR MEMORIA! ***\n\n");
				return;			
			}
		}
	}while(opcaoUsuario == 'S');
	//Gravação no arquivo
	if((fwrite(p, sizeof(tPiloto), qtdPilotos, arqvPilotos)) == qtdPilotos){
		printf("\nGravando dados no arquivo.");
		sleep(1);
		printf(".");
		sleep(1);
		printf(".");
		sleep(2);
		printf("OK!");
	}else{
		printf("\n*** ERRO AO GRAVAR OS DADOS NO ARQUIVO! ***\n\n");
	}
	//Desalocando a memória
	free(pPilotos);
	//Fechando o arquivo
	fclose(arqvPilotos);
	//Atualização da quantidade de pilotos
}

// Alteração de Pilotos
void alteraPiloto(){

}


// Exclusão de Pilotos
void excluiPiloto(){
	
}

/* Funções & Procedimentos da Classe Piloto */

//Objetivo	: Validar um número repetido.
//Parâmetros: Referência a um ponteiro de struct Piloto, a tamanho do vetor e a variável de validação.
//Retorno	: ***
void validaNumRepetido(tPiloto *pilotos, int qtdMax, int *validaRepetido){
	int contQtdPilotos;
	
	for(contQtdPilotos = 0; contQtdPilotos < qtdMax; contQtdPilotos++){
		if(pilotos[qtdMax].id == pilotos[contQtdPilotos].id){
			*validaRepetido = 1;
			break;
		}		
	}
}

//Objetivo	:
//Parâmetros:
//Retorno	: ***
void gerarIdsRand(int qtdIdsRand, int qtdMaxIds, int *idEscolhido){
	int contQtdIds, contQtdChars, tempIds[qtdIdsRand], validaEscolha;
	char opcaoUsuario[3], opcoesId[qtdIdsRand][qtdIdsRand];
	
	srand(time(NULL));
	
	do{
		validaEscolha = 1;
		for(contQtdIds = 0; contQtdIds < qtdIdsRand; contQtdIds++){
			tempIds[contQtdIds] = rand() % qtdMaxIds;
			itoa(tempIds[contQtdIds], opcoesId[contQtdIds], 10);
			printf("| %i ", tempIds[contQtdIds]);
		}
		leValidaString("|\n\nEscolha um ID acima para o piloto: ", MSG_ERRO, opcaoUsuario, 0);
		for(contQtdIds = 0; contQtdIds < qtdIdsRand; contQtdIds++){
			if((strcmp(opcaoUsuario, opcoesId[contQtdIds])) == 0){
				validaEscolha = 0;
				break;
			}
		}
		if(validaEscolha == 1){
			printf("\n*** Opcao invalida! ***\n\n");
		}
	}while(validaEscolha == 1);
	
	*idEscolhido = atoi(opcaoUsuario);
}

//

void escolhePais(char *paisEscolhido){
	unsigned int contQtd, contQtdLinhas;
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
}

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
		if(ano > 1900){
			if(ano % 400 == 0 || (ano % 100 !=0 && ano % 4 == 0)){
				diasMes[1] = 29;
			}
			if(mes < 13){
				if(dia < diasMes[mes]){
					*dataValida = 0;
				}
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
