#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_aulas.h"
#include "funcoes_uc.h"
#include "funcoes_estudantes.h"
#include "funcoes_menus.h"


void escreveDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas){
    printf("\n\tNumero de Estudante: %d", vAulasAssistidas.numEstudante );
    printf("\n\tDesignacao da Aula: %s", vAulasAssistidas.designacaoAula);
    printf("\n\tTipo de acesso: %s\n", vAulasAssistidas.tipoAcesso);
}


void listaDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas[MAX_ESTUDANTES], int numAulasAssistidas){
    int i;
    for (i=0; i<numAulasAssistidas; i++) {
        escreveDadosAulasAssistidas(vAulasAssistidas[i]);
    }
}

void acrescentaAulaAssistida(tipoAulasAssistidas vAulasAssistidas[MAX_ESTUDANTES], int numeroEstudante, char designacao[], char acesso[], int *numAulasAssistidas){

    vAulasAssistidas->numEstudante = numeroEstudante; //passar o numero de estudante e n�o a posi��o
    strcpy (vAulasAssistidas->designacaoAula, designacao);
    strcpy (vAulasAssistidas->tipoAcesso, acesso);

    (*numAulasAssistidas)++;

    printf("Aul: %d", *numAulasAssistidas);
    printf("\n\tFoi acrescentado um novo Estudante � Aula");
}



int procuraAulaAssistida(tipoEstudante vEstudante[], int numTotalEstudantes, int numEstudante){
    int i, posicao;
    posicao = -1;

    for (i=0; i<numTotalEstudantes; i++){
        if (vEstudante[i].numeroEstudante == numEstudante){
            posicao = i;
            i = numTotalEstudantes;
        }
    }
    return posicao;
}


void gravaAulasEstudantesBin(tipoAulasAssistidas vAulasAssistidas[], int numAulasAssistidas){
    FILE *ficheiro;
    int gravarDados;
    int erro;

    ficheiro=fopen("infoAulasEstudante.dat", "wb");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        fwrite(&numAulasAssistidas,sizeof(int),1,ficheiro);
        gravarDados=fwrite(vAulasAssistidas,sizeof(tipoAulasAssistidas),numAulasAssistidas,ficheiro);

        //fclose(ficheiro);
        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d ao fechar ficheiro", erro);
        }
    }
}


void leAulasEstudantesBin(tipoAulasAssistidas vAulasAssistidas[], int *numAulasAssistidas){
    FILE *ficheiro;

    ficheiro=fopen("infoEstudante.dat", "rb");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        fread(&(*numAulasAssistidas),sizeof(int),1,ficheiro);
        fread(vAulasAssistidas,sizeof(tipoAulasAssistidas),*numAulasAssistidas,ficheiro);

        fclose(ficheiro);
    }
}



void gravaAulasEstudantesTxt(tipoAulasAssistidas vAulasAssistidas[], int numAulasAssistidas){
    FILE *ficheiro;
    int i;

    ficheiro=fopen("infoAulasEstudante.txt", "a+");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        for(i=0; i<numAulasAssistidas; i++){
            fprintf(ficheiro, "Numero estudante: %d\n", vAulasAssistidas[i].numEstudante);
            fprintf(ficheiro, "Designacao Aula: %s\n\n", vAulasAssistidas[i].designacaoAula);
            fprintf(ficheiro, "Acesso: %s\n\n", vAulasAssistidas[i].tipoAcesso);
        }
        fclose(ficheiro);
    }
}

void leAulasEstudantesTxt(tipoAulasAssistidas vAulasAssistidas[], int *numAulasAssistidas){
    FILE *ficheiro;
    int i;

    ficheiro=fopen("infoAulasEstudante.txt", "r");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        for(i=0; i<*numAulasAssistidas; i++){
            fscanf(ficheiro, "%d", vAulasAssistidas[i].numEstudante);
            fgets(vAulasAssistidas[i].designacaoAula,100,ficheiro);
            fgets(vAulasAssistidas[i].tipoAcesso,3,ficheiro);
        }
        fclose(ficheiro);
    }
}


void assistirAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int *numAulasAssistidas){
   int posicaoAula, posicaoEstudante, numeroEstudante;
   char acesso[12];
   strcpy(acesso, "aula");

    if(numTotalAulas == 0 ){
        printf("N�o existem Aulas. \n");
    } else {
        posicaoAula=procuraAulaNome(vAulas, numTotalAulas,  designacaoAula);
        if(posicaoAula == -1){
            printf ("A designa��o da aula n�o existe");
        } else {
            if(strcmp(vAulas[posicaoAula].estadoAula, "A decorrer")==0){
                numeroEstudante=lerInteiro("\tNumero de Estudante: ",1000,2000);

                posicaoEstudante = procuraEstudante(vEstudante, numTotalEstudantes, numeroEstudante);

                if(posicaoEstudante == -1){
                    printf ("O numero de estudante inserido n�o existe");

                } else {
                    printf ("Est� a assitir � aula de %s", designacaoAula);


                    acrescentaAulaAssistida(vAulasAssistidas, numeroEstudante, designacaoAula, acesso, &(*numAulasAssistidas));

                    gravaAulasEstudantesTxt(vAulasAssistidas, *numAulasAssistidas);
                    gravaAulasEstudantesBin(vAulasAssistidas, *numAulasAssistidas);
                }
            } else{
                printf("A aula n�o esta a decorrer");
            }
        }
    }
}

void assistirGravacaoAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int *numAulasAssistidas){
   int posicaoAula, posicaoEstudante, numeroEstudante;
   char acesso[] = "gravacao";

    if(numTotalAulas == 0 ){
        printf("N�o existem Aulas. \n");
    } else {
        posicaoAula=procuraAulaNome(vAulas, numTotalAulas, designacaoAula);
        if(posicaoAula == -1){
            printf ("A designa��o da aula n�o existe");
        } else {
           if( (strcmp(vAulas[posicaoAula].estadoAula, "Realizada")==0) ){ //j� nao � teminada
               if (strcmp(vAulas[posicaoAula].gravacao,"S") == 0) {
                    numeroEstudante=lerInteiro("\tNumero de Estudante: ",1000,2000);
                    posicaoEstudante = procuraEstudante(vEstudante, numTotalEstudantes, numeroEstudante);

                    if(posicaoEstudante == -1){
                        printf ("O numero de estudante inserido n�o existe");

                    } else {
                        printf ("Est� a assitir � grava��o da aula de %s", designacaoAula);
                        acrescentaAulaAssistida(vAulasAssistidas, numeroEstudante, designacaoAula, acesso, &(*numAulasAssistidas));
                    }
                } else{
                    printf("A aula n�o foi gravada");
                }
            } else {
                printf("A aula n�o esta terminada");
            }
        }
    }
}



void listaAulasComGravacao(tipoAula vAulas[], int numAulas) {
    int i;

    for (i=0; i<numAulas; i++){
        if ((strcmp(vAulas[i].estadoAula, "Realizada") == 0) && (strcmp(vAulas[i].gravacao, "S") == 0)){

            printf("\n\tDescricao: %s\n",vAulas[i].designacao);
            printf("\tDocente: %s\n",vAulas[i].docente);
            printf("\tHora: %d:%d �s",vAulas[i].hora.h,vAulas[i].hora.m);
            printf(" %d:%d\n",vAulas[i].horaFim,vAulas[i].minFim);
            printf("\tData: %d/%d/%d\n",vAulas[i].data.dia, vAulas[i].data.mes,vAulas[i].data.ano);
            printf("\tEstado da Aula: %s\n",vAulas[i].estadoAula);
            printf("\tGravacao: " );
            if((strcmp(vAulas[i].gravacao, "S") == 0)){
                printf("Sim");
            }
            printf("\n\n");

            }
    }
}

