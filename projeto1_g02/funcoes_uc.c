#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_menus.h"


void escreveDadosUc(tipoUc vetorUc){
    printf("\n\tCódigo: %d", vetorUc.codigo);
    printf("\n\tDesignação: %s", vetorUc.designacao);
    printf("\n\tTipo (T, TP ou PL): %s", vetorUc.tipo);
    printf("\n\tSemestre: %d", vetorUc.semestre);
    printf("\n\tRegime (D,PL): %s", vetorUc.regime);
    printf("\n\tDuração de cada aula(em minutos): %d \n", vetorUc.duracao);
}


tipoUc leDadosUc(int codigoUc){
    tipoUc vetorUc;

    vetorUc.codigo = codigoUc;

    lerString("\tDesignacao: ", vetorUc.designacao,80);

    do{
        lerString("\tTipo (T, TP ou PL): ", vetorUc.tipo,3);
    } while( strcmp(vetorUc.tipo, "T") && strcmp(vetorUc.tipo, "t") && strcmp(vetorUc.tipo, "TP") && strcmp(vetorUc.tipo, "tp") && strcmp(vetorUc.tipo, "PL") && strcmp(vetorUc.tipo, "pl"));
    //strcmp - Compara se a string tipo é igual a T/PL/TP

    vetorUc.semestre = lerInteiro("\tSemestre: ",1,6);

    do{
        lerString("\tRegime (D,PL): ", vetorUc.regime,3);
    } while( strcmp(vetorUc.regime, "D") && strcmp(vetorUc.regime, "d") && strcmp(vetorUc.regime, "PL") && strcmp(vetorUc.regime, "pl"));


    vetorUc.duracao = lerInteiro("\tDuração de cada aula(em minutos): ", 60, 180);
    return vetorUc;
}

void listaDadosUc(tipoUc vetorUc[MAX_UC], int numTotalUc){
    int i;

    if (numTotalUc==0) {
        printf("\n\t Não existem dados referentes às Unidades Curriculares!");
    }
    else {
        for (i=0; i<numTotalUc; i++) {
        escreveDadosUc(vetorUc[i]);
        }
    }
}

int procuraUc(tipoUc vetorUc[], int numTotalUc, int codigoUC){
    int i, posicao;
    posicao = -1;

    for (i=0; i<numTotalUc; i++){
        if (vetorUc[i].codigo == codigoUC){
            posicao = i;
            i = numTotalUc; //Quando se encontra o codigoUc iguala-se o i=numTotalUc para sair do for
        }
    }
    return posicao;
}

void gravarUcTexto(tipoUc vetorUc[], int numTotalUc){
     FILE *ficheiro;
        int i;

        ficheiro=fopen("infoUc.txt", "a+");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fprintf(ficheiro, "%d", numTotalUc);

            for(i=0; i<=numTotalUc; i++){
                fprintf(ficheiro, "\n %d", vetorUc[i].codigo);
                fprintf(ficheiro, "\n %s", vetorUc[i].designacao);
                fprintf(ficheiro, "\n %s", vetorUc[i].tipo);
                fprintf(ficheiro, "\n %d", vetorUc[i].semestre);
                fprintf(ficheiro, "\n %s", vetorUc[i].regime);
                fprintf(ficheiro, "\n %.d", vetorUc[i].duracao);
            }
            fclose(ficheiro);
        }
}


void gravarUcBinario(tipoUc vetorUc[], int numTotalUc){
     FILE *ficheiro;

        ficheiro=fopen("infoUc.dat", "wb");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fwrite(&numTotalUc,sizeof(int),1,ficheiro);
            fwrite(vetorUc,sizeof(tipoUc),numTotalUc,ficheiro);

            fclose(ficheiro);
        }
}

void leFicheiroTexto(tipoUc vetorUc[], int *numTotalUc){
    FILE *ficheiro;
    int i;

        ficheiro=fopen("infoUc.txt", "r");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            for(i=0; i<=*numTotalUc; i++){
                fscanf(ficheiro, "%d", vetorUc[i].codigo);
                fgets(vetorUc[i].designacao,80,ficheiro);
                fgets(vetorUc[i].tipo,2,ficheiro);
                fscanf(ficheiro, "%d", vetorUc[i].semestre);
                fgets(vetorUc[i].regime,2,ficheiro);
                fscanf(ficheiro, "%d", vetorUc[i].duracao);
            }
            fclose(ficheiro);
        }
}


