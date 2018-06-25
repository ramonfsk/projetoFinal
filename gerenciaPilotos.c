#include "gerenciaPilotos.h"
#include "structs.h"
#include "validacoes.h"

//Objetivo	: Exibir o menu CRUD da classe equipe.
//Parâmetros:
//Retorno	: ***
void menuPilotoCRUD(char *opcaoUsuario, int *validaInteracao){
	do{
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
				//cadastraPiloto();
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
