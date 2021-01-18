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



void escreveDadosEstudante(tipoEstudante vEstudante){
    printf("\n\tNumero de Estudante: %d", vEstudante.numeroEstudante);
    printf("\n\tNome: %s", vEstudante.nome);
    printf("\n\tRegime(D,PL): %s\n", vEstudante.regime);
}

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


int procuraEstudante(tipoEstudante vEstudante[], int numTotalEstudantes, int numeroEstudante){
    int i, posicao;
    posicao = -1;

    for (i=0; i<numTotalEstudantes; i++){
        if (vEstudante[i].numeroEstudante == numeroEstudante){
            posicao = i;
            i = numTotalEstudantes;
        }
    }
    return posicao;
}



void gravarEstudantesTexto(tipoEstudante vEstudante[], int numTotalEstudante){
     FILE *ficheiro;
        int i;

        ficheiro=fopen("infoEstudante.txt", "a+");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fprintf(ficheiro, "%d", numTotalEstudante);

            for(i=0; i<=numTotalEstudante; i++){
                fprintf(ficheiro, "\n %d", vEstudante[i].numeroEstudante);
                fprintf(ficheiro, "\n %s", vEstudante[i].nome);
                fprintf(ficheiro, "\n %s", vEstudante[i].regime);
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
            for(i=0; i<=*numTotalEstudante; i++){
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

            gravarEstudantesBinario(vEstudante, *numTotalEstudantes);
            gravarEstudantesTexto(vEstudante, *numTotalEstudantes);
             printf("\n\tFoi acrescentada um nova Estudante");
        }
    }
}


void alterarVetorEstudante(tipoEstudante vEstudante[], int numTotalEstudantes){
    int i, posicao, numeroEstudante;
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
             for (i=0; i<numTotalEstudantes; i++){
                if (vEstudante[i].numeroEstudante == numeroEstudante){
                    do{
                        opcao=subMenuAlteraEstudante();
                        switch(opcao){
                            case 'A':
                                     lerString("Nome: ", vEstudante[i].nome,MAX_STRING);
                                     break;
                            case 'B':
                                    do{
                                        lerString("\tRegime (D,PL): ", vEstudante[i].regime,3);
                                    } while( strcmp(vEstudante[i].regime, "D") && strcmp(vEstudante[i].regime, "d") && strcmp(vEstudante[i].regime, "PL") && strcmp(vEstudante[i].regime, "pl"));
                                    break;
                            case 'V':
                                    printf("Voltar");
                                    break;
                            default: printf("Opção Invalida.");
                        }
                    } while(opcao!='V');

            gravarEstudantesBinario(vEstudante, numTotalEstudantes);
            gravarEstudantesTexto(vEstudante, numTotalEstudantes);
                }
            }
        }
        printf("\n\tOs dados do estudante foram alterado.");
    }
}


void eliminarEstudante(tipoEstudante vEstudante[], int *numTotalEstudantes){
    int i, posicao, numeroEstudante;

    if(*numTotalEstudantes == 0 ){
        printf("\tNão existem Unidades Curriculares. \n");
    }
    else{
        numeroEstudante=lerInteiro("\tNumero de Estudante: ", 1,100 );
        posicao=procuraEstudante(vEstudante,*numTotalEstudantes, numeroEstudante);
        if(posicao==-1){
            printf("\tA Unidade Curricular não existe. \n");
        }
        else {
            for(i=posicao; i<*numTotalEstudantes-1; i++){
                vEstudante[i]=vEstudante[i+1];
            }
            (*numTotalEstudantes)--;

            gravarEstudantesBinario(vEstudante, *numTotalEstudantes);
            gravarEstudantesTexto(vEstudante, *numTotalEstudantes);

            printf("\n\tO estudante foi eliminada");
        }
    }
}



