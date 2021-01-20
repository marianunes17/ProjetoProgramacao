#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>


#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_menus.h"

tipoUc leDadosUc(int codigoUc){
    tipoUc vetorUc;

    vetorUc.codigo = codigoUc;

    lerString("\tDesignacao: ", vetorUc.designacao,MAX_STRING);



    do{
        lerString("\tTipo de Uc (S - Obrigatorio, N - Opcional): ", vetorUc.tipoDeUc,3);
    } while( strcmp(vetorUc.tipoDeUc, "S") && strcmp(vetorUc.tipoDeUc, "s") && strcmp(vetorUc.tipoDeUc, "N") && strcmp(vetorUc.tipoDeUc, "n"));
    //strcmp - Compara se a string tipo � igual a S ou N


    do{
        lerString("\tTipo de Aula (T, TP ou P): ", vetorUc.tipoAula,3);
    } while( strcmp(vetorUc.tipoAula, "T") && strcmp(vetorUc.tipoAula, "t") && strcmp(vetorUc.tipoAula, "TP") && strcmp(vetorUc.tipoAula, "tp") && strcmp(vetorUc.tipoAula, "P") && strcmp(vetorUc.tipoAula, "p"));
    //strcmp - Compara se a string tipo � igual a T/PL/TP

    vetorUc.semestre = lerInteiro("\tSemestre: ",1,6);

    do{
        lerString("\tRegime (D,PL): ", vetorUc.regime,3);
    } while( strcmp(vetorUc.regime, "D") && strcmp(vetorUc.regime, "d") && strcmp(vetorUc.regime, "PL") && strcmp(vetorUc.regime, "pl"));

    vetorUc.quantidadeTotalHoras = lerInteiro("\tTotal de horas prevista: ", 30, 100);


    vetorUc.duracao = lerInteiro("\tDura��o de cada aula(em minutos): ", 60, 180);

    vetorUc.quantidadeAulas = ((vetorUc.quantidadeTotalHoras)/(vetorUc.duracao/60));

    vetorUc.quantidadeHoras = vetorUc.quantidadeTotalHoras ;

    vetorUc.quantidadeAulasAgendadas = 0;

    return vetorUc;
}

void escreveDadosUc(tipoUc vetorUc){
    strupr(vetorUc.tipoAula);
    strupr(vetorUc.tipoDeUc);
    strupr(vetorUc.regime);

    printf("\n\tC�digo da Uc: \t %d", vetorUc.codigo);
    printf("\n\tDesigna��o: \t %s", vetorUc.designacao);
    printf("\n\tTipo de Uc: \t " );
        if( (strcmp(vetorUc.tipoDeUc, "S")==0) ){
            printf("Obrigat�ria");
        } else {
            printf("Opcional");
        }

    printf("\n\tTipo de Aula: \t ");
        if( (strcmp(vetorUc.tipoAula, "T")==0) ){
                printf("Teorico");
        } else {
            if( (strcmp(vetorUc.tipoAula, "P")==0) ){
                printf("Pr�tico");
            } else{
                printf("Pr�tico Laboratorial");
            }
        }

    printf("\n\tSemestre: \t %d� semestre", vetorUc.semestre);

    printf("\n\tRegime: \t ");
        if( (strcmp(vetorUc.regime, "D")==0) ){
            printf("Diurno");
        } else {
            printf("P�s-Laboral");
        }

    printf("\n\tTotal de horas prevista: \t %d", vetorUc.quantidadeTotalHoras);
    printf("\n\tDura��o de cada aula(em minutos):%d", vetorUc.duracao);
    printf("\n\tM�dia de aulas prevista: \t %d\n", vetorUc.quantidadeAulas);
    printf("\n\tQuantidade de horas que faltam lecionar: \t %d", vetorUc.quantidadeHoras);
    printf("\n\tTotal aulas agendadas: %d \n", vetorUc.quantidadeAulasAgendadas);
}



