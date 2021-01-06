#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

#include "constantes.h"

tipoAula lerDadosAula();
//tipoAula *acrescentaAula(tipoAula vAula[], int *num, tipoUc vetorUc[],int numCodigo);
int acrescentaAula(tipoAula vAulas[], int *numAula);

tipoAula *eliminaAula(tipoAula vAula[], int *num, char designacao[]);
int procuraAulaNome(tipoAula vAula[], int num, char procAula[]);

tipoAula *lerFicheiroBin(tipoAula vAulas[],int *num);
tipoAula *gravaFicheiroBin(tipoAula vAulas[],int *num);



#endif // FUNCOES_AULAS_H_INCLUDED
