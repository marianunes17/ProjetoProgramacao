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

    vAulasAssistidas->numEstudante = numeroEstudante; //passar o numero de estudante e não a posição
    strcpy (vAulasAssistidas->designacaoAula, designacao);
    strcpy (vAulasAssistidas->tipoAcesso, acesso);

    (*numAulasAssistidas)++;

    printf("Aul: %d", *numAulasAssistidas);
    printf("\n\tFoi acrescentado um novo Estudante à Aula");
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


void assistirAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int *numAulasAssistidas){
   int posicaoAula, posicaoEstudante, numeroEstudante;
   char acesso[12];
   strcpy(acesso, "aula");

    if(numTotalAulas == 0 ){
        printf("Não existem Aulas. \n");
    } else {
        posicaoAula=procuraAulaNome(vAulas, numTotalAulas,  designacaoAula);
        if(posicaoAula == -1){
            printf ("A designação da aula não existe");
        } else {
            if(strcmp(vAulas[posicaoAula].estadoAula, "A decorrer")==0){
                numeroEstudante=lerInteiro("\tNumero de Estudante: ",1000,2000);

                posicaoEstudante = procuraEstudante(vEstudante, numTotalEstudantes, numeroEstudante);

                if(posicaoEstudante == -1){
                    printf ("O numero de estudante inserido não existe");

                } else {
                    printf ("Está a assitir à aula de %s", designacaoAula);

                    vAulas[posicaoAula].numeroEstudante = vEstudante[posicaoAula].numeroEstudante; // para que serve

                    acrescentaAulaAssistida(vAulasAssistidas, numeroEstudante, designacaoAula, acesso, &(*numAulasAssistidas));
                }
            } else{
                printf("A aula não esta a decorrer");
            }
        }
           gravaAulasEstudantesTxt(vEstudante, numTotalEstudantes, posicaoEstudante, vAulas, numTotalAulas, posicaoAula);
    }
}

void assistirGravacaoAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int *numAulasAssistidas){
   int posicaoAula, posicaoEstudante, numeroEstudante;
   char acesso[] = "gravacao";

    if(numTotalAulas == 0 ){
        printf("Não existem Aulas. \n");
    } else {
        posicaoAula=procuraAulaNome(vAulas, numTotalAulas, designacaoAula);
        if(posicaoAula == -1){
            printf ("A designação da aula não existe");
        } else {
           if( (strcmp(vAulas[posicaoAula].estadoAula, "Realizada")==0) ){ //já nao é teminada
               if (strcmp(vAulas[posicaoAula].gravacao,"S") == 0) {
                    numeroEstudante=lerInteiro("\tNumero de Estudante: ",1000,2000);
                    posicaoEstudante = procuraEstudante(vEstudante, numTotalEstudantes, numeroEstudante);

                    if(posicaoEstudante == -1){
                        printf ("O numero de estudante inserido não existe");

                    } else {
                        printf ("Está a assitir à gravação da aula de %s", designacaoAula);
                        acrescentaAulaAssistida(vAulasAssistidas, numeroEstudante, designacaoAula, acesso, &(*numAulasAssistidas));
                    }
                } else{
                    printf("A aula não foi gravada");
                }
            } else {
                printf("A aula não esta terminada");
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
            printf("\tHora: %d:%d às",vAulas[i].hora.h,vAulas[i].hora.m);
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


void gravaAulasEstudantesBin(tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAula[], int numTotalAulas){
    FILE *ficheiro;
    int erro;

    ficheiro=fopen("infoAulasEstudante.dat", "wb");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        fwrite(&numTotalEstudantes,sizeof(int),1,ficheiro);
        fwrite(vEstudante,sizeof(tipoEstudante),numTotalEstudantes,ficheiro);

        fwrite(&numTotalAulas,sizeof(int),1,ficheiro);   //acho que não é necessario repetir codigo
        fwrite(vAula,sizeof(tipoAula),numTotalAulas,ficheiro);

        //fclose(ficheiro);
        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d ao fechar ficheiro", erro);
        }
    }
}


void leAulasEstudantesBin(tipoEstudante vEstudante[], int *numTotalEstudantes, tipoAula vAula[], int *numTotalAulas){
    FILE *ficheiro;
    int erro;

    ficheiro=fopen("infoAulasEstudante.dat", "rb");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        fread(&(*numTotalEstudantes),sizeof(int),1,ficheiro);
        fread(vEstudante,sizeof(tipoEstudante),*numTotalEstudantes,ficheiro);

        fread(&(*numTotalAulas),sizeof(int),1,ficheiro);   //acho que não é necessario repetir codigo
        fread(vAula,sizeof(tipoEstudante),*numTotalAulas,ficheiro);

        //fclose(ficheiro);
        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d ao fechar ficheiro", erro);
        }
    }
}


void gravaAulasEstudantesTxt(tipoEstudante vEstudante[], int numTotalEstudantes, int numEstudante, tipoAula vAula[], int numTotalAulas, int posicaoAula){
        FILE *ficheiro;
        int i,j;

        ficheiro=fopen("infoAulasEstudante.txt", "a+");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{

                fprintf(ficheiro, "Nome estudante: %d\n", vEstudante[numEstudante].numeroEstudante);
                fprintf(ficheiro, "Numero: %s\n\n", vEstudante[numEstudante].nome);



                  //  fprintf(ficheiro,"Designacao %s", vAula[posicaoAula].designacao);
                    fprintf(ficheiro,"Data: %d\t",vAula[posicaoAula].data.dia);
                    fprintf(ficheiro,"%d\t",vAula[posicaoAula].data.mes);
                    fprintf(ficheiro,"%d\n",vAula[posicaoAula].data.ano);
                    fprintf(ficheiro,"Hora de Inicio: %d:%d\n",vAula[posicaoAula].hora.h,vAula[posicaoAula].hora.m);
                    fprintf(ficheiro,"Hora de Fim: %d:%d\n\n",vAula[posicaoAula].horaFim,vAula[posicaoAula].minFim);


            fclose(ficheiro);
            }

}
