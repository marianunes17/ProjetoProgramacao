#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

#include "constantes.h"

tipoAula lerDadosAula();
tipoAula *acrescentaAula(tipoAula vAula[], int *num, tipoUc vetorUc[], int posUc);
tipoAula *eliminaAula(tipoAula vAulas[], int *num, char designacao[], tipoUc vetorUc[], int numTotalUc);
int procuraAulaNome(tipoAula vAula[], int num, char procAula[]);
void mostrarDadosAula(tipoAula vAulas[], int numAula);
void alteraAulas(tipoAula vAula[], int *numAulas, char designacaoAula[], tipoUc vetorUc[], int numTotalUc);
void escreveDadosAulas(tipoAula vAulas);
void calculaHora(int *horaF, int *minF);
void pesquisaAula(tipoAula vAulas[], tipoAulasAssistidas vAulasAssistidas[], int num, int numAulasAssistidas, tipoUc vetorUc[], int numTotalUc);


int procuraHora(tipoAula vAula[], int numTotalAulas, int codigoUC, int ano, int mes, int dia, int hora, int minuto);

void listaAulasAgendadas(tipoAula vAulas[], int numAulas);
void listaAulasDecorrer(tipoAula vAulas[], int numAulas);
void listaAulasRealizadas(tipoAula vAulas[], int numAulas);

void lerQuantAulasAgendadas(int *quantidade, tipoAula vAulas[], int numAulas);
void lerQuantAulasRealizadas(int *quantidade, tipoAula vAulas[], int numAulas);
void lerQuantAulasGravadas(int *quantidade, tipoAula vAulas[], int numAulas);

void comecarAula(tipoAula vAulas[], int numTotalAulas, char designacaoAula[], tipoUc vetorUc[], int numTotalUc);
void terminarAula(tipoAula vAulas[], int numTotalAulas, char designacaoAula[],tipoUc vetorUc[], int numTotalUc);

tipoAula *lerFicheiroBin(tipoAula vAulas[],int *num);
void gravaFicheiroBin(tipoAula vAulas[],int num);
void gravaFicheiroTextAula(tipoAula vAulas[],int num);
tipoAula *lerFicheiroTextAula(tipoAula vAulas[],int *num);


#endif // FUNCOES_AULAS_H_INCLUDED
