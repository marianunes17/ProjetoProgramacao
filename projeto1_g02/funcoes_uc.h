#ifndef funcoes_uc
#define funcoes_uc

#include "constantes.h"


void escreveDadosUc(tipoUc vetorUc);
tipoUc leDadosUc();
void listaDadosUc(tipoUc vetorUc[MAX_UC], int numTotalUc);
int procuraUc(tipoUc vetorUc[], int numTotalUc, int codigoUC);
void pesquisaCodigoUc(tipoUc vetorUc[], int numTotalUc);
void acrescentaUc(tipoUc vetorUc[MAX_UC], int *numTotalUc, int codigoUc);
void eliminarVetorUc(tipoUc vetorUc[], tipoAula vAulas[], int *numTotalUc);
void alterarVetorUc(tipoUc vetorUc[], int numTotalUc);

void gravarUcTexto(tipoUc vetorUc[], int numTotalUc);
void gravarUcBinario(tipoUc vetorUc[], int *numTotalUc);
void leFicheiroUcTexto(tipoUc vetorUc[], int *numTotalUc);
void leFicheiroUcBinario(tipoUc vetorUc[], int *numTotalUc);

#endif // funcoes_uc
