//Classe: Equipe
#include "gerenciaEquipes.h"
#include "structs.h"
#include "validacoes.h"
#include "funcoes.h"
/* Métodos */

//Objetivo	: Exibir o menu CRUD da classe equipe.
//Parâmetros:
//Retorno	: ***
void menuEquipeCRUD(char *opcaoUsuario, int *validaInteracao){
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
				cadastraEquipe();
				break;
			case 'E':
				excluiEquipe();
				break;
			default:
				*validaInteracao = 0;
		}
	}while(*validaInteracao == 1);
}

void cadastraEquipe(){
	int qtdEquipes, tempQtdEquipes;
	char opcaoUsuario;
	tEquipe *pEquipes;
	FILE *arqvEquipes;
	//Inicializar variaveis
	qtdEquipes = 0;
	pEquipes = NULL;
	arqvEquipes = NULL;
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
	obtemQtdEquipes(arqvEquipes, &qtdEquipes);
	if(qtdEquipes == 0){
		if((pEquipes = (tEquipe*) calloc(1, sizeof(tEquipe))) == NULL){
			printf("\n*** FALHA AO ALOCAR MEMORIA! ***\n\n");
			exit(EXIT_FAILURE);
		}
	}else{
		if((pEquipes = (tEquipe*) calloc(qtdEquipes, sizeof(tEquipe))) == NULL){
			printf("\n*** FALHA AO ALOCAR MEMORIA! ***\n\n");
			exit(EXIT_FAILURE);
		}
		fseek(arqvEquipes, 0, SEEK_SET);
		tempQtdEquipes = 0;
		while(fread((pEquipes+tempQtdEquipes), sizeof(tEquipe), 1, arqvEquipes) == 1){
			tempQtdEquipes++;
		}	
	}
	//Cadastrar nova equipe
	do{
		system("cls");
		printf("*** CADASTRO DE EQUIPES ***\n");
		printf("---------------------------\n\n");
		//Insere um id sequencial
		pEquipes[0].idEquipe = (qtdEquipes+1);
		//Nome da Equipe
		leValidaString("Informe o nome da equipe: ", MSG_ERRO, pEquipes[0].nomeEquipe, 0);
		//Sigla
		leValidaSigla("Agora, informe a sigla da equipe: ", MSG_ERRO, pEquipes[0].siglaEquipe);
		//Pais de Origem
		selecionaPais(pEquipes[0].paisOrigem);
		//Gravar dados no arquivo
		fseek(arqvEquipes, 0, SEEK_END);
		fwrite(pEquipes, sizeof(tEquipe), 1, arqvEquipes);
		leValidaOpcao("Deseja cadstrar mais uma equipe[S/N]? ", &opcaoUsuario, "SN");
		if(opcaoUsuario == 'S'){
			//Incremento da quantidade de equipes
			qtdEquipes++;
		}
	}while(opcaoUsuario == 'S');
	//Desalocando
	free(pEquipes);
	//Fechando o arquivo
	fclose(arqvEquipes);
}

void excluiEquipe(){
	int qtdEquipes, contQtdEquipes, escolhaUsuario;
	char opcaoUsuario;
	tEquipe *pEquipes;
	FILE *arqvEquipes;
	qtdEquipes = 0;
	contQtdEquipes;
	pEquipes = NULL;
	arqvEquipes = NULL;
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
	obtemQtdEquipes(arqvEquipes, &qtdEquipes);
	if(qtdEquipes == 0){
		printf("\n*** Não há equipes cadastradas! ***\n\n");
		getch();
		return;
	}else{
		if((pEquipes = (tEquipe*) calloc(qtdEquipes, sizeof(tEquipe))) == NULL){
			printf("\n*** FALHA AO ALOCAR MEMORIA! ***\n\n");
			exit(EXIT_FAILURE);
		}
		fseek(arqvEquipes, 0, SEEK_SET);
		qtdEquipes = 0;
		while(fread((pEquipes+qtdEquipes), sizeof(tEquipe), 1, arqvEquipes) == 1){
			qtdEquipes++;
		}
	}
	//
	do{
		escolhaUsuario = 0;
		opcaoUsuario = '\0';
		system("cls");
		printf("*** EXCLUSÂO DE EQUIPES ***\n");
		printf("---------------------------\n\n");
		printf("+----+---------------+-------+---------------+\n");
		printf("| ID |      NOME     | SIGLA |      PAIS     |\n");
		printf("+----+---------------+-------+---------------+\n");
		for(contQtdEquipes = 0; contQtdEquipes < qtdEquipes; contQtdEquipes++){
			printf("|%4i|%15s|%7s|%15s|\n",
				pEquipes[contQtdEquipes].idEquipe,
				pEquipes[contQtdEquipes].nomeEquipe,
				pEquipes[contQtdEquipes].siglaEquipe,
				pEquipes[contQtdEquipes].paisOrigem
			);
			printf("+----+---------------+-------+---------------+\n");
		}
		leValidaInt("\nEscolha uma equipe para ser excluida: ", MSG_ERRO, &escolhaUsuario, 1, contQtdEquipes+1);
		pEquipes[escolhaUsuario].idEquipe = 0;
		strcpy(pEquipes[escolhaUsuario].nomeEquipe, "\0");
		strcpy(pEquipes[escolhaUsuario].siglaEquipe, "\0");
		strcpy(pEquipes[escolhaUsuario].paisOrigem, "\0");
		qtdEquipes--;
		//Ordena
		qsort(pEquipes, qtdEquipes, sizeof(tEquipe), comparaId);
		//Gravar dados no arquivo
		fseek(arqvEquipes, 0, SEEK_SET);
		fwrite(pEquipes, sizeof(tEquipe), qtdEquipes, arqvEquipes);
		leValidaOpcao("\nDeseja excluir mais uma equipe[S/N]? ", &opcaoUsuario, "SN");
	}while(opcaoUsuario == 'S');
	//Desaloca
	free(pEquipes);
	//Fecha o arquivo
	fclose(arqvEquipes);
}

