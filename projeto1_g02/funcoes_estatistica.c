#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_aulasAssistidas.h"
#include "funcoes_uc.h"
#include "funcoes_aulas.h"
#include "funcoes_estudantes.h"
#include "funcoes_menus.h"


void quantAcessosGravacoes(){
}



void mediaPresencasAulas(tipoAula vAulas[], int numAulas, int numTotalAulasAssistidas){
   int i;
   float contador=0, media=0;

    if(numTotalAulasAssistidas==0){
        printf("\t\tNao ha informacao referente as aulas assistidas. \n");
    } else {
         for (i=0; i<numAulas; i++){
            if (strcmp(vAulas[i].estadoAula, "Realizada") == 0){
                contador++;
            }
        }

        media = ((float)(numTotalAulasAssistidas / contador));
        printf("\t\tA media de presenças de presenças nas aulas é de: %.2f % \n", media);
    }
}


void ordenaPosUcGravacao(tipoUc vetorUc[], int numTotalUc){
    int i, j, aux;  //j elementos a comparar

    for(i=0; i < numTotalUc-1; i++) {        //Percorre vetor
        for (j= i+1; j<numTotalUc; j++) {
            if( vetorUc[j].numGravacoes > vetorUc[i].numGravacoes ){        // para ordenacao decrescente
                aux = vetorUc[j].numGravacoes;       // Troca valores v[i] ↔ v[j] */
                vetorUc[j].numGravacoes = vetorUc[i].numGravacoes;
                vetorUc[i].numGravacoes = aux;
            }
        }
    }
}


void percentagemUcAulasGravadas(tipoUc vetorUc[], int numTotalUc){
    int i;
    float gravacoes=0, aulasRealizadas=0, percentagemTotal=0,totalGravacoes=0;
    float conta=0;

    ordenaPosUcGravacao(vetorUc, numTotalUc);

    for (i=0; i<numTotalUc; i++) {
        printf("\t\tCodigo: %d", vetorUc[i].codigo);
        printf("\n\t\tDesignacao: %s", vetorUc[i].designacao);
        printf("\n\t\tAulas Realizadas: %d", vetorUc[i].quantAulasRealizadas);
        printf("\n\t\tAulas gravadas: %d", vetorUc[i].numGravacoes);


        gravacoes = vetorUc[i].numGravacoes;
        aulasRealizadas = vetorUc[i].quantAulasRealizadas;

        conta = ((float)((gravacoes/ 100) * (aulasRealizadas)));
        printf("\n\t\tPercentagem de gravacoes: %.2f %\n\n", conta);

        totalGravacoes = (float)(totalGravacoes + vetorUc[i].numGravacoes);
    }
    percentagemTotal = ((float)((totalGravacoes/ 100) * (aulasRealizadas)));

    printf("\n\n\t\tPercentagem de UCs com aulas gravadas %.2f\n\n", percentagemTotal);


}


void ordenaPosAulasRealizadas(tipoUc vetorUc[], int numTotalUc){
    int i, j, aux;  //j elementos a comparar

    for(i=0; i < numTotalUc-1; i++) {        //Percorre vetor
        for (j= i+1; j<numTotalUc; j++) {
            if( vetorUc[j].quantAulasRealizadas < vetorUc[i].quantAulasRealizadas ){        // para ordenacao crescente
                aux = vetorUc[j].quantAulasRealizadas;       // Troca valores v[i] ↔ v[j] */
                vetorUc[j].quantAulasRealizadas = vetorUc[i].quantAulasRealizadas;
                vetorUc[i].quantAulasRealizadas = aux;
            }
        }
    }
}

void UcMenorAulasRealizadas(tipoUc vetorUc[], int numTotalUc){
    int i, dados=3, contadorT=0, contadorP=0, contadorTP=0;

    ordenaPosAulasRealizadas(vetorUc, numTotalUc);

    if(numTotalUc == 0){
        printf("Nao existem unidades curriculares");
    } else{
        if(numTotalUc < 3){
            dados=numTotalUc;
        }
         for (i=0; i<dados; i++) {
            printf("\t\tCodigo: %d", vetorUc[i].codigo);
            printf("\n\t\tDesignacao: %s", vetorUc[i].designacao);
            printf("\n\t\tTipo de Aula: ");
                if( (strcmp(vetorUc[i].tipoAula, "T")==0) || (strcmp(vetorUc[i].tipoAula, "t")==0) ){
                    printf("Teorico");
                } else {
                    if( (strcmp(vetorUc[i].tipoAula, "P")==0) || (strcmp(vetorUc[i].tipoAula, "p")==0) ){
                        printf("Prático");
                    } else{
                        if( (strcmp(vetorUc[i].tipoAula, "TP")==0) || (strcmp(vetorUc[i].tipoAula, "tp")==0) ) {
                        printf("Prático Laboratorial");
                        }
                    }
                }
            printf("\n\t\tAulas Realizadas: %d\n\n", vetorUc[i].quantAulasRealizadas);
        }
    }
}


