//Classe: Equipe
#include "gerenciaEquipes.h"
#include "structs.h"
#include "validacoes.h"
#include "funcoes.h"
/* Métodos */

//Objetivo	: Exibir o menu CRUD da classe equipe.
//Parâmetros:
//Retorno	: ***
void menuEquipeCRUD(FILE *arqvEquipes, char *opcaoUsuario, int *validaInteracao, int *qtdEquipes){
	tEquipe tempStruct;
	do{
		
		*qtdEquipes = 0;
		fseek(arqvEquipes, 0, SEEK_SET);
		while(fread(&tempStruct, sizeof(tEquipe), 1, arqvEquipes) == 1){
			(*qtdEquipes)++;
		}
		//Apresentação do menu
		system("cls");
		printf("*** GERENCIAMENTO DE EQUIPES ***\n");
		printf("--------------------------------\n\n");
		printf("Qtd. Equipes: %i\n\n", *qtdEquipes);
		printf("[C] Cadastrar Equipe.\n");
		printf("[E] Excluir Equipe.\n");
		printf("[X] Voltar ao menu anterior...\n\n");
		leValidaOpcao("Qual opcao deseja[C/E/X]? ", opcaoUsuario, "CEX");
		switch(*opcaoUsuario){
			case 'C':
				cadastraEquipe(arqvEquipes, qtdEquipes);
				break;
			case 'E':
				excluiEquipe(arqvEquipes, qtdEquipes);
				break;
			default:
				*validaInteracao = 0;
		}
	}while(*validaInteracao == 1);
}

void cadastraEquipe(FILE *arqvEquipes, int *qtdEquipes){
	int contQtdEquipes, validaString;
	char opcaoUsuario;
	tEquipe *pEquipes, tempEquipe;
	//Inicializar variaveis
	pEquipes = NULL;
	if(*qtdEquipes == 0){
		if((pEquipes = (tEquipe*) calloc(1, sizeof(tEquipe))) == NULL){
			printf("\n*** FALHA AO ALOCAR MEMORIA! ***\n\n");
			exit(EXIT_FAILURE);
		}
	}else{
		if((pEquipes = (tEquipe*) calloc(*qtdEquipes, sizeof(tEquipe))) == NULL){
			printf("\n*** FALHA AO ALOCAR MEMORIA! ***\n\n");
			exit(EXIT_FAILURE);
		}else{
			//Aloca os dados em memoria
			fseek(arqvEquipes, 0, SEEK_SET);
			contQtdEquipes = 0;
			while(fread((pEquipes+contQtdEquipes), sizeof(tEquipe), 1, arqvEquipes) == 1){
				contQtdEquipes++;
			}
		}
	}
	//Cadastrar nova equipe
	do{
		system("cls");
		printf("*** CADASTRO DE EQUIPES ***\n");
		printf("---------------------------\n\n");
		//Nome da Equipe
		do{
			validaString = 0;
			leValidaString("Informe o nome da equipe: ", MSG_ERRO, tempEquipe.nomeEquipe, 0);
			validaNomeEquipeRepetida(pEquipes, *qtdEquipes, tempEquipe.nomeEquipe, &validaString);
			if(validaString == 1){
				printf("\n*** A equipe %s ja existe! ***\n\n", tempEquipe.nomeEquipe);
			}
		}while(validaString == 1);
		
		//Sigla
		do{
			validaString = 0;
			leValidaSigla("Agora, informe a sigla da equipe: ", MSG_ERRO, tempEquipe.siglaEquipe);
			validaSiglaEquipeRepetida(pEquipes, *qtdEquipes, tempEquipe.siglaEquipe, &validaString);
			if(validaString == 1){
				printf("\n*** A sigla %s ja existe! ***\n\n", tempEquipe.siglaEquipe);
			}
		}while(validaString == 1);
		
		//Pais de Origem
		selecionaPais(tempEquipe.paisOrigem);
		//Gravar dados no arquivo
		fseek(arqvEquipes, 0, SEEK_END);
		fwrite(&tempEquipe, sizeof(tEquipe), 1, arqvEquipes);
		printf("\nGravando dados.");
		sleep(1);
		printf(".");
		sleep(1);
		printf(".");
		sleep(1);
		printf("OK!\n\n");
		leValidaOpcao("Deseja cadstrar mais uma equipe[S/N]? ", &opcaoUsuario, "SN");
		if(opcaoUsuario == 'S'){
			//Incremento da quantidade de equipes
			(*qtdEquipes)++;
		}
	}while(opcaoUsuario == 'S');
	//Desalocando
	free(pEquipes);
	//Fechando o arquivo
	fclose(arqvEquipes);
}

