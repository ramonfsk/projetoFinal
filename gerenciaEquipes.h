#define ARQV_EQUIPES "equipes.bin"
#define ARQV_PAISES "paises.txt"
#define MSG_ERRO "\n*** ENTRADA INVALIDA! ***\n\n"

/* Menu de Interação*/
void menuEquipeCRUD();
/* CRUD da Classe Equipe*/
void cadastraEquipe();
void excluiEquipe();
/* Funções & Procedimentos da Classe Equipe*/
void validaNomeEquipeRepetida();
void validaSiglaEquipeRepetida();
void selecionaPais();
