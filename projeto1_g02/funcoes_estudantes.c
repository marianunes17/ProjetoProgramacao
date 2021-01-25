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
        int i, erro;

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
            erro = fclose(ficheiro);
            if (erro != 0){
                printf ("Erro %d ao fechar ficheiro", erro);
            }
        }
}


void gravarEstudantesBinario(tipoEstudante vEstudante[], int numTotalEstudante){
     FILE *ficheiro;
     int erro;

        ficheiro=fopen("infoEstudante.dat", "wb");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fwrite(&numTotalEstudante,sizeof(int),1,ficheiro);
            fwrite(vEstudante,sizeof(tipoEstudante),numTotalEstudante,ficheiro);

            erro = fclose(ficheiro);
            if (erro != 0){
                printf ("Erro %d ao fechar ficheiro", erro);
            }
        }
}

void leEstudantesTexto(tipoEstudante vEstudante[], int *numTotalEstudante){
    FILE *ficheiro;
    int i, erro;

    ficheiro=fopen("infoEstudante.txt", "r");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        for(i=0; i<*numTotalEstudante; i++){
            fscanf(ficheiro, "%d", vEstudante[i].numeroEstudante);
            fgets(vEstudante[i].nome,100,ficheiro);
            fgets(vEstudante[i].regime,3,ficheiro);
        }
        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d ao fechar ficheiro", erro);
        }
    }
}



void leEstudantesBinario(tipoEstudante vEstudante[], int *numTotalEstudante){
    FILE *ficheiro;
    int erro;

        ficheiro=fopen("infoEstudante.dat", "rb");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fread(&(*numTotalEstudante),sizeof(int),1,ficheiro);
            fread(vEstudante,sizeof(tipoEstudante),*numTotalEstudante,ficheiro);

            erro = fclose(ficheiro);
            if (erro != 0){
                printf ("Erro %d ao fechar ficheiro", erro);
            }
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
        numeroEstudante=lerInteiro("\tNúmero de Estudante: ", 1000,2000);
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
    char eliminacao;

    if(*numTotalEstudantes == 0 ){
        printf("\tNão existem Unidades Curriculares. \n");
    } else{
        numeroEstudante=lerInteiro("\tNumero de Estudante: ",1000,2000);
        posicao=procuraEstudante(vEstudante,*numTotalEstudantes, numeroEstudante);

        if(posicao==-1){
            printf("\tA Unidade Curricular não existe. \n");
        } else {
            do{
                printf("Tem a certeza que quer eliminar o estudante %s, com o numero %d'?(S-Sim, N-Nao): ", vEstudante[posicao].nome, vEstudante[posicao].numeroEstudante);
                scanf("%c", &eliminacao);
                limpaBufferStdin();
                eliminacao = toupper(eliminacao);

                if(eliminacao!='S' && eliminacao!='N' ){
                    printf("Inseriu uma opcao invalida.\n");
                }

            }while (eliminacao!='S' && eliminacao!='N');

            if(eliminacao == 'S'){
                vEstudante[posicao]=vEstudante[posicao+1];

                (*numTotalEstudantes)--;
                 printf("\n\tO estudante foi eliminada, com o numero. \n");
            } else {
                printf("\n\tO estudante não %s foi eliminada, com o numero %d. \n", vEstudante[posicao].nome, vEstudante[posicao].numeroEstudante);
            }
        }
    }
}