void leFicheiroUcBinario(tipoUc vetorUc[], int *numTotalUc){
    FILE *ficheiro;

        ficheiro=fopen("infoUc.dat", "rb");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fread(&(*numTotalUc),sizeof(int),1,ficheiro);
            fread(vetorUc,sizeof(tipoUc),*numTotalUc,ficheiro);

            fclose(ficheiro);
        }
}

void acrescentaUc(tipoUc vetorUc[MAX_UC], int *numTotalUc, int codigoUc){
    tipoUc dados;
    int posicao;

    if (*numTotalUc == MAX_UC){
        printf("\tImpossível acrescentar uma nova Unidade Curricular. O maximo de Unidades Curriculares é de: %d", MAX_UC);
    } else{
        posicao=procuraUc(vetorUc, *numTotalUc, codigoUc);

        if(posicao!=-1){
            printf("\tO codigo já existe.");
        } else {
            dados=leDadosUc(codigoUc);
            vetorUc[*numTotalUc]=dados;
            (*numTotalUc)++;
            gravarUcBinario(vetorUc, *numTotalUc);
            gravarUcTexto(vetorUc, *numTotalUc);
             printf("\n\tFoi acrescentada uma nova Unidade Curricular");
        }
    }
}



void eliminarDoVetor(tipoUc vetorUc[], int *numTotalUc){
    int i, posicao, numeroUc;

    if(*numTotalUc == 0 ){
        printf("\tNão existem Unidades Curriculares. \n");
    }
    else{
        numeroUc=lerInteiro("\tCódigo da Unidade Curricular: ", 1000,2000 );
        posicao=procuraUc(vetorUc,*numTotalUc, numeroUc);
        if(posicao==-1){
            printf("\tA Unidade Curricular não existe. \n");
        }
        else {
            for(i=posicao; i<*numTotalUc-1; i++){
                vetorUc[i]=vetorUc[i+1];
            }
            (*numTotalUc)--;
            gravarUcBinario(vetorUc, *numTotalUc);
            gravarUcTexto(vetorUc, *numTotalUc);
             printf("\n\tA Unidade Curricular foi eliminada");
        }
    }
}

void alterarVetorUc(tipoUc vetorUc[], int *numTotalUc){
    int i, posicao, codigoUc;
    char opcao;

    if(*numTotalUc == 0 ){
        printf("\tNão existem Unidades Curriculares. \n");
    }
    else{
        codigoUc=lerInteiro("\tNúmero de Unidades Curriculares: ", 1000, 2000);
        posicao=procuraUc(vetorUc,*numTotalUc, codigoUc);
        if(posicao==-1){
                printf("\tO numero nao existe.");
        } else{
             for (i=0; i<*numTotalUc; i++){
                if (vetorUc[i].codigo == codigoUc){
                    do{
                        opcao=subMenuAlteraUC();
                        switch(opcao){
                            case 'A':
                                     lerString("Designacao: ", vetorUc[i].designacao,80);
                                     break;
                            case 'B':
                                     do{
                                        lerString("Tipo (T, TP ou PL): ", vetorUc[i].tipo,3);
                                    } while( strcmp(vetorUc[i].tipo, "T") && strcmp(vetorUc[i].tipo, "t") && strcmp(vetorUc[i].tipo, "TP") && strcmp(vetorUc[i].tipo, "tp") && strcmp(vetorUc[i].tipo, "PL") && strcmp(vetorUc[i].tipo, "pl"));
                                    //strcmp - Compara se o a string tipo é igual a T/PL/TP
                                    break;
                            case 'C':
                                    vetorUc[i].semestre = lerInteiro("Semestre: ",1,6);
                                    break;
                            case 'D':
                                    do{
                                        lerString("Regime (D,PL): ", vetorUc->regime,3);
                                    } while( strcmp(vetorUc[i].regime, "D") && strcmp(vetorUc[i].regime, "d") && strcmp(vetorUc[i].regime, "PL") && strcmp(vetorUc[i].regime, "pl"));
                                    break;
                            case 'E':
                                    vetorUc[i].duracao = lerInteiro("Duração de cada aula(em minutos): ", 60, 180);
                                    break;
                            case 'V':
                                    printf("Voltar");
                                    break;
                            default: printf("Opção Invalida.");
                        }
                    } while(opcao!='V');

                    gravarUcBinario(vetorUc, *numTotalUc);
                    gravarUcTexto(vetorUc, *numTotalUc);
                }
            }
        }
        printf("\n\tA Unidade Curricular foi alterada.");
    }
}
