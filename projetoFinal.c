// Aluno	: Ramon Ferreira
// Matrícula: UC14100797

/*
SINTESE
Objetivo: 
Entrada	: 
Saída	: 
*/
#define TAM_NOMECIRCUITO 20
#define TAM_TEMPO 13

/* Biliotecas */
#include "validacoes.h"
#include "gerenciaEquipes.h"
#include "gerenciaPilotos.h"
#include "gerenciaCircuitos.h"
#include "gerenciaMelhoresVoltas.h"

int main(){
	int validaInteracao;
	char opcaoUsuario;
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
						case 'P':
							validaInteracao = 1;
							opcaoUsuario = '\0';
							//menuPilotoCRUD();
							validaInteracao = 1; // Gambiarra
							break;
						case 'E':
							validaInteracao = 1;
							opcaoUsuario = '\0';
							menuEquipeCRUD(&opcaoUsuario, &validaInteracao);
							validaInteracao = 1; // Gambiarra
							break;
						case 'C':
							validaInteracao = 1;
							opcaoUsuario = '\0';
							//menuCircuitoCRUD();
							validaInteracao = 1; // Gambiarra
							break;
						case 'M':
							validaInteracao = 1;
							opcaoUsuario = '\0';
							//menuMelhorVoltaCRUD();
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