void gravaAulasEstudantesBin(tipoEstudante vEstudante[], int *numTotalEstudantes, tipoAula vAula[], int *numTotalAulas){
 FILE *ficheiro;

        ficheiro=fopen("infoAulasEstudante.dat", "wb");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fwrite(&(*numTotalEstudantes),sizeof(int),1,ficheiro);
            fwrite(vEstudante,sizeof(tipoEstudante),*numTotalEstudantes,ficheiro);

            fwrite(&(*numTotalAulas),sizeof(int),1,ficheiro);
            fwrite(vAula,sizeof(tipoAula),*numTotalAulas,ficheiro);
            fclose(ficheiro);
        }
}


void leAulasEstudantesBin(tipoEstudante vEstudante[], int *numTotalEstudantes, tipoAula vAula[], int *numTotalAulas){
 FILE *ficheiro;

    ficheiro=fopen("infoEstudante.dat", "rb");
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


void GravaAulasEstudantesTxt(tipoEstudante vEstudante[], int *numTotalEstudantes, tipoAula vAula[], int *numTotalAulas){

     FILE *ficheiro;
        int i,j;

        ficheiro=fopen("infoEstudante.txt", "a+");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fprintf(ficheiro, "%d", *numTotalEstudantes);
            fprintf(ficheiro, "%d", *numTotalAulas);

            for(i=0; i<=*numTotalEstudantes; i++){
                fprintf(ficheiro, "\n %d", vEstudante[i].numeroEstudante);
                fprintf(ficheiro, "\n %s", vEstudante[i].nome);
            }
            for(j=0; j<=*numTotalAulas; i++){
                fprintf(ficheiro, "\n %d", vAula[i].codigo);
                fprintf(ficheiro, "\n %s", vAula[i].designacao);
                fprintf(ficheiro, "\n %d", vAula[i].data.dia);
                fprintf(ficheiro, "\n %d", vAula[i].data.mes);
                fprintf(ficheiro, "\n %d", vAula[i].data.ano);
                fprintf(ficheiro, "\n %d", vAula[i].hora.h);
                fprintf(ficheiro, "\n %d", vAula[i].hora.m);
            }


            fclose(ficheiro);
        }
}

void leAulasEstudantesTxt(tipoEstudante vEstudante[], int *numTotalEstudantes, tipoAula vAula[], int *numTotalAulas){
 FILE *ficheiro;
    int i, j;

        ficheiro=fopen("infoAulasEstudantes.txt", "r");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            for(i=0; i<=*numTotalEstudantes; i++){
                fscanf(ficheiro, "%d", vEstudante[i].numeroEstudante);
                fgets(vEstudante[i].nome,100,ficheiro);
            }

            for(j=0; j<=*numTotalAulas; j++){
                fscanf(ficheiro, "%d", vAula[i].codigo);
                fgets(vAula[i].designacao,100,ficheiro);
                fscanf(ficheiro, "%d", vAula[i].data.dia);
                fscanf(ficheiro, "%d", vAula[i].data.mes);
                fscanf(ficheiro, "%d", vAula[i].data.ano);
                fscanf(ficheiro, "%d", vAula[i].hora.h);
                fscanf(ficheiro, "%d", vAula[i].hora.m);
            }


            fclose(ficheiro);
        }
}


void assistirAula(tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[]){
    int posicao, i;
    tipoEstudante info;

    if(numTotalAulas == 0 ){
        printf("Não existem Aulas. \n");
    }else{
        if(numTotalAulas == MAX_ESTUDANTES){
            printf("\tImpossível aceder à aula online. O máximo de estudantes é de: %d", MAX_ESTUDANTES);

        } else{
            posicao=procuraAulaNome(vAulas, numTotalAulas, designacaoAula);
            if(posicao == -1){
                printf ("Aula nao está agendada");
            }
            else{
                for(i=0; i<numTotalAulas; i++){
                        gravaAulasEstudantesBin(vEstudante, &numTotalEstudantes, vAulas, &numTotalAulas);
                    }
                }
            }
        }
    }