void ordenaAulaTipo(tipoUc vetorUc[], int numTotalUc){
    int i, j, troca=1;
    char aux[50];

    for(i=0; i <numTotalUc-1 && troca!=0; i++){
        troca=0;
        for (j= 0; j < numTotalUc-i-1; j++){
            if(strcmp(vetorUc[j+1].tipoAula ,vetorUc[j].tipoAula ) < 0){ /* > para decrescente */
                troca=1; /* se elemento seguinte inferior */
                strcpy(aux,vetorUc[j].tipoAula ); /* efetua a troca */
                strcpy(vetorUc[j].tipoAula ,vetorUc[j+1].tipoAula );
                strcpy(vetorUc[j+1].tipoAula ,aux);
            }
        }
    }
}


void tipoAulasMaiorAcessoGravacoes(tipoUc vetorUc[], int numTotalUc){
    ordenaAulaTipo(vetorUc, numTotalUc);
    printf("\n\t\tO tipo de aula com maior quantidade de acessos e o:" );
    if( (strcmp(vetorUc->tipoAula, "T")==0) || (strcmp(vetorUc->tipoAula, "t")==0) ){
        printf("teorico");
    } else {
        if( (strcmp(vetorUc->tipoAula, "P")==0) || (strcmp(vetorUc->tipoAula, "p")==0) ){
            printf("prático");
        } else{
            if( (strcmp(vetorUc->tipoAula, "TP")==0) || (strcmp(vetorUc->tipoAula, "tp")==0) ) {
            printf("prático laboratorial");
            }
        }
    }
}

void ordenarMaiorAcessoGravacoes(tipoUc vetorUc[], int numTotalUc){
    int i, j, aux;  //j elementos a comparar

    for(i=0; i < numTotalUc-1; i++) {        //Percorre vetor
        for (j= i+1; j<numTotalUc; j++) {
            if( vetorUc[j].quantAcessosGravacoes > vetorUc[i].quantAcessosGravacoes ){        // para ordenacao decrescente
                aux = vetorUc[j].quantAcessosGravacoes;       // Troca valores v[i] ↔ v[j] */
                vetorUc[j].quantAcessosGravacoes = vetorUc[i].quantAcessosGravacoes;
                vetorUc[i].quantAcessosGravacoes = aux;
            }
        }
    }
}


void rakingUcGravacoes(tipoUc vetorUc[], int numTotalUc){
    int i;

    ordenarMaiorAcessoGravacoes(vetorUc, numTotalUc);
    for (i=0; i<numTotalUc; i++) {
        printf("\t\tCodigo: %d", vetorUc[i].codigo);
        printf("\n\t\tDesignacao: %s", vetorUc[i].designacao);
        printf("\n\t\tTipo Aula: %s", vetorUc[i].tipoAula);
        printf("\n\t\tAcesso a  gravacao: %d \n\n", vetorUc[i].quantAcessosGravacoes);
    }
}


/*
void quantidadeAulasOnline(tipoAula vAulas[], int numTotalAulas){
    int contador=0, maior=0, conta=0;
    int i, j;

    if(numTotalAulas==0){
        printf("\n\nNão existem aulas agendadas.");
    } else {
        for(i=0; i<numTotalAulas; i++){
            contador=0;
            for(j=0; j<numTotalAulas; j++){
                if(vAulas[i].codigo == vAulas[j].codigo){
                    contador++;
                    maior = vAulas[j].codigo;
                }
            }
        }


        printf("\n\n\t A disciplina com mais aulas online é: %d \n", maior);
        for(i=0; i<numTotalAulas; i++){
            if(vAulas[i].codigo == maior){
                escreveDadosAulas(vAulas[i]);
                //printf("nome aula -> %s",vAulas[i].designacao);
                conta++;
            }
        }
    }
}
*/

