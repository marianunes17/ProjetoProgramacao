#ifndef funcoes_auxiliares
#define funcoes_auxiliares

#include "constantes.h"


int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
tipoData lerData(void);
void limpaBufferStdin(void);

#endif
