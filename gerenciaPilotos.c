//Classe Piloto
#include "gerenciaPilotos.h"
#include "structs.h"
#include "validacoes.h"

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
		printf("Qtd. Pilotos: %i\n\n", *qtdPilotos);
		printf("[C] Cadastrar Piloto.\n");
		printf("[A] Alterar Piloto.\n");
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
	int contQtdPilotos, validaNumero, validaString, contQtdIds, tempIds[3], escolhaUsuario;
	char opcaoUsuario;
	FILE *arqvEquipes;
	tEquipe *pEquipes;
	tPiloto *pPilotos, tempPiloto;
	//Inicializa variáveis
	srand(time(NULL));
	arqvEquipes = NULL;
	pEquipes = NULL;
	pPilotos = NULL;
	//Aloca os dados em memoria
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
			selecionaIdRand(&tempPiloto.idPiloto);
			validaIdRepetido(pPilotos, qtdPilotos, tempPiloto.idPiloto, &validaNumero);
			if(validaNumero == 1){
				printf("\n*** O ID %i ja existe! ***\n\n", tempPiloto.idPiloto);
			}
		}while(validaNumero == 1);
		//Nome
		do{
			validaString = 0;
			leValidaString("Agora, informe o nome: ", MSG_ERRO, tempPiloto.nomePiloto, 1);
			validaNomePilotoRepetido(pPilotos, *qtdPilotos, tempPiloto.nomePiloto, &validaString);
		}while(validaString == 1);
		//Sigla
		//DataNascimento
		//Sexo
		leValidaOpcao("Qual o sexo do piloto[S/N]? ", &tempPiloto.sexoPiloto, "FM");
		//Pais
		selecionaPais(tempPiloto.paisOrigem);
	}while(opcaoUsuario == 'S');
}

//Objetivo	: Gerar três números aleatorios e selecionar um
//Parâmetros:
//Retorno	: ***
void selecionaIdRand(int *idEscolhido){
	int contQtdIds, tempIds[3], escolhaUsuario;
	
	srand(time(NULL));
	printf("+----+----+----+\n");
	for(contQtdIds = 0; contQtdIds < 3; contQtdIds++){
		tempIds[contQtdIds] = rand() % 101;
		printf("| %2i ", tempIds[contQtdIds]);
	}
	printf("|\n+----+----+----+\n");
	printf("| 01 | 02 | 03 | <- Escolha entre [1..3]");
	printf("\n+----+----+----+\n");
	leValidaInt("\nEscolha uma posicao acima para o ID do piloto: ", MSG_ERRO, &escolhaUsuario, 0, 101);
	
	*idEscolhido = tempIds[escolhaUsuario-1];
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

//Objetivo	: Validar se há uma string repetida.
//Parâmetros: 
void validaNomePilotoRepetido(tPiloto *pPilotos, int qtdPilotos, char *string, int *validaRepetido){
	int contQtd;
	
	for(contQtd = 0; contQtd < qtdPilotos; contQtd++){
		if(stricmp(string, pPilotos[contQtd].nomePiloto) == 0){
			*validaRepetido = 1;
			break;
		}
	}
}

void selecionaSigla(char *sigla){
	int qtdEquipes, contQtdEquipes, escolhaUsuario;
	FILE *arqvEquipes;
	tEquipe *pEquipes, tempStruct;
	arqvEquipes = NULL;
	pEquipes = NULL;
	//Criar ou abrir arquivo existente
	if((arqvEquipes = fopen(ARQV_EQUIPES, "r")) == NULL){
		if((arqvEquipes = fopen(ARQV_EQUIPES, "wb+")) == NULL){
			printf("\n*** FALHA AO CRIAR O ARQUIVO! ***\n\n");
			fclose(arqvEquipes);
			getch();
			return;
		}
	}else{
		if((arqvEquipes = fopen(ARQV_EQUIPES, "rb+")) == NULL){
			printf("\n*** FALHA AO ABRIR O ARQUIVO! ***\n\n");
			fclose(arqvEquipes);
			getch();
			return;
		}
	}
	//Obtem quantidade de equipes cadastradas
	qtdEquipes = 0;
	fseek(arqvEquipes, 0, SEEK_SET);
	while(fread(&tempStruct, sizeof(tEquipe), 1, arqvEquipes) == 1){
		qtdEquipes++;
	}
	//
	printf("+----+-----+\n");
	for(contQtdEquipes = 0; contQtdEquipes < qtdEquipes; contQtdEquipes++){
		printf("| %i | %3s |\n", contQtdEquipes+1, pEquipes[contQtdEquipes].siglaEquipe);
	}
	printf("+----+-----+\n\n");
	leValidaInt("Escolha uma das siglas acima: ", MSG_ERRO, &escolhaUsuario, 1, contQtdEquipes+1);
	memcpy(sigla, (pEquipes+(escolhaUsuario-1))->siglaEquipe, sizeof((pEquipes+(escolhaUsuario-1))->siglaEquipe));
}
