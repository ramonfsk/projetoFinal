#define ARQV_EQUIPES "equipes.bin"
#define ARQV_PAISES "paises.txt"
#define MSG_ERRO "\n*** ENTRADA INVALIDA! ***\n\n"

/* Menu de Intera��o*/
void menuEquipeCRUD(char *opcaoUsuario, int *validaInteracao);
/* CRUD da Classe Equipe*/
void cadastraEquipe();
void excluiEquipe();
/* Fun��es & Procedimentos da Classe Equipe*/
void obtemQtdEquipes();
void selecionaPais();
int comparaId();
