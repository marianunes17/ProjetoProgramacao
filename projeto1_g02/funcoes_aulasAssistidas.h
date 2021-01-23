#ifndef FUNCOES_AULASASSISTIDAS_H_INCLUDED
#define FUNCOES_AULASASSISTIDAS_H_INCLUDED

tipoAulasAssistidas ledadosAulasAssistidas(int posicaoEstudante, char designacaoAula[], char acesso[]);
void escreveDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas);
void listaDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas[], int numAulasAssistidas);
void acrescentaAulaAssistida(tipoAulasAssistidas vAulasAssistidas[], int posicaoEstudante, char designacaoAula[], char acesso[], int *numAulasAssistidas);
int procuraAulaAssistida(tipoEstudante vEstudante[], int numTotalEstudantes, int numEstudante);

void assistirAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int numAulasAssistidas);
void assistirGravacaoAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int numAulasAssistidas);

void listaAulasComGravacao(tipoAula vAulas[], int numAulas);

void gravaAulasEstudantesBin(tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAula[], int numTotalAulas);
void gravaAulasEstudantesTxt(tipoEstudante vEstudante[], int numTotalEstudantes, int numeroEstudante, tipoAula vAula[], int numTotalAulas, int posicaoAula);
void leAulasEstudantesTxt(tipoEstudante vEstudante[], int *numTotalEstudantes, int *posicaoEstudante, tipoAula vAula[], int *numTotalAulas, int posicaoAula);

#endif // FUNCOES_AULASASSISTIDAS_H_INCLUDED
