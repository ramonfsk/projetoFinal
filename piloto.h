//Classe: Piloto

/* Struct */
struct Piloto{
	int id;
	char nome[TAM_NOMECOMPLETO], sigla[TAM_SIGLA], paisOrigem[TAM_NOMEPAIS], dataNascimento[TAM_DATA];
	char sexo;
};

/* Métodos */

// Cadastro de Pilotos
void cadastraPiloto(struct Piloto *pilotos, int *qtdPilotos){
	int contQtdPilotos, validaRepetido, validaData, tempId[3];
	char opcaoUsuario, tempIdChars[3], opcoesId[9];
	FILE *arqvPiloto;

	contQtdPilotos = *qtdPilotos;
	
	//Criando ou abrindo o arquivo
	if((arqvPiloto = fopen(ARQV_PILOTO, "r")) == NULL){
		if((arqvPiloto = fopen(ARQV_PILOTO, "a+b")) == NULL){
			printf("\n*** FALHA AO CRIAR ARQUIVO! ***\n\n");
			return;
		}
	}else{
		if((arqvPiloto = fopen(ARQV_PILOTO, "ab")) == NULL){
			printf("\n*** FALHA AO ABRIR ARQUIVO! ***\n\n");
			return;
		}
	}
	//Cadastrando pilotos
	do{
		//Alocando e realocando memória
		if(contQtdPilotos == 0){
			pilotos = (struct Piloto *) malloc(sizeof(struct Piloto));
		}else{
			pilotos = (struct Piloto *) realloc(pilotos, (contQtdPilotos+1) * sizeof(struct Piloto));
		}
		system("cls");
		printf("Alocado %i bytes.\n\n", contQtdPilotos * sizeof(*pilotos));
		//Cadastro do ID
		do{
			validaRepetido = 0;
			gerarIdsRand(QTD_IDSRAND, MAX_IDSRAND, &pilotos[contQtdPilotos].id);
			validaNumRepetido(pilotos, contQtdPilotos, &validaRepetido);
			if(validaRepetido == 1){
				printf("\n*** O ID %i ja esta sendo utilizado! ***\n\n", pilotos[contQtdPilotos].id);
			}
		}while(validaRepetido == 1);
		//Cadastro do Nome
		leValidaString("Agora, insira o nome do piloto: ", MSG_ERRO, pilotos[contQtdPilotos].nome, 1);
		//Cadastro da Data
		/*do{
			validaData = 1;
			leValidaData(pilotos[contQtdPilotos].dataNascimento, &validaData, 1);
			printf("\ndataformatada: %s\n", pilotos[contQtdPilotos].dataNascimento.dataFormatada);
			if(validaData == 1){
				printf("\n*** Data invalida! ***\n\n");
			}
		}while(validaData == 1);*/
		//Cadastro do Sexo
		//Cadastro do País
		//Gravação no arquivo
		contQtdPilotos++;
		leValidaOpcao("Deseja cadastrar mais um piloto[S/N]? ", &opcaoUsuario, "SN");
	}while(opcaoUsuario == 'S');
	//Desalocando a memória
	free(pilotos);
	//Fechando o arquivo
	fclose(arqvPiloto);
	//Atualização da quantidade de pilotos
	*qtdPilotos += contQtdPilotos;
}

// Alteração de Pilotos
void alteraPiloto(struct Piloto *pilotos, int *qtdPilotos){

}


// Exclusão de Pilotos
void excluiPiloto(struct Piloto *pilotos, int *qtdPilotos){
	
}

/* Validações da Classe Piloto */

//Objetivo	: Validar um número repetido.
//Parâmetros: Referência a um ponteiro de struct Piloto, a tamanho do vetor e a variável de validação.
//Retorno	: ***
void validaNumRepetido(struct Piloto *pilotos, int qtdMax, int *validaRepetido){
	int contQtdPilotos;
	
	for(contQtdPilotos = 0; contQtdPilotos < qtdMax; contQtdPilotos++){
		if(pilotos[qtdMax].id == pilotos[contQtdPilotos].id){
			*validaRepetido = 1;
			break;
		}		
	}
}

void gerarIdsRand(int qtdIdsRand, int qtdMaxIds, int *idEscolhido){
	int contQtdIds, contQtdChars, tempIds[qtdIdsRand], validaEscolha;
	char opcaoUsuario[3], opcoesId[qtdIdsRand][qtdIdsRand];
	
	srand(time(NULL));
	
	do{
		validaEscolha = 1;
		printf("| ID |");
		for(contQtdIds = 0; contQtdIds < qtdIdsRand; contQtdIds++){
			tempIds[contQtdIds] = rand() % qtdMaxIds;
			itoa(tempIds[contQtdIds], opcoesId[contQtdIds], 10);
			printf(" %i |", tempIds[contQtdIds]);
		}
		leValidaString("\n\nEscolha um ID acima para o piloto: ", MSG_ERRO, opcaoUsuario, 0);
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
