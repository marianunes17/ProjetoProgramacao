#ifndef FUNCOES_AULASASSISTIDAS_H_INCLUDED
#define FUNCOES_AULASASSISTIDAS_H_INCLUDED

#include "constantes.h"

tipoAulasAssistidas leDadosAulaAssistidas(int numeroEstudante, char designacao[], char acesso[]);
void escreveDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas);
void listaDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas);
void acrescentaAulaAssistida(tipoAulasAssistidas vAulasAssistidas[], int posicaoEstudante, char designacaoAula[], char acesso[], int *numAulasGravacoesAssistidas);
void procuraAulaAssistidaAula(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas, char designacao[], int *contadorAulas);
void procuraAulaAssistidaGravacao(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas, char designacao[], int *contadorAulas);
int procuraEstudanteAssistir(tipoAulasAssistidas vAulasAssistidas[], char designacao[], int numeroEstudante, int numAulasGravacoesAssistidas);

void assistirAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int *numTotalAulasAssistidas, int *numAulasGravacoesAssistidas, int numTotalGravacoesAssistidas);
void assistirGravacaoAula(tipoAulasAssistidas vAulasAssistidas[], tipoUc vetorUc[], tipoAula vAulas[], tipoEstudante vEstudante[],  int numTotalEstudantes,  int numTotalAulas, char designacaoAula[], int *numTotalGravacoesAssistidas, int *numAulasGravacoesAssistidas, int *numTotalAulasAssistidas, int numTotalUc);
void listaAulasComGravacao(tipoAula vAulas[], int numAulas);


void gravaAulasEstudantesBin(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas, int numTotalAulasAssistidas, int numTotalGravacoesAssistidas);
void leAulasEstudantesBin(tipoAulasAssistidas vAulasAssistidas[], int *numAulasGravacoesAssistidas, int *numTotalAulasAssistidas, int *numTotalGravacoesAssistidas);
void gravaAulasEstudantesTxt(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas, int numTotalAulasAssistidas, int numTotalGravacoesAssistidas);
void leAulasEstudantesTxt(tipoAulasAssistidas vAulasAssistidas[], int *numAulasGravacoesAssistidas, int *numTotalAulasAssistidas, int *numTotalGravacoesAssistidas);
#endif // FUNCOES_AULASASSISTIDAS_H_INCLUDED
