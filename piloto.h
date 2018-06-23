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
	struct Piloto *swapPiloto;
	int validaRepetido, validaData;
	char opcaoUsuario;
	FILE *arqvPiloto;
	
	//Criando ou abrindo o arquivo
	abreArqvBinario(arqvPiloto);
	//Alocacao de memoria
	alocaStructPiloto(pilotos);
	//Cadastrando pilotos
	do{
		system("cls");
		printf("Qtd. Pilotos: %i | Alocado %i bytes\n\n", *qtdPilotos, sizeof(*pilotos));
		//Cadastro do ID
		do{
			validaRepetido = 0;
			gerarIdsRand(QTD_IDSRAND, MAX_IDSRAND, &pilotos[(*qtdPilotos)-1].id);
			validaNumRepetido(pilotos, *qtdPilotos, &validaRepetido);
			if(validaRepetido == 1){
				printf("\n*** O ID %i ja esta sendo utilizado! ***\n\n", pilotos[(*qtdPilotos)-1].id);
			}
		}while(validaRepetido == 1);
		//Cadastro do Nome
		leValidaString("Agora, insira o nome do piloto: ", MSG_ERRO, pilotos[(*qtdPilotos)-1].nome, 1);
		//Cadastro da Data
		do{
			validaData = 1;
			leValidaData("Informe a data de nascimento[DD/MM/AAAA]: ", "\n*** Data invalida! ***\n\n", pilotos[(*qtdPilotos-1)].dataNascimento, &validaData, 0);
		}while(validaData == 1);
		//Cadastro do Sexo
		leValidaOpcao("Qual o sexo do piloto[M/F]? ", &pilotos[(*qtdPilotos)-1].sexo, "MF");
		//Cadastro do País
		//abreLeArqvPaises(pilotos[(*qtdPilotos)-1].paisOrigem);
		leValidaOpcao("Deseja cadastrar mais um piloto[S/N]? ", &opcaoUsuario, "SN");
		if(opcaoUsuario == 'S'){
			//Incremento da quantidade de pilotos
			(*qtdPilotos)++;
			//Realocando e memória
			if((swapPiloto = (struct Piloto *) realloc(pilotos, (*qtdPilotos) * sizeof(struct Piloto))) == NULL){
				printf("\n*** FALHA AO ALOCAR MEMORIA! ***\n\n");
				exit(1);			
			}else{
				pilotos = swapPiloto;
				free(swapPiloto);
			}
		}
	}while(opcaoUsuario == 'S');
	//Gravação no arquivo
	//Desalocando a memória
	free(pilotos);
	//Fechando o arquivo
	fclose(arqvPiloto);
	//Atualização da quantidade de pilotos
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

//Objetivo	:
//Parâmetros:
//Retorno	: ***
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

//Objetivo	: 
//Parâmetros: 
//Retorno	: ***
void alocaStructPiloto(struct Piloto *pilotos){
	if((pilotos = (struct Piloto *) malloc(sizeof(struct Piloto))) == NULL){
		printf("\n*** FALHA AO ALOCAR MEMORIA! ***\n\n");
		exit(1);
	}
}
