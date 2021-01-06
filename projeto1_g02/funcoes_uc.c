#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"


void escreveDadosUc(tipoUc vetorUc){
    printf("\n\tCódigo: %d", vetorUc.codigo);
    printf("\n\tDesignação: %s", vetorUc.designacao);
    printf("\n\tTipo (T, TP ou PL): %s", vetorUc.tipo);
    printf("\n\tSemestre: %d", vetorUc.semestre);
    printf("\n\tRegime (D,PL): %s", vetorUc.regime);
    printf("\n\tDuração de cada aula(em minutos): %.2f \n", vetorUc.duracao);
}


tipoUc leDadosUc(int codigoUc){
    tipoUc vetorUc;

    vetorUc.codigo = codigoUc;

    lerString("Designacao: ", vetorUc.designacao,80);

    do{
        lerString("Tipo (T, TP ou PL): ", vetorUc.tipo,3);
    } while( strcmp(vetorUc.tipo, "T") && strcmp(vetorUc.tipo, "t") && strcmp(vetorUc.tipo, "TP") && strcmp(vetorUc.tipo, "tp") && strcmp(vetorUc.tipo, "PL") && strcmp(vetorUc.tipo, "pl"));
    //strcmp - Compara se o a string tipo é igual a T/PL/TP

    vetorUc.semestre = lerInteiro("Semestre: ",1,6);

    do{
        lerString("Regime (D,PL): ", vetorUc.regime,3);
    } while( strcmp(vetorUc.regime, "D") && strcmp(vetorUc.regime, "d") && strcmp(vetorUc.regime, "PL") && strcmp(vetorUc.regime, "pl"));


    vetorUc.duracao = lerFloat("Duração de cada aula(em minutos): ", vetorUc.duracao, 0.60);

    return vetorUc;
}

void listaDadosUc(tipoUc vetorUc[MAX_UC], int numUc){
    int i;

    if (numUc==0) {
        printf("\n Não existem dados!!");
    }
    else {
        for (i=0; i<numUc; i++) {
        escreveDadosUc(vetorUc[i]);
        }
    }
}

int procuraUc(tipoUc vetorUc[], int numUc, int codigoUC){
    int i, posicao;
    posicao = -1;

    for (i=0; i<numUc; i++){
        if (vetorUc[i].codigo == codigoUC){
            posicao = i;
            i = numUc;
        }
    }
    return posicao;
}

int acrescentaUc(tipoUc vetorUc[MAX_UC], int *numUc, int codigoUc){
    tipoUc dados;
    int posicao;

    if (*numUc == MAX_UC){
        printf("Impossível acrescentar");
    }
    else {
        dados=leDadosUc(codigoUc);
        posicao=procuraUc(vetorUc,*numUc,dados.codigo);

        if(posicao != -1){ //Se o codigo da Uc ja existir escreve:
            printf("Unidade Curricular já existente");
        }
        else { //Se nao existir vai adicionar mais 1
            vetorUc[*numUc]=dados;
            (*numUc)++;
        }
    }
}


void gravarUcTexto(tipoUc vetorUc[], int numUc){
     FILE *ficheiro;
        int i;

        ficheiro=fopen("infoUc.txt", "w");
        if(ficheiro==NULL){
            printf("Erro ao abrir o ficheiro");
        } else{
            fprintf(ficheiro, "%d", numUc);

            for(i=0; i<=numUc; i++){
                fprintf(ficheiro, "\n %d", vetorUc[i].codigo);
                fprintf(ficheiro, "\n %s", vetorUc[i].designacao);
                fprintf(ficheiro, "\n %s", vetorUc[i].tipo);
                fprintf(ficheiro, "\n %d", vetorUc[i].semestre);
                fprintf(ficheiro, "\n %s", vetorUc[i].regime);
                fprintf(ficheiro, "\n %.2f", vetorUc[i].duracao);
            }
            fclose(ficheiro);
        }
}


void gravarUcBinario(tipoUc vetorUc[], int numUc){
     FILE *ficheiro;

        ficheiro=fopen("infoUc.dat", "wb");
        if(ficheiro==NULL){
            printf("Erro ao abrir o ficheiro");
        } else{
            fwrite(&numUc,sizeof(int),1,ficheiro);
            fwrite(vetorUc,sizeof(tipoUc),numUc,ficheiro);

            fclose(ficheiro);
        }
}

void leFicheiroTexto(tipoUc vetorUc[], int *numUc){
    FILE *ficheiro;
    int i;

        ficheiro=fopen("infoUc.txt", "r");
        if(ficheiro==NULL){
            printf("Erro ao abrir o ficheiro");
        } else{
            for(i=0; i<=*numUc; i++){
                fscanf(ficheiro, "%d", vetorUc[i].codigo);
                fgets(vetorUc[i].designacao,80,ficheiro);
                fgets(vetorUc[i].tipo,2,ficheiro);
                fscanf(ficheiro, "%d", vetorUc[i].semestre);
                fgets(vetorUc[i].regime,2,ficheiro);
                fscanf(ficheiro, "%f", vetorUc[i].duracao);
            }
            fclose(ficheiro);
        }
}


void leFicheiroUcBinario(tipoUc vetorUc[], int *numUc){
    FILE *ficheiro;

        ficheiro=fopen("infoUc.dat", "rb");
        if(ficheiro==NULL){
            printf("Erro ao abrir o ficheiro");
        } else{
            fread(&(*numUc),sizeof(int),1,ficheiro);
            fread(vetorUc,sizeof(tipoUc),*numUc,ficheiro);

            fclose(ficheiro);
        }
}

void eliminarDoVetor(tipoUc vetorUc[], int *numUc){
    int i, posicao, numeroUc;

    if(*numUc == 0 ){
        printf("Não existem Unidades Curriculares");
    }
    else{
        numeroUc=lerInteiro("Número de Unidades Curriculares: ", 1,100 );
        posicao=procuraUc(vetorUc,*numUc, numeroUc);
        if(posicao==-1){
            printf("A Unidade Curricular não existe");
        }
        else {
            for(i=posicao; i<*numUc-1; i++){
                vetorUc[i]=vetorUc[i+1];
            }
            (*numUc)--;
             printf("A Unidade Curricular foi eliminada");
        }
    }
}

void alterarVetorUc(tipoUc vetorUc){
    lerString("Designacao: ", vetorUc.designacao,80);
}
