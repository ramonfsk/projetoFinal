// Aluno	: Ramon Ferreira
// Matrícula: UC14100797

/*
SINTESE
Objetivo: 
Entrada	: 
Saída	: 
*/

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* MACROS */
#define ARQV_PILOTO "piloto.dat"
#define ARQV_PAISES "paises.txt"
#define MAX_MELHORESVOLTAS 10
#define TAM_NOMEPAIS 30
#define TAM_NOMECOMPLETO 30
#define TAM_SIGLA 3
#define TAM_NOMEEQUIPE 30
#define TAM_NOMECIRCUITO 20
#define TAM_DATA 10
#define TAM_TEMPO 13
#define QTD_IDSRAND 3
#define MAX_IDSRAND 100
#define MSG_ERRO "\n*** ENTRADA INVALIDA! ***\n\n"

/* Classes */
#include "validacoes.h"
#include "piloto.h"
#include "equipe.h"
#include "circuito.h"
#include "melhoresVoltas.h"

/* Protótipo das Funções & Procedimentos */
void menuPilotoCRUD(struct Piloto *pilotos, char *opcaoUsuario, int *validaInteracao, int *qtdPilotos);
void menuEquipeCRUD(struct Equipe *equipes, char *opcaoUsuario, int *validaInteracao, int *qtdEquipes);
void menuCircuitoCRUD(struct Circuito *circuitos, char *opcaoUsuario, int *validaInteracao, int *qtdCircuitos);
void menuMelhorVoltaCRUD(struct MelhorVolta *melhoresVoltas, char *opcaoUsuario, int *validaInteracao, int *qtdMelhoresVoltas);

