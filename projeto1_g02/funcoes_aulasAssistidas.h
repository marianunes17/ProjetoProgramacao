#ifndef FUNCOES_AULASASSISTIDAS_H_INCLUDED
#define FUNCOES_AULASASSISTIDAS_H_INCLUDED

#include "funcoes_aulasAssistidas.h"

void escreveDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas);
void listaDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas[], int numAulasAssistidas);
void acrescentaAulaAssistida(tipoAulasAssistidas vAulasAssistidas[], int posicaoEstudante, char designacaoAula[], char acesso[], int *numAulasAssistidas);
int procuraAulaAssistida(tipoEstudante vEstudante[], int numTotalEstudantes, int numEstudante);

void assistirAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int *numAulasAssistidas);
void assistirGravacaoAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int *numAulasAssistidas);

void listaAulasComGravacao(tipoAula vAulas[], int numAulas);

void gravaAulasEstudantesBin(tipoAulasAssistidas vAulasAssistidas[], int numAulasAssistidas);
void leAulasEstudantesBin(tipoAulasAssistidas vAulasAssistidas[], int *numAulasAssistidas);
void gravaAulasEstudantesTxt(tipoAulasAssistidas vAulasAssistidas[], int numAulasAssistidas);
void leAulasEstudantesTxt(tipoAulasAssistidas vAulasAssistidas[], int *numAulasAssistidas);
#endif // FUNCOES_AULASASSISTIDAS_H_INCLUDED
