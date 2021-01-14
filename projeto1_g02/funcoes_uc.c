#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>


#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_menus.h"


void escreveDadosUc(tipoUc vetorUc){
    strupr(vetorUc.tipoAula);
    strupr(vetorUc.tipoDeUc);
    strupr(vetorUc.regime);

    printf("\n\tCódigo da Uc: \t %d", vetorUc.codigo);
    printf("\n\tDesignação: \t %s", vetorUc.designacao);
    printf("\n\tTipo de Uc: \t " );
        if( (strcmp(vetorUc.tipoDeUc, "S")==0) ){
            printf("Obrigatória");
        } else {
            printf("Opcional");
        }

    printf("\n\tTipo de Aula: \t ");
        if( (strcmp(vetorUc.tipoAula, "T")==0) ){
                printf("Teorico");
        } else {
            if( (strcmp(vetorUc.tipoAula, "P")==0) ){
                printf("Prático");
            } else{
                printf("Prático Laboratorial");
            }
        }

    printf("\n\tSemestre: \t %dº semestre", vetorUc.semestre);

    printf("\n\tRegime: \t ");
        if( (strcmp(vetorUc.regime, "D")==0) ){
            printf("Diurno");
        } else {
            printf("Pós-Laboral");
        }

    printf("\n\tTotal de horas prevista: \t %d", vetorUc.quantidadeHoras);
    printf("\n\tDuração de cada aula(em minutos):%d", vetorUc.duracao);
    printf("\n\tMédia de aulas prevista: \t %d\n", vetorUc.quantidadeAulas);
 //   printf("\n\tTotal de horas prevista: %d \n", vetorUc.quantidadeAulasAgendadas);
}


tipoUc leDadosUc(int codigoUc){
    tipoUc vetorUc;

    vetorUc.codigo = codigoUc;

    lerString("\tDesignacao: ", vetorUc.designacao,MAX_STRING);



    do{
        lerString("\tTipo de Uc (S - Obrigatorio, N - Opcional): ", vetorUc.tipoDeUc,3);
    } while( strcmp(vetorUc.tipoDeUc, "S") && strcmp(vetorUc.tipoDeUc, "s") && strcmp(vetorUc.tipoDeUc, "N") && strcmp(vetorUc.tipoDeUc, "n"));
    //strcmp - Compara se a string tipo é igual a S ou N


    do{
        lerString("\tTipo de Aula (T, TP ou P): ", vetorUc.tipoAula,3);
    } while( strcmp(vetorUc.tipoAula, "T") && strcmp(vetorUc.tipoAula, "t") && strcmp(vetorUc.tipoAula, "TP") && strcmp(vetorUc.tipoAula, "tp") && strcmp(vetorUc.tipoAula, "P") && strcmp(vetorUc.tipoAula, "p"));
    //strcmp - Compara se a string tipo é igual a T/PL/TP

    vetorUc.semestre = lerInteiro("\tSemestre: ",1,6);

    do{
        lerString("\tRegime (D,PL): ", vetorUc.regime,3);
    } while( strcmp(vetorUc.regime, "D") && strcmp(vetorUc.regime, "d") && strcmp(vetorUc.regime, "PL") && strcmp(vetorUc.regime, "pl"));

    vetorUc.quantidadeHoras = lerInteiro("\tTotal de horas prevista: ", 1, 100);


    vetorUc.duracao = lerInteiro("\tDuração de cada aula(em minutos): ", 60, 180);

    vetorUc.quantidadeAulas = ((vetorUc.quantidadeHoras)/(vetorUc.duracao/60));

    //vetorUc.quantidadeAulas = vetorUc.quantidadeHoras/vetorUc.quantidadeHoras;
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
                fprintf(ficheiro, "\n %s", vetorUc[i].tipoDeUc);
                fprintf(ficheiro, "\n %s", vetorUc[i].tipoAula);
                fprintf(ficheiro, "\n %d", vetorUc[i].semestre);
                fprintf(ficheiro, "\n %s", vetorUc[i].regime);
                fprintf(ficheiro, "\n %.d", vetorUc[i].quantidadeHoras);
                fprintf(ficheiro, "\n %.d", vetorUc[i].duracao);
                fprintf(ficheiro, "\n %.d", vetorUc[i].quantidadeAulas);
        //        fprintf(ficheiro, "\n %.d", vetorUc[i].quantidadeAulasAgendadas);
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
                fgets(vetorUc[i].designacao,100,ficheiro);
                fgets(vetorUc[i].tipoDeUc,3,ficheiro);
                fgets(vetorUc[i].tipoAula,3,ficheiro);
                fscanf(ficheiro, "%d", vetorUc[i].semestre);
                fgets(vetorUc[i].regime,2,ficheiro);
                fscanf(ficheiro, "%d", vetorUc[i].quantidadeHoras);
                fscanf(ficheiro, "%d", vetorUc[i].duracao);
                fscanf(ficheiro, "%d", vetorUc[i].quantidadeAulas);
            //    fscanf(ficheiro, "%d", vetorUc[i].quantidadeAulasAgendadas);
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



void eliminarVetorUc(tipoUc vetorUc[], int *numTotalUc){
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
                                     lerString("Designacao: ", vetorUc[i].designacao,MAX_STRING);
                                     break;
                            case 'B':
                                    do{
                                        lerString("\tTipo de Uc (S - Obrigatorio, N - Opcional): ", vetorUc[i].tipoDeUc,3);
                                    } while( strcmp(vetorUc[i].tipoDeUc, "S") && strcmp(vetorUc[i].tipoDeUc, "s") && strcmp(vetorUc[i].tipoDeUc, "N") && strcmp(vetorUc[i].tipoDeUc, "n"));

                                    break;
                            case 'C':
                                    do{
                                        lerString("\tTipo (T, TP ou P): ", vetorUc[i].tipoAula,3);
                                    } while( strcmp(vetorUc[i].tipoAula, "T") && strcmp(vetorUc[i].tipoAula, "t") && strcmp(vetorUc[i].tipoAula, "TP") && strcmp(vetorUc[i].tipoAula, "tp") && strcmp(vetorUc[i].tipoAula, "P") && strcmp(vetorUc[i].tipoAula, "p"));
                                    //strcmp - Compara se o a string tipoAula é igual a T/PL/TP
                                    break;
                            case 'D':
                                    vetorUc[i].semestre = lerInteiro("Semestre: ",1,6);
                                    break;
                            case 'E':
                                    do{
                                        lerString("\tRegime (D,PL): ", vetorUc[i].regime,3);
                                    } while( strcmp(vetorUc[i].regime, "D") && strcmp(vetorUc[i].regime, "d") && strcmp(vetorUc[i].regime, "PL") && strcmp(vetorUc[i].regime, "pl"));
                                    break;
                            case 'F':
                                    vetorUc[i].quantidadeAulas = lerInteiro("Duração de cada aula(em minutos): ", 0, 100);
                                    break;
                            case 'G':
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
