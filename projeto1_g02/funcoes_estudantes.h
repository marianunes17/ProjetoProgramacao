#ifndef funcoes_estudantes
#define funcoes_estudantes

#include "constantes.h"

void escreveDadosEstudante(tipoEstudante vEstudante[]);
tipoEstudante leDadosEstudante();
void listaDadosEstudante(tipoEstudante vEstudante[MAX_ESTUDANTES], int numTotalEstudantes);
int procuraEstudante(tipoEstudante vEstudante[], int numTotalEstudantes, int numeroEstudante);
void acrescentaEstudante(tipoEstudante vEstudante[], int *numTotalEstudantes, int numeroEstudante);
void alterarVetorEstudante(tipoEstudante vEstudante[], int numTotalEstudantes);
void assistirAula(tipoEstudante vEstudante[], int *numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[]);

void gravarTextoEstudantes(tipoEstudante vEstudante[], int numTotalEstudante);
void gravarBinarioEstudantes(tipoEstudante vEstudante[], int numTotalEstudante);
void leFicheiroTextoEstudantes(tipoEstudante vEstudante[], int *numTotalEstudante);
void leFicheiroUcBinarioEstudantes(tipoEstudante vEstudante[], int *numTotalEstudante);


#endif
