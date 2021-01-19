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
void eliminarEstudante(tipoEstudante vEstudante[], int *numTotalEstudantes);

void gravarEstudantesTexto(tipoEstudante vEstudante[], int numTotalEstudante);
void gravarEstudantesBinario(tipoEstudante vEstudante[], int numTotalEstudante);
void leEstudantesTexto(tipoEstudante vEstudante[], int *numTotalEstudante);
void leEstudantesBinario(tipoEstudante vEstudante[], int *numTotalEstudante);

void gravaAulasEstudantesBin(tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAula[], int numAulas);
void leAulasEstudantesBin(tipoEstudante vEstudante[], int *numTotalEstudantes, tipoAula vAula[], int *numAulas);
void gravaAulasEstudantesTxt(tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAula[], int numAulas);
void leAulasEstudantesTxt(tipoEstudante vEstudante[], int *numTotalEstudantes, tipoAula vAula[], int *numAulas);


void escreveAulasEstudantes(tipoEstudante vEstudante, tipoAula vAulas[]);
void listaDadosAulasEstudantes(tipoEstudante vEstudante[MAX_ESTUDANTES], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas);
#endif
