//Classe Piloto
#include "gerenciaPilotos.h"
#include "structs.h"
#include "validacoes.h"
#include "funcoes.h"

//Objetivo	: Exibir o menu CRUD da classe equipe.
//Parâmetros:
//Retorno	: ***
void menuPilotoCRUD(char *opcaoUsuario, int *validaInteracao, int *qtdPilotos){
	tPiloto tempStruct;
	FILE *arqvPilotos;
	arqvPilotos = NULL;
	
	do{
		//Criar ou abrir arquivo existente
		if((arqvPilotos = fopen(ARQV_PILOTOS, "r")) == NULL){
			if((arqvPilotos = fopen(ARQV_PILOTOS, "wb+")) == NULL){
				printf("\n*** FALHA AO CRIAR O ARQUIVO! ***\n\n");
				fclose(arqvPilotos);
				getch();
				return;
			}
		}else{
			if((arqvPilotos = fopen(ARQV_PILOTOS, "rb+")) == NULL){
				printf("\n*** FALHA AO ABRIR O ARQUIVO! ***\n\n");
				fclose(arqvPilotos);
				getch();
				return;
			}
		}
		//Obter a quantidade de equipes já cadastradas no arquivo
		*qtdPilotos = 0;
		fseek(arqvPilotos, 0, SEEK_SET);
		while(fread(&tempStruct, sizeof(tPiloto), 1, arqvPilotos) == 1){
			(*qtdPilotos)++;
		}
		system("cls");
		printf("*** GERENCIAMENTO DE PILOTOS ***\n");
		printf("--------------------------------\n\n");
		printf("[C] Cadastrar Piloto.\n");
		printf("[A] Alterar Piloto.");
		printf("[E] Excluir Piloto.\n");
		printf("[X] Voltar ao menu anterior...\n\n");
		leValidaOpcao("Qual opcao deseja[C/A/E/X]? ", opcaoUsuario, "CAEX");
		switch(*opcaoUsuario){
			case 'C':
				cadastraPiloto(arqvPilotos, qtdPilotos);
				break;
			case 'A':
				//alteraPiloto();
				break;
			case 'E':
				//excluiPiloto();
				break;
			default:
				*validaInteracao = 0;
		}
	}while(*validaInteracao == 1);
}

void cadastraPiloto(FILE *arqvPilotos, int *qtdPilotos){
	int contQtdPilotos, validaNumero, validaString;
	char opcaoUsuario;
	FILE *arqvEquipes;
	tEquipe *pEquipes;
	tPiloto *pPilotos, tempPiloto;
	//Inicializa variáveis
	arqvEquipes = NULL;
	pEquipes = NULL;
	pPilotos = NULL;
	if(*qtdPilotos == 0){
		if((pPilotos = (tPiloto*) calloc(1, sizeof(tPiloto))) == NULL){
			printf("\n*** FALHA AO ALOCAR MEMORIA! ***\n\n");
			exit(EXIT_FAILURE);
		}
	}else{
		if((pPilotos = (tPiloto*) calloc(*qtdPilotos, sizeof(tPiloto))) == NULL){
			printf("\n*** FALHA AO ALOCAR MEMORIA! ***\n\n");
			exit(EXIT_FAILURE);
		}else{
			//Aloca os dados em memoria
			fseek(arqvPilotos, 0, SEEK_SET);
			contQtdPilotos = 0;
			while(fread((pPilotos+contQtdPilotos), sizeof(tPiloto), 1, arqvPilotos) == 1){
				contQtdPilotos++;
			}
		}
	}
	//Cadastra novo Piloto
	do{
		system("cls");
		printf("*** CADASTRO DE PILOTOS ***\n");
		printf("---------------------------\n\n");
		//ID
		do{
			validaNumero = 0;
			selecionaIdRand(QTD_IDSRAND, MAX_IDSRAND, &tempPiloto.idPiloto);
			validaIdRepetido(pPilotos, *qtdPilotos, tempPiloto.idPiloto, &validaNumero);
			if(validaNumero == 1){
				printf("\n*** O ID %i ja existe! ***\n\n", tempPiloto.idPiloto);
			}
		}while(validaNumero == 1);
		//Nome
		//Sigla
		//DataNascimento
		//Sexo
		//Pais
	}while(opcaoUsuario == 'S');
}




//Objetivo	: Gerar três números aleatorios e selecionar um
//Parâmetros:
//Retorno	: ***
void selecionaIdRand(int qtdIdsRand, int qtdMaxIds, int *idEscolhido){
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

//Objetivo	: Validar se há um número repetido.
//Parâmetros:
//Retorno	: ***
void validaIdRepetido(tPiloto *pPilotos, int *qtdPilotos, int numero, int *validaRepetido){
	int contQtd;
	
	for(contQtd = 0; contQtd < *qtdPilotos; contQtd++){
		if(numero == pPilotos[contQtd].idPiloto){
			*validaRepetido = 1;
			break;
		}
	}
}
