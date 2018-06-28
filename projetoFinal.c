// Aluno	: Ramon Ferreira
// Matrícula: UC14100797

/*
SINTESE
Objetivo: 
Entrada	: 
Saída	: 
*/

/* Biliotecas */
#include "validacoes.h"
#include "structs.h"
#include "gerenciaEquipes.h"
#include "gerenciaPilotos.h"
#include "gerenciaCircuitos.h"
#include "gerenciaMelhoresVoltas.h"

/* Protótipos das Funções & Procedimentos */
void obterQtdEquipes(FILE *arqvEquipes, int *qtdEquipes);
void obterQtdPilotos(FILE *arqvPilotos, int *qtdPilotos);
void obterQtdCircuitos(FILE *arqvCircuitos, int *qtdCircuitos);
void obterQtdMelhoresVoltas(FILE *arqvMelhoresVoltas, int *qtdMelhoresVoltas);

int main(){
//Declarações
	FILE *arqvEquipes, *arqvPilotos, *arqvCircuitos, *arqvMelhoresVoltas;
	int validaInteracao, qtdEquipes, qtdPilotos, qtdCircuitos, qtdMelhoresVoltas;
	char opcaoUsuario;
//Inicializações
	arqvEquipes = NULL;
	arqvPilotos = NULL;
	arqvCircuitos = NULL;
	arqvMelhoresVoltas = NULL;
	qtdEquipes = 0;
	qtdPilotos = 0;
	qtdCircuitos = 0;
	qtdMelhoresVoltas = 0;
//Instruções
	//Obter quatidade de informações nos arquivos
	obterQtdEquipes(arqvEquipes, &qtdEquipes);
	obterQtdPilotos(arqvPilotos, &qtdPilotos);
	obterQtdCircuitos(arqvCircuitos, &qtdCircuitos);
	obterQtdMelhoresVoltas(arqvMelhoresVoltas, &qtdMelhoresVoltas);
//Apresentar menus
	do{
		validaInteracao = 1;
		opcaoUsuario = '\0';
		system("cls");
		printf("*** MOTOGP 2018 ***\n");
		printf("-------------------\n\n");
		printf("[C] Realizar gerenciamento de dados.\n");
		printf("[R] Consultar os dados cadastrados.\n");
		printf("[S] Exibir ultimo relatorio sintetico.\n");
		printf("[X] Encerrar do programa...\n\n");
		leValidaOpcao("Qual opcao deseja[C/R/S/X]? ", &opcaoUsuario , "CRSX");
		switch(opcaoUsuario){
			case 'C':
				do{
					validaInteracao = 1;
					opcaoUsuario = '\0';
					system("cls");
					printf("*** GERENCIAMENTO MOTOGP 2018 ***\n");
					printf("---------------------------------\n\n");
					printf("[E] Equipes.\n");
					printf("[P] Pilotos.\n");
					printf("[C] Circuitos.\n");
					printf("[M] Melhores Voltas.\n");
					printf("[X] Voltar ao menu anterior...\n\n");
					leValidaOpcao("Qual opcao deseja[P/E/C/M/X]? ", &opcaoUsuario , "EPCMX");
					switch(opcaoUsuario){
						case 'E':
							validaInteracao = 1;
							opcaoUsuario = '\0';
							menuEquipeCRUD(&opcaoUsuario, &validaInteracao, &qtdEquipes);
							validaInteracao = 1; // Gambiarra
							break;
						case 'P':
							if(qtdEquipes == 0){
								printf("\n*** Nao ha equipes cadastradas! \n\n***");
								getch();
							}else{
								validaInteracao = 1;
								opcaoUsuario = '\0';
								menuPilotoCRUD(&opcaoUsuario, &validaInteracao, &qtdPilotos);	
							}
							validaInteracao = 1; // Gambiarra
							break;
						case 'C':
							if(qtdPilotos == 0){
								printf("\n*** Nao ha pilotos cadastrados! \n\n***");
								getch();								
							}else{
								validaInteracao = 1;
								opcaoUsuario = '\0';
								//menuCircuitoCRUD();								
							}
							validaInteracao = 1; // Gambiarra
							break;
						case 'M':
							if(qtdCircuitos){
								printf("\n*** Nao ha circuitos cadastrados! \n\n***");
								getch();		
							}else{
								validaInteracao = 1;
								opcaoUsuario = '\0';
								//menuMelhorVoltaCRUD();								
							}
							validaInteracao = 1; // Gambiarra
							break;
						default:
							validaInteracao = 0;
					}
				}while(validaInteracao == 1);
				validaInteracao = 1; // Gambiarra
				break;
			case 'R':
				do{
					validaInteracao = 1;
					opcaoUsuario = '\0';
					system("cls");
					printf("*** RELATORIOS SINTETICOS MOTOGP 2018 ***\n");
					printf("-----------------------------------------\n\n");
					printf("[1] Pesquisar um registro especifico em um dos arquivos pelo ID.\n");
					printf("[2] Pesquisar pilotos pelo nome.\n");
					printf("[3] Relacionar os pilotos que realizaram voltas em um circuito por data.\n");
					printf("[4] Pesquisar todos os circuitos cadastrados pelo nome.\n");
					printf("[5] Apresentar todos os pilotos de uma equipe por periodo.\n");
					printf("[6] Pesquisar todos os dados por tempo de volta igual ou menor fornecido.\n");
					printf("[7] Apresentar pilotos, equipes ou circuitos sem melhor volta realizada.\n");
					printf("[8] Pesquisar todos os dados dos circuitos pelo nome.\n");
					printf("[9] Pesquiar informacoes completas de um piloto.\n");
					printf("[X] Voltar ao menu anterior...\n\n");
					leValidaOpcao("Qual opcao deseja[1...9/X]? ", &opcaoUsuario ,"123456789X");
					switch(opcaoUsuario){
						case '1':
							break;
						case '2':
							break;
						case '3':
							break;
						case '4':
							break;
						case '5':
							break;
						case '6':
							break;
						case '7':
							break;
						case '8':
							break;
						case '9':
							break;
						default:
							validaInteracao = 0;
					}			
				}while(validaInteracao == 1);
				validaInteracao = 1; // Gambiarra
				break;
			case 'S':
				//exibirRelatorioSintetico();
				break;
			default:
				validaInteracao = 0;
		}
		}while(validaInteracao == 1);
	return 0;
}

