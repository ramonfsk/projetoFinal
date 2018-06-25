typedef struct Pais{
	char siglaPais[3], nomePais[15];
}tPais;

typedef struct Data{
	unsigned int dia, mes, ano;
}tData;

typedef struct Tempo{
	unsigned int hora, minuto, segundo, milissegundo;
}tTempo;

typedef struct Equipe{
	int idEquipe;
	char nomeEquipe[20], siglaEquipe[3], paisOrigem[15];
}tEquipe;

typedef struct Piloto{
	int id;
	char nome[30], sigla[3], dataNascimento[10], paisOrigem[15];
	char sexo;
}tPiloto;

typedef struct Circuito{
	int id, idPiloto;
	char nome[15], pais[15], tempoRecorde[13];
	float tamanho;
}tCircuito;

typedef struct MelhorVolta{
	int id, idPiloto, idCircuito;
	char nomeEquipe[20], data[10], tempoRecorde[13];
}tMelhorVolta;
