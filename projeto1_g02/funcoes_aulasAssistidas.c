#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_aulas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_estudantes.h"
#include "funcoes_estatistica.h"
#include "funcoes_menus.h"
#include "funcoes_uc.h"


tipoAulasAssistidas leDadosAulaAssistidas(int numeroEstudante, char designacao[], char acesso[]){
    tipoAulasAssistidas vAulasAssistidas;

    vAulasAssistidas.numEstudante = numeroEstudante; //passar o numero de estudante e não a posição
    strcpy (vAulasAssistidas.designacaoAula, designacao);
    strcpy (vAulasAssistidas.tipoAcesso, acesso);

    return vAulasAssistidas;
}

void escreveDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas){
    printf("\n\tNumero de Estudante: %d", vAulasAssistidas.numEstudante );
    printf("\n\tDesignacao da Aula: %s", vAulasAssistidas.designacaoAula);
    printf("\n\tTipo de acesso: %s\n", vAulasAssistidas.tipoAcesso);
}

void acrescentaAulaAssistida(tipoAulasAssistidas vAulasAssistidas[MAX_ESTUDANTES], int numeroEstudante, char designacao[], char acesso[], int *numAulasGravacoesAssistidas){
    tipoAulasAssistidas dados;

    dados=leDadosAulaAssistidas(numeroEstudante, designacao, acesso);
    vAulasAssistidas[*numAulasGravacoesAssistidas]=dados;
    (*numAulasGravacoesAssistidas)++;

    printf("Total de Aulas: %d \n", *numAulasGravacoesAssistidas);
}


void listaDadosAulasAssistidas(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas){
    int i;
    for (i=0; i<numAulasGravacoesAssistidas; i++) {
        escreveDadosAulasAssistidas(vAulasAssistidas[i]);
    }
}


void procuraAulaAssistidaAula(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas, char designacao[], int *contadorAulas){
  int i;

    for (i=0; i<=numAulasGravacoesAssistidas; i++){
        if(strcmp(vAulasAssistidas[i].designacaoAula, designacao) == 0 && strcmp(vAulasAssistidas[i].tipoAcesso, "aula") == 0){
            (*contadorAulas)++;

            printf("\t\t %d\n", vAulasAssistidas[i].numEstudante);
        }
    }
}


void procuraAulaAssistidaGravacao(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas, char designacao[], int *contadorGravacoes){
  int i;

    for (i=0; i<=numAulasGravacoesAssistidas; i++){
        if (strcmp(vAulasAssistidas[i].designacaoAula, designacao) == 0 && strcmp(vAulasAssistidas[i].tipoAcesso, "gravacao") == 0){
            (*contadorGravacoes)++;
            printf("\t\t %d\n", vAulasAssistidas[i].numEstudante);
        }
    }
}


void gravaAulasEstudantesBin(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas, int numTotalAulasAssistidas, int numTotalGravacoesAssistidas){
    FILE *ficheiro;
    int gravarDados;
    int erro;

    ficheiro=fopen("infoAulasEstudante.dat", "wb");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        fwrite(&numAulasGravacoesAssistidas,sizeof(int),1,ficheiro);
        fwrite(&numTotalAulasAssistidas,sizeof(int),1,ficheiro);
        fwrite(&numTotalGravacoesAssistidas,sizeof(int),1,ficheiro);
        gravarDados=fwrite(vAulasAssistidas,sizeof(tipoAulasAssistidas),numAulasGravacoesAssistidas,ficheiro);

        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d ao fechar ficheiro", erro);
        }
    }
}


void leAulasEstudantesBin(tipoAulasAssistidas vAulasAssistidas[], int *numAulasGravacoesAssistidas, int *numTotalAulasAssistidas, int *numTotalGravacoesAssistidas){
    FILE *ficheiro;
    int erro;

    ficheiro=fopen("infoAulasEstudante.dat", "rb");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        fread(&(*numAulasGravacoesAssistidas),sizeof(int),1,ficheiro);
        fread(&(*numTotalAulasAssistidas),sizeof(int),1,ficheiro);
        fread(&(*numTotalGravacoesAssistidas),sizeof(int),1,ficheiro);
        fread(vAulasAssistidas,sizeof(tipoAulasAssistidas),*numAulasGravacoesAssistidas,ficheiro);

        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d ao fechar ficheiro", erro);
        }
    }
}



void gravaAulasEstudantesTxt(tipoAulasAssistidas vAulasAssistidas[], int numAulasGravacoesAssistidas, int numTotalAulasAssistidas, int numTotalGravacoesAssistidas){
    FILE *ficheiro;
    int i, erro;

    ficheiro=fopen("infoAulasEstudante.txt", "a+");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
         fprintf(ficheiro, "Total Acessos: %d\n", numAulasGravacoesAssistidas);
         fprintf(ficheiro, "Total Numero Alunos a assistir às aulas: %d\n", numTotalAulasAssistidas);
         fprintf(ficheiro, "Total Numero Alunos a assistir às gravacoes: %d\n", numTotalGravacoesAssistidas);


        for(i=0; i<numAulasGravacoesAssistidas; i++){
            fprintf(ficheiro, "Numero estudante: %d\n", vAulasAssistidas[i].numEstudante);
            fprintf(ficheiro, "Designacao Aula: %s\n\n", vAulasAssistidas[i].designacaoAula);
            fprintf(ficheiro, "Acesso: %s\n\n", vAulasAssistidas[i].tipoAcesso);
        }

        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d ao fechar ficheiro", erro);
        }
    }
}