void obterQtdEquipes(FILE *arqvEquipes, int *qtdEquipes){
	tEquipe tempStruct;
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
	//Obter a quantidade de equipes já cadastradas no arquivo
	*qtdEquipes = 0;
	fseek(arqvEquipes, 0, SEEK_SET);
	while(fread(&tempStruct, sizeof(tEquipe), 1, arqvEquipes) == 1){
		(*qtdEquipes)++;
	}
	fclose(arqvEquipes);
}

void obterQtdPilotos(FILE *arqvPilotos, int *qtdPilotos){
	tPiloto tempStruct;
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
	fclose(arqvPilotos);
}

void obterQtdCircuitos(FILE *arqvCircuitos, int *qtdCircuitos){
	tCircuito tempStruct;
	//Criar ou abrir arquivo existente
	if((arqvCircuitos = fopen(ARQV_CIRCUITOS, "r")) == NULL){
		if((arqvCircuitos = fopen(ARQV_CIRCUITOS, "wb+")) == NULL){
			printf("\n*** FALHA AO CRIAR O ARQUIVO! ***\n\n");
			fclose(arqvCircuitos);
			getch();
			return;
		}
	}else{
		if((arqvCircuitos = fopen(ARQV_CIRCUITOS, "rb+")) == NULL){
			printf("\n*** FALHA AO ABRIR O ARQUIVO! ***\n\n");
			fclose(arqvCircuitos);
			getch();
			return;
		}
	}
	//Obter a quantidade de equipes já cadastradas no arquivo
	*qtdCircuitos = 0;
	fseek(arqvCircuitos, 0, SEEK_SET);
	while(fread(&tempStruct, sizeof(tCircuito), 1, arqvCircuitos) == 1){
		(*qtdCircuitos)++;
	}
	fclose(arqvCircuitos);
}

void obterQtdMelhoresVoltas(FILE *arqvMelhoresVoltas, int *qtdMelhoresVoltas){
	tMelhorVolta tempStruct;
	//Criar ou abrir arquivo existente
	if((arqvMelhoresVoltas = fopen(ARQV_MELHORESVOLTAS, "r")) == NULL){
		if((arqvMelhoresVoltas = fopen(ARQV_MELHORESVOLTAS, "wb+")) == NULL){
			printf("\n*** FALHA AO CRIAR O ARQUIVO! ***\n\n");
			fclose(arqvMelhoresVoltas);
			getch();
			return;
		}
	}else{
		if((arqvMelhoresVoltas = fopen(ARQV_MELHORESVOLTAS, "rb+")) == NULL){
			printf("\n*** FALHA AO ABRIR O ARQUIVO! ***\n\n");
			fclose(arqvMelhoresVoltas);
			getch();
			return;
		}
	}
	//Obter a quantidade de equipes já cadastradas no arquivo
	*qtdMelhoresVoltas = 0;
	fseek(arqvMelhoresVoltas, 0, SEEK_SET);
	while(fread(&tempStruct, sizeof(tMelhorVolta), 1, arqvMelhoresVoltas) == 1){
		(*qtdMelhoresVoltas)++;
	}
	fclose(arqvMelhoresVoltas);
}