void excluiEquipe(FILE *arqvEquipes, int *qtdEquipes){
	int contQtdEquipes, escolhaUsuario;
	char opcaoUsuario;
	tEquipe *pEquipes;
	pEquipes = NULL;
	//Verifica se há dados para serem excluidos
	if(*qtdEquipes == 0){
		printf("\n*** Nao ha equipes cadastradas! ***\n\n");
		getch();
		return;
	}else{
		if((pEquipes = (tEquipe*) calloc(*qtdEquipes, sizeof(tEquipe))) == NULL){
			printf("\n*** FALHA AO ALOCAR MEMORIA! ***\n\n");
			exit(EXIT_FAILURE);
		}
		//Aloca os dados em memoria
		fseek(arqvEquipes, 0, SEEK_SET);
		contQtdEquipes = 0;
		while(fread((pEquipes+contQtdEquipes), sizeof(tEquipe), 1, arqvEquipes) == 1){
			contQtdEquipes++;
		}
	}
	//Exclui um usuário
	do{
		escolhaUsuario = 0;
		opcaoUsuario = '\0';
		system("cls");
		printf("*** EXCLUSAO DE EQUIPES ***\n");
		printf("---------------------------\n\n");
		printf("+----+---------------+-------+---------------+\n");
		printf("| ID |      NOME     | SIGLA |      PAIS     |\n");
		printf("+----+---------------+-------+---------------+\n");
		for(contQtdEquipes = 0; contQtdEquipes < *qtdEquipes; contQtdEquipes++){
			printf("|%4i|%15s|%7s|%15s|\n",
				contQtdEquipes+1,
				pEquipes[contQtdEquipes].nomeEquipe,
				pEquipes[contQtdEquipes].siglaEquipe,
				pEquipes[contQtdEquipes].paisOrigem
			);
			printf("+----+---------------+-------+---------------+\n");
		}
		leValidaInt("\nEscolha uma equipe para ser excluida: ", MSG_ERRO, &escolhaUsuario, 1, contQtdEquipes+1);
		strcpy(pEquipes[escolhaUsuario-1].nomeEquipe, "\0");
		strcpy(pEquipes[escolhaUsuario-1].siglaEquipe, "\0");
		strcpy(pEquipes[escolhaUsuario-1].paisOrigem, "\0");
		for(contQtdEquipes = 0; contQtdEquipes < *qtdEquipes; contQtdEquipes++){
			if(strcmp(pEquipes[contQtdEquipes].nomeEquipe, "\0") == 0){
				pEquipes[contQtdEquipes] = pEquipes[contQtdEquipes+1];
			}
		}
		(*qtdEquipes)--;
		//Zera os dados no arquivo.
		fclose(arqvEquipes);
		if((arqvEquipes = fopen(ARQV_EQUIPES, "wb+")) == NULL){
			printf("\n*** FALHA AO ABRIR O ARQUIVO! ***\n\n");
			fclose(arqvEquipes);
			getch();
			return;
		}
		fseek(arqvEquipes, 0, SEEK_SET);
		//Regrava os dados sem a posição excluida.
		fwrite(pEquipes, sizeof(tEquipe), *qtdEquipes, arqvEquipes);
		printf("\nRegravando dados.");
		sleep(1);
		printf(".");
		sleep(1);
		printf(".");
		sleep(1);
		printf("OK!\n\n");
		if(*qtdEquipes > 0){
			leValidaOpcao("\nDeseja excluir mais uma equipe[S/N]? ", &opcaoUsuario, "SN");
		}
	}while(opcaoUsuario == 'S');
	//Desaloca
	free(pEquipes);
	//Fecha o arquivo
	fclose(arqvEquipes);
}

/* Funções & Procedimentos da Classe Equipes */

//Objetivo	: Validar se há uma string repetida.
//Parâmetros: 
void validaNomeEquipeRepetida(tEquipe *pEquipes, int qtdEquipes, char *string, int *validaRepetido){
	int contQtd;
	
	for(contQtd = 0; contQtd < qtdEquipes; contQtd++){
		if(stricmp(string, pEquipes[contQtd].nomeEquipe) == 0){
			*validaRepetido = 1;
			break;	
		}
	}
}

//Objetivo	: Validar se há uma string repetida.
//Parâmetros:
void validaSiglaEquipeRepetida(tEquipe *pEquipes, int qtdEquipes, char *string, int *validaRepetido){
	int contQtd;
	
	for(contQtd = 0; contQtd < qtdEquipes; contQtd++){
		if(stricmp(string, pEquipes[contQtd].siglaEquipe) == 0){
			*validaRepetido = 1;
			break;	
		}
	}
}

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
