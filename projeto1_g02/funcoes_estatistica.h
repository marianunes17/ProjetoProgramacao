#ifndef FUNCOES_ESTATISTICA_H_INCLUDED
#define FUNCOES_ESTATISTICA_H_INCLUDED

void quantidadeAulasOnline(tipoAula vAulas[], int numTotalAulas);
void quantidadeAulasRealizadasUc(tipoUc vetorUc[],int numTotalUc,int quantAulasRealizadas);
void mediaPresencasAulas(tipoAula vAulas[], int numAulas, int numTotalAulasAssistidas);
void aulasRealizadasAntigas(tipoAula vAulas[], int numTotalAulas);

void ordenaPosUcGravacao(tipoUc vetorUc[], int numTotalUc);
void ordenaPosAulasRealizadas(tipoUc vetorUc[], int numTotalUc);
void percentagemUcAulasGravadas(tipoUc vetorUc[], int numTotalUc);

#endif // FUNCOES_ESTATISTICA_H_INCLUDED
