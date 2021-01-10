#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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


void assistirAula(tipoEstudante vEstudante[], int *numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[]){
    int posicao;
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

            }
    }
        }
}

void gravarTextoEstudantes(tipoEstudante vEstudante[], int numTotalEstudante){
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


void gravarBinarioEstudantes(tipoEstudante vEstudante[], int numTotalEstudante){
     FILE *ficheiro;

        ficheiro=fopen("infoEstudante.dat", "wb");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fwrite(&numTotalEstudante,sizeof(int),1,ficheiro);
            fwrite(vEstudante,sizeof(tipoUc),numTotalEstudante,ficheiro);
            fclose(ficheiro);
        }
}

void leFicheiroTextoEstudantes(tipoEstudante vEstudante[], int *numTotalEstudante){
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



void leFicheiroUcBinarioEstudantes(tipoEstudante vEstudante[], int *numTotalEstudante){
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

            gravarBinarioEstudantes(vEstudante, *numTotalEstudantes);
            gravarTextoEstudantes(vEstudante, *numTotalEstudantes);
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

            gravarBinarioEstudantes(vEstudante, numTotalEstudantes);
            gravarTextoEstudantes(vEstudante, numTotalEstudantes);
                }
            }
        }
        printf("\n\tOs dados do estudante foram alterado.");
    }
}