void leAulasEstudantesTxt(tipoAulasAssistidas vAulasAssistidas[], int *numAulasGravacoesAssistidas, int *numTotalAulasAssistidas, int *numTotalGravacoesAssistidas){
    FILE *ficheiro;
    int i, erro;

    ficheiro=fopen("infoAulasEstudante.txt", "r");
    if(ficheiro==NULL){
        printf("\tErro ao abrir o ficheiro. \n");
    } else{
        for(i=0; i<*numAulasGravacoesAssistidas; i++){
            fscanf(ficheiro, "%d", vAulasAssistidas[i].numEstudante);
            fgets(vAulasAssistidas[i].designacaoAula,100,ficheiro);
            fgets(vAulasAssistidas[i].tipoAcesso,10,ficheiro);
        }
        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d ao fechar ficheiro", erro);
        }
    }
}


int procuraEstudanteAssistir(tipoAulasAssistidas vAulasAssistidas[], char designacao[], int numeroEstudante, int numAulasGravacoesAssistidas){
    int i, posicao;
    posicao = -1;

    for (i=0; i<numAulasGravacoesAssistidas; i++){
        if(strcmp(vAulasAssistidas[i].designacaoAula, designacao) == 0 && vAulasAssistidas[i].numEstudante == numeroEstudante){
            posicao = i;
            i = numAulasGravacoesAssistidas;
        }
    }

    return posicao;
}

void assistirAula(tipoAulasAssistidas vAulasAssistidas[], tipoEstudante vEstudante[], int numTotalEstudantes, tipoAula vAulas[], int numTotalAulas, char designacaoAula[], int *numTotalAulasAssistidas, int *numAulasGravacoesAssistidas, int numTotalGravacoesAssistidas){
   int posicaoAula, posicaoEstudante, numeroEstudante, posAssistir;
   char acesso[7];
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

                if(numTotalAulas==0){
                    printf("Não existem estudantes. \n");
                } else {
                    posicaoEstudante = procuraEstudante(vEstudante, numTotalEstudantes, numeroEstudante);

                    if(posicaoEstudante == -1){
                        printf ("O numero de estudante inserido não existe");

                    } else {
                         posAssistir=procuraEstudanteAssistir(vAulasAssistidas, designacaoAula, numeroEstudante, *numAulasGravacoesAssistidas);

                        if(posAssistir == -1){
                            acrescentaAulaAssistida(vAulasAssistidas, numeroEstudante, designacaoAula, acesso, &(*numAulasGravacoesAssistidas));
                            printf ("Está a assitir à aula de %s", designacaoAula);

                            (*numTotalAulasAssistidas)++;

                            printf("numTotalAulasAssistidas %d", *numTotalAulasAssistidas);

                            gravaAulasEstudantesTxt(vAulasAssistidas, *numAulasGravacoesAssistidas, *numTotalAulasAssistidas, numTotalGravacoesAssistidas);

                            gravaAulasEstudantesBin(vAulasAssistidas, *numAulasGravacoesAssistidas, *numTotalAulasAssistidas, numTotalGravacoesAssistidas);

                        } else {
                             printf("\tJa está a assistir à aula de %s", designacaoAula);
                        }
                    }
                }
            } else {
                printf("A aula não esta a decorrer");
            }
        }
    }
}


void assistirGravacaoAula(tipoAulasAssistidas vAulasAssistidas[], tipoUc vetorUc[], tipoAula vAulas[], tipoEstudante vEstudante[],  int numTotalEstudantes,  int numTotalAulas, char designacaoAula[], int *numTotalGravacoesAssistidas, int *numAulasGravacoesAssistidas, int *numTotalAulasAssistidas, int numTotalUc){
   int posicaoAula, posicaoEstudante, numeroEstudante, codigoUc, posUc;
    char acesso[10];
   strcpy(acesso, "gravacao");

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
                    if(numTotalAulas==0){
                        printf("Não existem estudantes. \n");
                    } else {
                        posicaoEstudante = procuraEstudante(vEstudante, numTotalEstudantes, numeroEstudante);

                        if(posicaoEstudante != -1){
                            acrescentaAulaAssistida(vAulasAssistidas, numeroEstudante, designacaoAula, acesso, &(*numAulasGravacoesAssistidas));

                            (*numTotalGravacoesAssistidas)++;


                            gravaAulasEstudantesTxt(vAulasAssistidas, *numAulasGravacoesAssistidas, *numTotalAulasAssistidas, *numTotalGravacoesAssistidas);
                            gravaAulasEstudantesBin(vAulasAssistidas, *numAulasGravacoesAssistidas, *numTotalAulasAssistidas, *numTotalGravacoesAssistidas);


                            codigoUc = vAulas[posicaoAula].codigo;
                            posUc = procuraUc(vetorUc, numTotalUc, codigoUc);

                            vetorUc[posUc].quantAcessosGravacoes = vetorUc[posUc].quantAcessosGravacoes + 1;


                            printf("vetorUc[posUc].quantAcessosGravacoes %d", vetorUc[posUc].quantAcessosGravacoes);

                            printf ("Está a assitir à gravação da aula de %s", designacaoAula);
                        }
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

