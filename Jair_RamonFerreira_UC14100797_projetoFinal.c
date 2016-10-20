// Aluno: Ramon Ferreira

/*
SINTESE
	Objetivo :
	Entrada  :
	Saída    :
*/

#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
//#include <conio.c>

/* Protótipo das Funções & Procedimentos */
void obterData();

/* Definições MACRO */
#define TAM_NOME_PROPRIETARIO 90
#define TAM_DESCRICAO 120
#define TAM_NOME_CIDADE 50
#define TAM_PLACA 7
#define TAM_MODELO 80
#define TAM_FABRICANTE 60
#define TAM_CHASSI 17
#define TAM_DESCRICAO_SERVICO 500

/* Structs */
struct Endereco{
	char descricao[TAM_DESCRICAO];
	char cidade[TAM_NOME_CIDADE];
	char estado[2];
};

struct Telefone{
	int ddd;
	int numero;
};

struct Proprietario{
	char nome[TAM_NOME_PROPRIETARIO];
	int cpf;
	struct Endereco endereco;
	struct Telefone telefone;
};

struct Veiculo{
	char placa[TAM_PLACA];
	char modelo[TAM_MODELO];
	char fabricante[TAM_FABRICANTE];
	char chassi[TAM_CHASSI];
	int anoFabricacao;
};

struct Manutencao{
	int idVeiculo;
	int idProprietario;
	char descricaoServico[TAM_DESCRICAO_SERVICO];
	float valorPecas;
	float valorServico;
	char data[12] == {__DATE__};
};

int main(){
	setlocale(LC_ALL,"portuguese");
// Declarações

// Instruções

}

/* Protótipo das Funções & Procedimentos */

// Objetivo   : Obter a data do sistema e formatá-la.
// Parâmetros : ***
// Retorno    : ***
void obterData(){
	char mes[4], dia[3], ano[5];
	
	strcpy(mes, "");
	strcpy(dia, "");
	strcpy(ano, "");
	strncat(mes, __DATE__ , 3);
	strncat(dia, __DATE__ +4, 2);
	strncat(ano, __DATE__ +7, 4);
	printf("%s %s %s\n", dia, mes, ano);
}
