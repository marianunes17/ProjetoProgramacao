#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

#include "constantes.h"

tipoAula lerDadosAula();
tipoAula *acrescentaAula(tipoAula vAula[], int *num, tipoUc vetorUc[],int numCodigo);

tipoAula *eliminaAula(tipoAula vAulas[], int *num, char designacao[]);
int procuraAulaNome(tipoAula vAula[], int num, char procAula[]);
void mostrarDadosAula(tipoAula vAulas[], int numAula);


tipoAula *lerFicheiroBin(tipoAula vAulas[],int *num);
//tipoAula *gravaFicheiroBin(tipoAula vAulas[],int *num);
void  gravaFicheiroBin(tipoAula vAulas[],int num);
void gravaFicheiroTextAula(tipoAula vAulas[],int num);
tipoAula *lerFicheiroTextAula(tipoAula vAulas[],int *num);


#endif // FUNCOES_AULAS_H_INCLUDED