/*
void quantidadeAulasRealizadasUc(tipoUc vetorUc[],int numTotalUc,int quantAulasRealizadas){

   int i,j,k,n,aux,aux2, numTotalUc2;
    numTotalUc2 = numTotalUc;

    if(numTotalUc == 0){
        printf("\n\n\tNão existem dados referentes às Unidades Curriculares.\n");
    }
    else{
        if(quantAulasRealizadas < 3){
            printf("\n\n\tNão tem dados suficientes para efetuar a quantidade maior e menor de aulas realizadas.");
            printf("Precisa de, no mínimo, ter 3 aulas realizadas.\n");
        }
        else{

            //calcula o maior
            for(i=0;i<numTotalUc-1;i++){
                for(j=i+1;j<numTotalUc; j++){
                    if(vetorUc[i].quantAulasRealizadas < vetorUc[j].quantAulasRealizadas){
                        aux = vetorUc[j].quantAulasRealizadas;
                        vetorUc[j].quantAulasRealizadas = vetorUc[i].quantAulasRealizadas;
                        vetorUc[i].quantAulasRealizadas = aux;
                    }
                }
            }

            printf("\n\n\tAs primeiras UCs com maior quantidade de aulas realizadas são:\n\n");
            for(i=0;i<3;i++){
                printf("\tA UC de %s com um total de %d aula(s).\n", vetorUc[i].designacao, vetorUc[i].quantAulasRealizadas);
            }

            //calcula o menor
            for(k=0;k<numTotalUc2-1;k++){
                for(n=k+1; n<numTotalUc2; n++){
                    if(vetorUc[k].quantAulasRealizadas > vetorUc[n].quantAulasRealizadas){
                        aux2 = vetorUc[n].quantAulasRealizadas;
                        vetorUc[n].quantAulasRealizadas = vetorUc[k].quantAulasRealizadas;
                        vetorUc[k].quantAulasRealizadas = aux2;
                    }
                }
            }

            printf("\n\tAs primeiras UCs com menor quantidade de aulas realizadas são:\n\n");
            for(k=0;k<3;k++){
                printf("\tA UC de %s com apenas %d aula(s).\n", vetorUc[k].designacao, vetorUc[k].quantAulasRealizadas);
            }

        }

    }
}
*/












void aulasRealizadasAntigas(tipoAula vAulas[], int numTotalAulas){
/*
    int i,j,aux;
    int *pdata1=NULL, *pdata2=NULL;

    if(numTotalAulas == 0){
        printf("Não existem dados referentes às Aulas Online.\n");
    }
    else{

        for(i=0;i<numTotalAulas;i++){
            for(j=i+1; j<numTotalAulas; j++){

                pdata1 = &vAulas[i].data;
                pdata2 = &vAulas[j].data;

                if(pdata1 > pdata2){
                    aux = pdata2;
                    *pdata2 = *pdata1;
                    *pdata1 = aux;
                }
            }

        }

        //foi usado ponteiros para guardar a posição don vetor
        printf("\n\tA aula realizada à mais tempo é:\n");
        printf("\tA aula de %s",vAulas[*pdata1].designacao);
        printf(" com a data: %d/%d/%d\n",vAulas[*pdata1].data.dia, vAulas[*pdata1].data.mes,vAulas[*pdata1].data.ano);

    }
*/
}


/*
void percentagemUcAulasGravadas(tipoAula vAulas[], int numTotalAulas, int quantAulasGravadas, tipoUc vetorUc[], int numTotalUc){

    int i, conta=0, media=0;
    float percentagem;

       if(numTotalUc == 0){
        printf("Não existem UC\n");
    }
    else{

        for (i=0; i<numTotalUc; i++){
            if(vetorUc[i].codigo == vAulas[i].codigo){

                if (strcmp(vAulas[i].gravacao, "S") == 0){
                    conta++;
                    printf("\n\tOpcao garvacao-> %s de %d aulas da UC %s\n", vAulas[i].gravacao,conta,vetorUc[i].designacao);
                }

            }
                printf("\n\tOpcao garvacao-> %s de %d aulas da UC %s\n", vAulas[i].gravacao,conta,vetorUc[i].designacao);
                percentagem = (conta/quantAulasGravadas)*100;
                printf("\n\tPercetagem: %.2f da UC %s\n", percentagem,vetorUc[i].designacao);

        }
    }

    percentagem = (numTotalUc/quantAulasGravadas)*100;

    printf("\n\tEm cada Aula à uma média de: %.2f presenças\n", media);
}
*/
