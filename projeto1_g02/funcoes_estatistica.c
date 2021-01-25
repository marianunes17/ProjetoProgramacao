#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_uc.h"
#include "funcoes_aulas.h"
#include "funcoes_estudantes.h"
#include "funcoes_menus.h"


void quantidadeAulasOnline(tipoAula vAulas[], int numTotalAulas){
    int contador=0, maior=0, conta=0;
    int i, j;

    if(numTotalAulas==0){
        printf("\nNão existem aulas agendadas.");
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


        printf("\n\t A disciplina com mais aulas online é: %d \n", maior);
        for(i=0; i<numTotalAulas; i++){
            if(vAulas[i].codigo == maior){
                escreveDadosAulas(vAulas[i]);
                //printf("nome aula -> %s",vAulas[i].designacao);
                conta++;
            }
        }
    }
}

void quantidadeAulasRealizadasUc(tipoUc vetorUc[],int numTotalUc){

    int i,j,k,n,aux,aux2;

    if(numTotalUc == 0){
        printf("Não existem dados referentes às Unidades Curriculares.\n");
    }
    else{
        //calcula o maior
        for(i=0;i<numTotalUc;i++){
            for(j = i+1; j<numTotalUc; j++){
                if(vetorUc[i].quantAulasRealizadas < vetorUc[j].quantAulasRealizadas){
                    aux = vetorUc[j].quantAulasRealizadas;
                    vetorUc[j].quantAulasRealizadas = vetorUc[i].quantAulasRealizadas;
                    vetorUc[i].quantAulasRealizadas = aux;
                }
            }

        }

        //calcula o menor
        for(k=0;k<numTotalUc;k++){
            for(n = k+1; n<numTotalUc; n++){
                if(vetorUc[k].quantAulasRealizadas > vetorUc[n].quantAulasRealizadas){
                    aux2 = vetorUc[n].quantAulasRealizadas;
                    vetorUc[n].quantAulasRealizadas = vetorUc[k].quantAulasRealizadas;
                    vetorUc[k].quantAulasRealizadas = aux2;
                }
            }

        }


        printf("\n\t As 3 primeiras UC com quantidade maior de aula realizadas são:\n\n");
        for(i=0;i<3;i++){
            printf("\tA UC de %s com um total de %d \n", vetorUc[i].designacao, vetorUc[i].quantAulasRealizadas);
        }

        printf("\n\t e as 3  UC com quantidade menor de aula realizadas são:\n\n");
        for(k=0;k<3;k++){
            printf("\tA UC de %s com apenas %d aula\n", vetorUc[k].designacao, vetorUc[k].quantAulasRealizadas);
        }
    }


}


void mediaPresencasAulas(tipoAula vAulas[], int numAulas, int numTotalAulasAssistidas){
   /* int conta=0, media, i;
    printf("\nnumTotalAulasAssistidas: %d\n", numTotalAulasAssistidas);

     for (i=0; i<numAulas; i++){
        if (strcmp(vAulas[i].estadoAula, "Realizada") == 0){
            conta++;
        }
    }

    media = (numTotalAulasAssistidas/conta);

    printf("\nnumTotalAulasAssistidas: %d\n", numTotalAulasAssistidas);
    printf("conta: %d\n", conta);
    printf("A media de presenças é de: %d\n", media);
    */
}


void aulasRealizadasAntigas(tipoAula vAulas[], int numTotalAulas){
/*
    int i,j,aux;
    int *pdata1=NULL, *pdata2=NULL;

    if(numTotalAulas == 0){

        for(i=0;i<numTotalAulas;i++){
            for(j = i+1; j<numTotalAulas; j++){

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
        printf("\t%s",vAulas[*pdata1].designacao);
        printf(" com a data: %d/%d/%d\n",vAulas[*pdata1].data.dia, vAulas[*pdata1].data.mes,vAulas[*pdata1].data.ano);


    }else{
        printf("Não existem dados referentes às Aulas Online.\n");
    }
*/
}

void percentagemUcAulasGravadas(tipoAula vAulas[], int numTotalAulas, int quantAulasGravadas, tipoUc vetorUc[], int numTotalUc){
/*
    int i, conta=0;
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

    //percentagem = (numTotalUc/quantAulasGravadas)*100;

    //printf("\n\tEm cada Aula à uma média de: %.2f presenças\n", media);
*/

}