int main(){
// Declarações
	struct Piloto *pilotos;
	struct Equipe *equipes;
	struct Circuito *circuitos;
	struct MelhorVolta *melhoresVoltas;
	int contQtdPilotos, contQtdEquipes, contQtdCircuitos, contQtdMelhoresVoltas, validaInteracao;
	char opcaoUsuario;
// Inicializações
	contQtdPilotos = 1;
	contQtdEquipes = 1;
	contQtdCircuitos = 1;
	contQtdMelhoresVoltas = 1;
// Instruções
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
		leValidaOpcao("Qual opcao deseja[C/R/S/X]? ", &opcaoUsuario ,"CRSX");
		switch(opcaoUsuario){
			case 'C':
				do{
					validaInteracao = 1;
					opcaoUsuario = '\0';
					system("cls");
					printf("*** GERENCIAMENTO MOTOGP 2018 ***\n");
					printf("---------------------------------\n\n");
					printf("[P] Pilotos.\n");
					printf("[E] Equipes.\n");
					printf("[C] Circuitos.\n");
					printf("[M] Melhores Voltas.\n");
					printf("[X] Voltar ao menu anterior...\n\n");
					leValidaOpcao("Qual opcao deseja[P/E/C/M/X]? ", &opcaoUsuario ,"PECMX");
					switch(opcaoUsuario){
						case 'P':
							validaInteracao = 1;
							opcaoUsuario = '\0';
							menuPilotoCRUD(&pilotos, &opcaoUsuario, &validaInteracao, &contQtdPilotos);
							validaInteracao = 1; // Gambiarra
							break;
						case 'E':
							validaInteracao = 1;
							opcaoUsuario = '\0';
							menuEquipeCRUD(&equipes, &opcaoUsuario, &validaInteracao, &contQtdEquipes);
							validaInteracao = 1; // Gambiarra
							break;
						case 'C':
							validaInteracao = 1;
							opcaoUsuario = '\0';
							menuCircuitoCRUD(&circuitos, &opcaoUsuario, &validaInteracao, &contQtdCircuitos);
							validaInteracao = 1; // Gambiarra
							break;
						case 'M':
							validaInteracao = 1;
							opcaoUsuario = '\0';
							menuMelhorVoltaCRUD(&melhoresVoltas ,&opcaoUsuario, &validaInteracao, &contQtdMelhoresVoltas);
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

/* Funções & Procedimentos */

//Objetivo	: Exibir o menu CRUD da classe piloto.
//Parâmetros:
//Retorno	: ***
void menuPilotoCRUD(struct Piloto *pilotos, char *opcaoUsuario, int *validaInteracao, int *qtdPilotos){
	do{
		system("cls");
		printf("*** GERENCIAMENTO DE PILOTOS ***\n");
		printf("--------------------------------\n\n");
		printf("[C] Cadastrar Piloto.\n");
		printf("[A] Alterar Piloto.\n");
		printf("[E] Excluir Pilotos.\n");
		printf("[X] Voltar ao menu anterior...\n\n");
		leValidaOpcao("Qual opcao deseja[C/A/E/X]? ", opcaoUsuario, "CAEX");
		switch(*opcaoUsuario){
			case 'C':
				cadastraPiloto(pilotos, qtdPilotos);
				break;
			case 'A':
				//alteraPiloto(pilotos, *qtdPilotos);
				break;
			case 'E':
				//exlcuiPiloto(pilotos, *qtdPilotos);
				break;
			default:
				*validaInteracao = 0;
		}	
	}while(*validaInteracao == 1);
}

//Objetivo	: Exibir o menu CRUD da classe equipe.
//Parâmetros:
//Retorno	: ***
void menuEquipeCRUD(struct Equipe *equipes, char *opcaoUsuario, int *validaInteracao, int *qtdEquipes){
	do{
		system("cls");
		printf("*** GERENCIAMENTO DE EQUIPES ***\n");
		printf("--------------------------------\n\n");
		printf("[C] Cadastrar Equipe.\n");
		printf("[E] Excluir Equipe.\n");
		printf("[X] Voltar ao menu anterior...\n\n");
		leValidaOpcao("Qual opcao deseja[C/E/X]? ", opcaoUsuario, "CEX");
		switch(*opcaoUsuario){
			case 'C':
				//cadastraEquipe(equipes, qtdEquipes);
				break;
			case 'E':
				//exlcuiEquipe(equipes, qtdEquipes);
				break;
			default:
				*validaInteracao = 0;
		}
	}while(*validaInteracao == 1);
}

//Objetivo	: Exibir o menu CRUD da classe circuito.
//Parâmetros:
//Retorno	: ***
void menuCircuitoCRUD(struct Circuito *circuitos, char *opcaoUsuario, int *validaInteracao, int *qtdCircuitos){
	do{
		system("cls");
		printf("*** GERENCIAMENTO DE CIRCUITOS ***\n");
		printf("--------------------------------\n\n");
		printf("[C] Cadastrar Circuito.\n");
		printf("[A] Alterar Circuito.\n");
		printf("[X] Voltar ao menu anterior...\n\n");
		leValidaOpcao("Qual opcao deseja[C/A/X]? ", opcaoUsuario, "CAX");
		switch(*opcaoUsuario){
			case 'C':
				//cadastraCircuito(circuitos, qtdCircuitos);
				break;
			case 'A':
				//alteraCircuito(pilotos, qtdPilotos);
				break;
			default:
				*validaInteracao = 0;
		}	
	}while(*validaInteracao == 1);
}

//Objetivo	: Exibir o menu CRUD da classe melhoresVoltas.
//Parâmetros:
//Retorno	: ***
void menuMelhorVoltaCRUD(struct MelhorVolta *melhoresVoltas, char *opcaoUsuario, int *validaInteracao, int *qtdMelhoresVoltas){
	do{
		system("cls");
		printf("*** GERENCIAMENTO DE MELHORES VOLTAS ***\n");
		printf("--------------------------------\n\n");
		printf("[C] Cadastrar Melhor Volta.\n");
		printf("[A] Alterar Melhor Volta.\n");
		printf("[E] Excluir Melhor Volta.\n");
		printf("[X] Voltar ao menu anterior...\n\n");
		leValidaOpcao("Qual opcao deseja[C/A/E/X]? ", opcaoUsuario, "CAEX");
		switch(*opcaoUsuario){
			case 'C':
				//cadastraMelhorVolta(melhoresVoltas, qtdMelhoresVoltas);
				break;
			case 'A':
				//alteraMelhorVolta(melhoresVoltas, qtdMelhoresVoltas);
				break;
			case 'E':
				//exlcuiMelhorVolta(melhoresVoltas, qtdMelhoresVoltas);;
				break;
			default:
				*validaInteracao = 0;
		}	
	}while(*validaInteracao == 1);
}
