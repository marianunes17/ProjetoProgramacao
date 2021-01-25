#ifndef FUNCOES_ESTATISTICA_H_INCLUDED
#define FUNCOES_ESTATISTICA_H_INCLUDED


void mediaPresencasAulas(tipoAula vAulas[], int numAulas, int numTotalAulasAssistidas);

void ordenaPosUcGravacao(tipoUc vetorUc[], int numTotalUc);
void percentagemUcAulasGravadas(tipoUc vetorUc[], int numTotalUc);

void ordenaPosAulasRealizadas(tipoUc vetorUc[], int numTotalUc);
void UcMenorAulasRealizadas(tipoUc vetorUc[], int numTotalUc);

void aulasMaiorAcessoGravacoes(tipoUc vetorUc[], int numTotalUc);

void quantidadeAulasOnline(tipoAula vAulas[], int numTotalAulas);
void quantidadeAulasRealizadasUc(tipoUc vetorUc[],int numTotalUc,int quantAulasRealizadas);
void aulasRealizadasAntigas(tipoAula vAulas[], int numTotalAulas);


void ordenaAulaTipo(tipoUc vetorUc[], int numTotalUc);

#endif // FUNCOES_ESTATISTICA_H_INCLUDED
