#ifndef FUNCOES_ESTATISTICA_H_INCLUDED
#define FUNCOES_ESTATISTICA_H_INCLUDED

void rakingUcGravacoes(tipoUc vetorUc[], int numTotalUc);

void mediaPresencasAulas(tipoAula vAulas[], int numAulas, int numTotalAulasAssistidas);

void ordenaPosUcGravacao(tipoUc vetorUc[], int numTotalUc);
void percentagemUcAulasGravadas(tipoUc vetorUc[], int numTotalUc);

void ordenaPosAulasRealizadas(tipoUc vetorUc[], int numTotalUc);
void UcMenorAulasRealizadas(tipoUc vetorUc[], int numTotalUc);


void ordenaAulaTipo(tipoUc vetorUc[], int numTotalUc);
void tipoAulasMaiorAcessoGravacoes(tipoUc vetorUc[], int numTotalUc);


void ordenarMaiorAcessoGravacoes(tipoUc vetorUc[], int numTotalUc);
void rakingUcGravacoes(tipoUc vetorUc[], int numTotalUc);

void quantidadeAulasOnline(tipoAula vAulas[], int numTotalAulas);
void quantidadeAulasRealizadasUc(tipoUc vetorUc[],int numTotalUc,int quantAulasRealizadas);

void aulasRealizadasAntigas(tipoAula vAulas[], int numTotalAulas);




#endif // FUNCOES_ESTATISTICA_H_INCLUDED