void listaDadosUc(tipoUc vetorUc[MAX_UC], int numTotalUc){
    int i;

    if (numTotalUc==0) {
        printf("\n\t N�o existem dados referentes �s Unidades Curriculares!");
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


void pesquisaCodigoUc(tipoUc vetorUc[], int numTotalUc){
    int posUC, codigoUc,i;

    codigoUc = lerInteiro("Insira o codigo da Uc", 1000, 2000);
    posUC=procuraUc(vetorUc,numTotalUc, codigoUc);
        if(posUC==-1){
            printf("\tA Unidade Curricular n�o existe. \n");
        }
        else {
            escreveDadosUc(vetorUc[posUC]);
        }
}

void gravarUcTexto(tipoUc vetorUc[], int numTotalUc){
    FILE *ficheiro;
    int i;

    ficheiro=fopen("infoUc.txt", "a+");

    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        fprintf(ficheiro, "Unidades Curriculares: %d\n", numTotalUc);

        for(i=0; i<numTotalUc; i++){
            fprintf(ficheiro, "\nCodigo: %d", vetorUc[i].codigo);
            fprintf(ficheiro, "\nDesignacao: %s", vetorUc[i].designacao);
            fprintf(ficheiro, "\nTipo de Uc: %s", vetorUc[i].tipoDeUc);
            fprintf(ficheiro, "\nTipo de Aula: %s", vetorUc[i].tipoAula);
            fprintf(ficheiro, "\nSemestre: %d", vetorUc[i].semestre);
            fprintf(ficheiro, "\nRegime: %s", vetorUc[i].regime);
            fprintf(ficheiro, "\nQuantidade Total de Horas: %.d", vetorUc[i].quantidadeTotalHoras);
            fprintf(ficheiro, "\nDuracao de cada aula: %.d", vetorUc[i].duracao);
            fprintf(ficheiro, "\nQuantidade Media de Aulas: %.d", vetorUc[i].quantidadeAulas);
            fprintf(ficheiro, "\nQuantidade total de horas: %.d\n", vetorUc[i].quantidadeHoras);
            fprintf(ficheiro, "\nQuantidade de aulas agendadas: %.d", vetorUc[i].quantidadeAulasAgendadas);
        }
        fclose(ficheiro);
    }
}


void gravarUcBinario(tipoUc vetorUc[], int *numTotalUc){
     FILE *ficheiro;
     int gravarDados;

        ficheiro=fopen("infoUc.dat", "wb");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro. \n");
        } else{
            fwrite(&(*numTotalUc),sizeof(int),1,ficheiro);
            gravarDados = fwrite(vetorUc,sizeof(tipoUc),*numTotalUc,ficheiro);

            printf("\n uc escritas gravadas bin = %d \n", gravarDados);

            fclose(ficheiro);
        }
}

void leFicheiroTexto(tipoUc vetorUc[], int *numTotalUc){
    FILE *ficheiro;
    int i;

    ficheiro=fopen("infoUc.txt", "r");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro.\n");
    } else{
        for(i=0; i<*numTotalUc; i++){
            fscanf(ficheiro, "%d", vetorUc[i].codigo);
            fgets(vetorUc[i].designacao,100,ficheiro);
            fgets(vetorUc[i].tipoDeUc,3,ficheiro);
            fgets(vetorUc[i].tipoAula,3,ficheiro);
            fscanf(ficheiro, "%d", vetorUc[i].semestre);
            fgets(vetorUc[i].regime,2,ficheiro);
            fscanf(ficheiro, "%d", vetorUc[i].quantidadeTotalHoras);
            fscanf(ficheiro, "%d", vetorUc[i].duracao);
            fscanf(ficheiro, "%d", vetorUc[i].quantidadeAulas);
            fscanf(ficheiro, "%d", vetorUc[i].quantidadeHoras);
            fscanf(ficheiro, "%d", vetorUc[i].quantidadeAulasAgendadas);
            }
        fclose(ficheiro);
    }
}


void leFicheiroUcBinario(tipoUc vetorUc[], int *numTotalUc){
    FILE *ficheiro;

        ficheiro=fopen("infoUc.dat", "rb");
        if(ficheiro==NULL){
            printf("\tErro ao abrir o ficheiro.\n");
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
        printf("\tImposs�vel acrescentar uma nova Unidade Curricular. O maximo de Unidades Curriculares � de: %d", MAX_UC);
    } else{
        posicao=procuraUc(vetorUc, *numTotalUc, codigoUc);

        if(posicao!=-1){
            printf("\tO codigo j� existe.");
        } else {
            dados=leDadosUc(codigoUc);
            vetorUc[*numTotalUc]=dados;
            (*numTotalUc)++;
             printf("\n\tFoi acrescentada uma nova Unidade Curricular");
        }
    }
}



