#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_uc.h"


tipoAula lerDadosAula(){
    tipoAula aula;
    lerString("Indique Descrição: ", aula.designacao, MAX_AULAS);
    lerString("Docente: ", aula.docente, MAX_AULAS);
    //campo tipo contador - tem a haver com a funcionalidade do programa
    aula.gavacao = 0;
    aula.estadoAula = 0;
    return aula;
}


int procuraAulaNome(tipoAula vAula[], int num, char procAula[]){
    int i, pos;
    pos = -1;

    for (i=0; i<num; i++){
        if (strcmp(vAula[i].designacao, procAula) == 0){  // Elemento encontrado
            pos = i;       // guarda posição de numero em vAula
            i = num;    // para concluir pesquisa (sair do for)
        }
    }
    return pos;
}


tipoAula *acrescentaAula(tipoAula vAula[], int *num, tipoUc vetorUc[], int posUc){
    tipoAula *pAula, dados;
    int posAula;
    pAula = vAula;

    dados = lerDadosAula();
    posAula = procuraAulaNome(vAula,*num,dados.designacao);

    if(posAula != -1){
        printf("Nome de Aula existente");
    }else{
        vAula = realloc(vAula, (*num+1)*sizeof(tipoAula));

        if(vAula == NULL){
            printf("ERRO - impossivel inserir aula");
            vAula = pAula;
        }else{
            vAula[*num] = dados;
            (*num)++;
        }
    }
    return vAula;
}





tipoAula *eliminaAula(tipoAula vAula[], int *num, char designacao[]){
    int i, pos;
    tipoAula *pAula;
    pAula = vAula; // ponteiro auxiliar

    if(*num !=0){
        pos=procuraAulaNome(vAula, *num,designacao);
        if(pos== -1){
            printf ("Funcionario nao existe!");
        }

        else{
            for(i=pos; i<*num-1;i++){
                vAula[i]=vAula[i+1];
            }

            vAula = realloc(vAula,(*num-1)*sizeof(tipoAula));

            if(vAula==NULL && (*num-1) !=0){
                printf ("Erro na alocacao de memoria");
                vAula = pAula;   // restaura valor de vAula
            }
            (*num)--; // Atualiza numero funcionarios
        }
    }
    return vAula;
}


tipoAula *lerFicheiroBin(tipoAula vAulas[],int *num){
    int lerDados, erro;

    FILE *ficheiro;
    tipoAula *pAula;

    ficheiro = fopen("dadosAula.dat", "rb");

    if (ficheiro == NULL) {
        printf ("Impossível abrir ficheiro");
    }
    else {
        fread(&(*num),sizeof(int),1,ficheiro); //fwrite(&quantidade,sizeof(int),1,ficheiro)
    pAula = vAulas; // ponteiro auxiliar

        // usar o realloc para se conseguir ler o vetor dinamico
        // criar um vetor dinamico antes de se fazer a leitura

        vAulas = realloc(vAulas,(*num)*sizeof(tipoAula));

        if(vAulas == NULL && *num !=0){
                printf("Erro ao reservar memoria");
            vAulas = pAula;   // restaura valor de vAulas
        }
        else{
            lerDados = fread(vAulas,sizeof(tipoAula),*num,ficheiro);
            printf("Elementos escritos = %d \n", lerDados);
        }

        //fclose(ficheiro);
        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d ao fechar ficheiro", erro);
        }
    }
    return vAulas;
}



tipoAula *gravaFicheiroBin(tipoAula vAulas[],int *num){
    int gravarDados, erro;

    FILE *ficheiro;
    tipoAula *pAula;
    pAula = vAulas; // ponteiro auxiliar

    ficheiro = fopen("dadosAula.dat", "ab");

    if (ficheiro == NULL) {
        printf ("Impossível abrir ficheiro");
    }
    else {
        fwrite(&(*num),sizeof(int),1,ficheiro); //fwrite(&quantidade,sizeof(int),1,ficheiro)

        // usar o realloc para se conseguir ler o vetor dinamico
        // criar um vetor dinamico antes de se fazer a leitura

        vAulas = realloc(vAulas,(*num)*sizeof(tipoAula));

        if(vAulas == NULL && *num !=0){
                printf("Erro ao reservar memoria");
            vAulas = pAula;   // restaura valor de vAulas
        }
        else{
            gravarDados = fwrite(vAulas,sizeof(tipoAula),*num,ficheiro);
            printf("Elementos escritos = %d \n", gravarDados);
        }

        //fclose(ficheiro);
        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d ao fechar ficheiro", erro);
        }
    }
    return vAulas;
}



