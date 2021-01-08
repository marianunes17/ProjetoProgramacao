#ifndef funcoes_uc
#define funcoes_uc

#include "constantes.h"


void escreveDadosUc(tipoUc vetorUc);
tipoUc leDadosUc();
void listaDadosUc(tipoUc vetorUc[MAX_UC], int numUc);
int procuraUc(tipoUc vetorUc[], int numUc, int codigoUC);
void acrescentaUc(tipoUc vetorUc[MAX_UC], int *numUc, int codigoUc);
void eliminarDoVetor(tipoUc vetorUc[], int *numUc);
void alterarVetorUc(tipoUc vetorUc[], int *numUc);

void gravarUcTexto(tipoUc vetorUc[], int numUc);
void gravarUcBinario(tipoUc vetorUc[], int numUc);
void leFicheiroUcTexto(tipoUc vetorUc[], int *numUc);
void leFicheiroUcBinario(tipoUc vetorUc[], int *numUc);

#endif // funcoes_uc
