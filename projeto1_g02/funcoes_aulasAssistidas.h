#ifndef FUNCOES_AULASASSISTIDAS_H_INCLUDED
#define FUNCOES_AULASASSISTIDAS_H_INCLUDED

#include "constantes.h"

tipoAulasAssistidas leDadosAulaAssistidas(int numeroEstudante, char designacao[], char acesso[]);
void escreveDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas);
void listaDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas);
void acrescentaAulaAssistida(tipoAulasAssistidas vAulasAssistidas[], int posicaoEstudante, char designacaoAula[], char acesso[], int *numAulasGravacoesAssistidas);
void procuraAulaAssistidaAula(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas, char designacao[], int *contadorAulas, int *contadorGravacoes);
void procuraAulaAssistidaGravacao(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas, char designacao[], int *contadorAulas, int *contadorGravacoes);
int procuraAssistir(tipoAulasAssistidas vAulasAssistidas[], char designacaoAula, int numeroEstudante, int numAulasGravacoesAssistidas);

void assistirAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int *numTotalAulasAssistidas, int *numAulasGravacoesAssistidas);
void assistirGravacaoAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int *numTotalAulasAssistidas, int *numAulasGravacoesAssistidas);
void listaAulasComGravacao(tipoAula vAulas[], int numAulas);


void gravaAulasEstudantesBin(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas);
void leAulasEstudantesBin(tipoAulasAssistidas vAulasAssistidas[], int *numAulasGravacoesAssistidas);
void gravaAulasEstudantesTxt(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas);
void leAulasEstudantesTxt(tipoAulasAssistidas vAulasAssistidas[], int *numAulasGravacoesAssistidas);
#endif // FUNCOES_AULASASSISTIDAS_H_INCLUDED
