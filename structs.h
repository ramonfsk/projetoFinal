typedef struct Pais{
	char siglaPais[4], nomePais[15];
}tPais;

typedef struct Data{
	unsigned int dia, mes, ano;
}tData;

typedef struct Tempo{
	unsigned int hora, minuto, segundo, milissegundo;
}tTempo;

typedef struct Equipe{
	char nomeEquipe[20], siglaEquipe[4], paisOrigem[15];
}tEquipe;

typedef struct Piloto{
	int idPiloto;
	char nomePiloto[30], siglaEquipe[3], dataNascimento[10], paisOrigem[15];
	char sexoPiloto;
}tPiloto;

typedef struct Circuito{
	int idCircuito, idPiloto;
	char nomeCircuito[15], paisCircuito[15], tempoRecorde[13];
	float tamanhoCircuito;
}tCircuito;

typedef struct MelhorVolta{
	int id, idPiloto, idCircuito;
	char nomeEquipe[20], data[10], tempoRecorde[13];
}tMelhorVolta;
