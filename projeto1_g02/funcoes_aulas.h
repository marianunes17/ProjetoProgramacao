#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

#include "constantes.h"

tipoAula lerDadosAula();
tipoAula *acrescentaAula(tipoAula vAula[], int *num, tipoUc vetorUc[],int numCodigo);

tipoAula *eliminaAula(tipoAula vAulas[], int *num, char designacao[]);
int procuraAulaNome(tipoAula vAula[], int num, char procAula[]);

int procuraUc(tipoUc vetorUc[MAX_UC], int numUc, int codigoUC); //buscar o da MAria~!!!

tipoAula *lerFicheiroBin(tipoAula vAulas[],int *num);
tipoAula *gravaFicheiroBin(tipoAula vAulas[],int *num);

#endif // FUNCOES_AULAS_H_INCLUDED