void eliminarVetorUc(tipoUc vetorUc[], int *numTotalUc){
    int posicao, numeroUc;

    if(*numTotalUc == 0 ){
        printf("\tN�o existem Unidades Curriculares. \n");
    }
    else{
        numeroUc=lerInteiro("\tC�digo da Unidade Curricular: ", 1000,2000 );
        posicao=procuraUc(vetorUc,*numTotalUc, numeroUc);
        if(posicao==-1){
            printf("\tA Unidade Curricular n�o existe. \n");
        }
        else {
            vetorUc[posicao]=vetorUc[posicao+1];
        }

        (*numTotalUc)--;
         printf("\n\tA Unidade Curricular foi eliminada");
    }
}


void alterarVetorUc(tipoUc vetorUc[], int numTotalUc){
    int posicao, codigoUc;
    char opcao;

    if(numTotalUc == 0 ){
        printf("\tN�o existem Unidades Curriculares. \n");
    }
    else{
        codigoUc=lerInteiro("\tN�mero de Unidades Curriculares: ", 1000, 2000);
        posicao=procuraUc(vetorUc,numTotalUc, codigoUc);
        if(posicao==-1){
                printf("\tO numero nao existe.");
        } else{
            if (vetorUc[posicao].codigo == codigoUc){
                do{
                    opcao=subMenuAlteraUC();
                    switch(opcao){
                        case 'A':
                                printf("Escolheu a op��o de Alterar Designa��o\n");
                                 lerString("Designacao: ", vetorUc[posicao].designacao,MAX_STRING);
                                 break;
                        case 'B':
                                printf("Escolheu a op��o de Alterar Tipo de Uc\n");
                                do{
                                    lerString("\tTipo de Uc (S - Obrigatorio, N - Opcional): ", vetorUc[posicao].tipoDeUc,3);
                                } while( strcmp(vetorUc[posicao].tipoDeUc, "S") && strcmp(vetorUc[posicao].tipoDeUc, "s") && strcmp(vetorUc[posicao].tipoDeUc, "N") && strcmp(vetorUc[posicao].tipoDeUc, "n"));

                                break;
                        case 'C':
                                printf("Escolheu a op��o de Alterar Tipo de Aula\n");
                                do{
                                    lerString("\tTipo (T, TP ou P): ", vetorUc[posicao].tipoAula,3);
                                } while( strcmp(vetorUc[posicao].tipoAula, "T") && strcmp(vetorUc[posicao].tipoAula, "t") && strcmp(vetorUc[posicao].tipoAula, "TP") && strcmp(vetorUc[posicao].tipoAula, "tp") && strcmp(vetorUc[posicao].tipoAula, "P") && strcmp(vetorUc[posicao].tipoAula, "p"));
                                //strcmp - Compara se o a string tipoAula � igual a T/PL/TP
                                break;
                        case 'D':
                                printf("Escolheu a op��o de Alterar Semestre\n");
                                vetorUc[posicao].semestre = lerInteiro("Semestre: ",1,6);
                                break;
                        case 'E':
                                printf("Escolheu a op��o de Alterar Regime\n");
                                do{
                                    lerString("\tRegime (D,PL): ", vetorUc[posicao].regime,3);
                                } while( strcmp(vetorUc[posicao].regime, "D") && strcmp(vetorUc[posicao].regime, "d") && strcmp(vetorUc[posicao].regime, "PL") && strcmp(vetorUc[posicao].regime, "pl"));
                                break;
                        case 'F':
                                printf("Escolheu a op��o de Alterar Total de horas previstas\n");
                                vetorUc[posicao].quantidadeTotalHoras = lerInteiro("\tTotal de horas prevista: ", 30, 100);
                                vetorUc[posicao].quantidadeAulas = ((vetorUc[posicao].quantidadeTotalHoras)/(vetorUc[posicao].duracao/60));
                                break;
                        case 'G':
                                printf("Escolheu a op��o de Alterar Dura��o de cada aula(em minutos)\n");
                                 vetorUc[posicao].duracao = lerInteiro("\tf: ", 60, 180);
                                 vetorUc[posicao].quantidadeAulas = ((vetorUc[posicao].quantidadeTotalHoras)/(vetorUc[posicao].duracao/60));
                                break;
                        case 'V':
                                printf("Voltar");
                                break;
                        default: printf("Op��o Invalida.");
                    }
                } while(opcao!='V');
            }
            printf("\n\tA Unidade Curricular foi alterada.");
        }
    }
}