/* Funções & Procedimentos da Classe Equipes */

//Objetivo	: Apresentar paises ao usuário e deixa-lo escolher um.
//Parâmetros: Referência ao ponteiro do elemento pais da struct tEquipe.
//Retorno	: ***
void selecionaPais(char *paisOrigem){
	int contQtdPaises, qtdPaises, opcaoPais;
	tPais *pPaises, tempStruct;
	FILE *arqvPaises;
	
	contQtdPaises = 0;
	qtdPaises = 0;
	pPaises = NULL;
	arqvPaises = NULL;
	
	//Abrir arquivo
	if((arqvPaises = fopen(ARQV_PAISES, "r")) == NULL){
		if((arqvPaises = fopen(ARQV_PAISES, "w+")) == NULL){
			printf("\n*** FALHA AO CRIAR O ARQUIVO! ***\n\n");
			fclose(arqvPaises);
			getch();
			return;
		}
	}else{
		if((arqvPaises = fopen(ARQV_PAISES, "r")) == NULL){
			printf("\n*** FALHA AO ABRIR O ARQUIVO! ***\n\n");
			fclose(arqvPaises);
			getch();
			return;
		}
	}
	
	fseek(arqvPaises, 0, SEEK_SET);
	while(!feof(arqvPaises)){
		fscanf(arqvPaises, "%s", &tempStruct.siglaPais);
		fseek(arqvPaises, (long) sizeof(char), SEEK_CUR);
		fscanf(arqvPaises, "%s\n", &tempStruct.nomePais);
		qtdPaises++;
	}
	//Insere os dados na memoria
	if(qtdPaises == 0){
		printf("\n*** Não há dados no arquivo paises.txt! ***\n\n");
		fclose(arqvPaises);
		return;
	}else{
		if((pPaises = (tPais*) calloc(qtdPaises, sizeof(tPais))) == NULL){
			printf("\n*** FALHA AO ALOCAR MEMORIA! ***\n\n");
			exit(EXIT_FAILURE);
		}else{
			qtdPaises = 0;
			fseek(arqvPaises, 0, SEEK_SET);
			while(!feof(arqvPaises)){
				fscanf(arqvPaises, "%s", (pPaises+qtdPaises)->siglaPais);
				fseek(arqvPaises, (long) sizeof(char), SEEK_CUR);
				fscanf(arqvPaises, "%s\n", (pPaises+qtdPaises)->nomePais); 
				qtdPaises++;
			}
		}
	}
	//O usuário seleciona um pais
	printf("+----+----+---------------+\n");
	for(contQtdPaises = 0; contQtdPaises < qtdPaises; contQtdPaises++){
		printf("|%4i|%4s|%-15s|\n", contQtdPaises+1, (pPaises+contQtdPaises)->siglaPais, (pPaises+contQtdPaises)->nomePais);
	}
	printf("+----+----+---------------+\n");
	leValidaInt("\nSelecione um pais[1-10]: ", MSG_ERRO, &opcaoPais, 1, contQtdPaises+1);
	memcpy(paisOrigem, (pPaises+(opcaoPais-1))->nomePais, sizeof((pPaises+(opcaoPais-1))->nomePais));
	free(pPaises);
	fclose(arqvPaises);
}

int comparaId(const void * a, const void * b){
	if((*(tEquipe*)a).idEquipe == (*(tEquipe*)b).idEquipe){
		return 0;
	}else{
		if((*(tEquipe*)a).idEquipe < (*(tEquipe*)b).idEquipe){
			return -1;
		}else{
			return 1;
		}
	}
}

//Objetivo	: Obter a quantidade de equipes já cadastradas.
//Parâmetros: Ponteiro para o arquivo e a quantidade de  equipes.
//Retorno	: ***
void obtemQtdEquipes(FILE *arqvEquipes, int *qtdEquipes){
	tEquipe tempStruct;
	
	fseek(arqvEquipes, 0, SEEK_SET);
	while(fread(&tempStruct, sizeof(tEquipe), 1, arqvEquipes) == 1){
		(*qtdEquipes)++;
	}
}
