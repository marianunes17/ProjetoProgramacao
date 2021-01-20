#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_aulas.h"
#include "funcoes_uc.h"
#include "funcoes_menus.h"


tipoEstudante leDadosEstudante(int numeroEstudante){
    tipoEstudante vEstudante;

    vEstudante.numeroEstudante = numeroEstudante;

    lerString("\tNome: ", vEstudante.nome,MAX_STRING);

    do{
        lerString("\tRegime (D,PL): ", vEstudante.regime,3);
    } while( strcmp(vEstudante.regime, "D") && strcmp(vEstudante.regime, "d") && strcmp(vEstudante.regime, "PL") && strcmp(vEstudante.regime, "pl"));
    //strcmp - Compara se a string regime é igual a D/pl

    return vEstudante;
}

void escreveDadosEstudante(tipoEstudante vEstudante){
    printf("\n\tNumero de Estudante: %d", vEstudante.numeroEstudante);
    printf("\n\tNome: %s", vEstudante.nome);
    printf("\n\tRegime(D,PL): %s\n", vEstudante.regime);
}


void listaDadosEstudante(tipoEstudante vEstudante[MAX_ESTUDANTES], int numTotalEstudantes){
    int i;

    if (numTotalEstudantes==0) {
        printf("\n\t Não existem estudantes.");
    }
    else {
        for (i=0; i<numTotalEstudantes; i++) {
            escreveDadosEstudante(vEstudante[i]);
        }
    }
}


int procuraEstudante(tipoEstudante vEstudante[], int numTotalEstudantes, int numEstudante){
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



void gravarEstudantesTexto(tipoEstudante vEstudante[], int numTotalEstudante){
     FILE *ficheiro;
        int i;

        ficheiro=fopen("infoEstudante.txt", "a");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fprintf(ficheiro, "Estudantes:%d\n", numTotalEstudante);

            for(i=0; i<numTotalEstudante; i++){
                fprintf(ficheiro, "\nNumero Estudante: %d", vEstudante[i].numeroEstudante);
                fprintf(ficheiro, "\nNome: %s", vEstudante[i].nome);
                fprintf(ficheiro, "\nRegime: %s\n", vEstudante[i].regime);
            }
            fclose(ficheiro);
        }
}


void gravarEstudantesBinario(tipoEstudante vEstudante[], int numTotalEstudante){
     FILE *ficheiro;

        ficheiro=fopen("infoEstudante.dat", "wb");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fwrite(&numTotalEstudante,sizeof(int),1,ficheiro);
            fwrite(vEstudante,sizeof(tipoEstudante),numTotalEstudante,ficheiro);
            fclose(ficheiro);
        }
}

void leEstudantesTexto(tipoEstudante vEstudante[], int *numTotalEstudante){
    FILE *ficheiro;
    int i;

        ficheiro=fopen("infoEstudante.txt", "r");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            for(i=0; i<*numTotalEstudante; i++){
                fscanf(ficheiro, "%d", vEstudante[i].numeroEstudante);
                fgets(vEstudante[i].nome,100,ficheiro);
                fgets(vEstudante[i].regime,3,ficheiro);
            }
            fclose(ficheiro);
        }
}



void leEstudantesBinario(tipoEstudante vEstudante[], int *numTotalEstudante){
    FILE *ficheiro;

        ficheiro=fopen("infoEstudante.dat", "rb");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fread(&(*numTotalEstudante),sizeof(int),1,ficheiro);
            fread(vEstudante,sizeof(tipoEstudante),*numTotalEstudante,ficheiro);

            fclose(ficheiro);
        }
}


void acrescentaEstudante(tipoEstudante vEstudante[], int *numTotalEstudantes, int numeroEstudante){
    tipoEstudante dados;
    int posicao;

    if (*numTotalEstudantes == MAX_ESTUDANTES){
        printf("\tImpossível acrescentar um novo estudante. O numero maximo de estudantes é de: %d", MAX_ESTUDANTES);
    } else{
        posicao=procuraEstudante(vEstudante, *numTotalEstudantes, numeroEstudante);

        if(posicao!=-1){
            printf("\tO estudante já existe.");
        } else {
            dados=leDadosEstudante(numeroEstudante);
            vEstudante[*numTotalEstudantes]=dados;
            (*numTotalEstudantes)++;
             printf("\n\tFoi acrescentado um novo Estudante");
        }
    }
}


void alterarVetorEstudante(tipoEstudante vEstudante[], int numTotalEstudantes){
    int posicao, numeroEstudante;
    char opcao;

    if(numTotalEstudantes == 0 ){
        printf("\tNão existem Alunos. \n");
    }
    else{
        numeroEstudante=lerInteiro("\tNúmero de Estudante: ", 1, 100);
         posicao=procuraEstudante(vEstudante, numTotalEstudantes, numeroEstudante);
        if(posicao==-1){
                printf("\tO numero nao existe.");
        } else{
            if (vEstudante[posicao].numeroEstudante == numeroEstudante){
                do{
                    opcao=subMenuAlteraEstudante();
                    switch(opcao){
                        case 'A':
                                 lerString("Nome: ", vEstudante[posicao].nome,MAX_STRING);
                                 break;
                        case 'B':
                                do{
                                    lerString("\tRegime (D,PL): ", vEstudante[posicao].regime,3);
                                } while( strcmp(vEstudante[posicao].regime, "D") && strcmp(vEstudante[posicao].regime, "d") && strcmp(vEstudante[posicao].regime, "PL") && strcmp(vEstudante[posicao].regime, "pl"));
                                break;
                        case 'V':
                                printf("Voltar");
                                break;
                        default: printf("Opção Invalida.");
                    }
                } while(opcao!='V');

            }
            printf("\n\tOs dados do estudante foram alterado.");
        }
    }
}


void eliminarEstudante(tipoEstudante vEstudante[], int *numTotalEstudantes){
    int posicao, numeroEstudante;

    if(*numTotalEstudantes == 0 ){
        printf("\tNão existem Unidades Curriculares. \n");
    }
    else{
        numeroEstudante=lerInteiro("\tNumero de Estudante: ", 1,100 );
        posicao=procuraEstudante(vEstudante,*numTotalEstudantes, numeroEstudante);
        if(posicao==-1){
            printf("\tA Unidade Curricular não existe. \n");
        } else {
            vEstudante[posicao]=vEstudante[posicao+1];
        }

        (*numTotalEstudantes)--;
        printf("\n\tO estudante foi eliminada");
    }
}



void gravaAulasEstudantesBin(tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAula[], int numTotalAulas){
 FILE *ficheiro;

        ficheiro=fopen("infoAulasEstudante.dat", "wb");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fwrite(&numTotalEstudantes,sizeof(int),1,ficheiro);
            fwrite(vEstudante,sizeof(tipoEstudante),numTotalEstudantes,ficheiro);

            fwrite(&numTotalAulas,sizeof(int),1,ficheiro);
            fwrite(vAula,sizeof(tipoAula),numTotalAulas,ficheiro);
            fclose(ficheiro);
        }
}


void leAulasEstudantesBin(tipoEstudante vEstudante[], int *numTotalEstudantes, tipoAula vAula[], int *numTotalAulas){
 FILE *ficheiro;

    ficheiro=fopen("infoAulasEstudante.dat", "rb");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        fread(&(*numTotalEstudantes),sizeof(int),1,ficheiro);
        fread(vEstudante,sizeof(tipoEstudante),*numTotalEstudantes,ficheiro);

        fread(&(*numTotalAulas),sizeof(int),1,ficheiro);
        fread(vAula,sizeof(tipoEstudante),*numTotalAulas,ficheiro);

        fclose(ficheiro);
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





void assistirAula(tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[]){
   int posicaoAula, posicaoEstudante, numeroEstudante;

    if(numTotalAulas == 0 ){
        printf("Não existem Aulas. \n");
    } else {
        posicaoAula=procuraAulaNome(vAulas, numTotalAulas, designacaoAula);
        if(posicaoAula == -1){
            printf ("A designação da aula não existe");
        } else {
            if(strcmp(vAulas[posicaoAula].estadoAula, "A decorrer")==0){
                numeroEstudante=lerInteiro("\tNumero de Estudante: ",1,100);

                posicaoEstudante = procuraEstudante(vEstudante, numTotalEstudantes, numeroEstudante);

                if(posicaoEstudante == -1){
                    printf ("O numero de estudante inserido não existe");

                } else {
                    printf ("Está a assitir à aula de %s", designacaoAula);
                }
            } else{
                printf("A aula não esta a decorrer");
            }
        }
           gravaAulasEstudantesTxt(vEstudante, numTotalEstudantes, posicaoEstudante, vAulas, numTotalAulas, posicaoAula);
    }
}

void assistirGravacaoAula(tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[]){
   int posicaoAula, posicaoEstudante, numeroEstudante;

    if(numTotalAulas == 0 ){
        printf("Não existem Aulas. \n");
    } else {
        posicaoAula=procuraAulaNome(vAulas, numTotalAulas, designacaoAula);
        if(posicaoAula == -1){
            printf ("A designação da aula não existe");
        } else {
           if( (strcmp(vAulas[posicaoAula].estadoAula, "Terminada")==0) ){
               if (strcmp(vAulas[posicaoAula].gravacao,"Sim") == 0) {
                    numeroEstudante=lerInteiro("\tNumero de Estudante: ",1,100);
                    posicaoEstudante = procuraEstudante(vEstudante, numTotalEstudantes, numeroEstudante);

                    if(posicaoEstudante == -1){
                        printf ("O numero de estudante inserido não existe");

                    } else {
                        printf ("Está a assitir à gravação da aula de %s", designacaoAula);
                        gravaAulasEstudantesTxt(vEstudante, numTotalEstudantes, posicaoEstudante, vAulas, numTotalAulas, posicaoAula);
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

