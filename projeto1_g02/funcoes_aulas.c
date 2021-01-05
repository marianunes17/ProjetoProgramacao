#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

/*
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
}*/


//tipoAula *acrescentaAula(tipoAula vAula[], int *num)
/*
tipoAula *acrescentaAula(tipoAula vAula[], int *num, tipoUc vetorUc[], int numCodigo){​

    int posAula, posUc;​
    tipoAula *pAula, dados;
    pAula = vAula;  ​    // ponteiro auxiliar p/ ñ perder a 1ºposicao do vetor

    dados = lerDadosAula();
    posAula = procuraAulaNome(vAula,*num,dados.designacao);​

    if(posAula != -1){ ​
        printf("Nome de Aula já existente");
    }​
    else{	​
        // procura o codigo no vetor das UCs
        posUc = procuraUC(vetorUc,numCodigo,dados.codigo);​ //ver se Maria já tem esta funcao!!!!!

        if(posUc == -1){ ​
            printf("Uc não existe");
        }
        else{

            vAula = realloc(vAula,(*num+1)*sizeof(tipoAula));​ //obter espaço para  + 1 elemento

            if(vAula == NULL){​
                printf("ERRO - Impossivel inserir Aula");
                vAula = pAula;  // recuperar o valor de veotr vAula
            }
            else{​
                //dados.codigo = vetorUc[posUc].codigo;
                vAula[*num]= dados;​   //cria o campo para nova aula no vetor
                (*num)++;  // Atualiza numero de aulas

                //vLoja[posUc].numFunc++;
                //vLoja[posUc].custoV += dados.venc;
            }
        }
    }​
    return vAula; ​
}​*/

/*
int procuraUc(tipoUc vetorUc[MAX_UC], int numUc, int codigoUC){
    int i, posicao;
    posicao = -1;

    for (i=0; i<numUc; i++){
        if (vetorUc[i].codigo == codigoUC){
            posicao = i;
            i = numUc;
        }
    }
    return posicao;
}*/

/*
tipoAula *insereAula(int num){
    tipoAula *pAula;
    int i;

    pAula = malloc(n*sizeof(tipoAula));​

        if (pAula == NULL) {​
            printf ("Erro ao reservar memoria");​
        }​
        else{ ​
            for (i=0; i<num; i++) {​
                pAula[i] = lerDadosAula(); ​
            }​
        }​
    return pAula;
}*/

/*
tipoAula *eliminaAula(tipoAula vAula[], int *num, char designacao[]){​

    int i, pos;​
    tipoAula *pAula;
    pAula = vAula; ​// ponteiro auxiliar

    if (*num != 0) {​
        pos = procuraAulaNome(vAula, *num, designacao);​
        if (pos == -1) {​
            printf ("Funcionario nao existe!");​
        }​

        else {​
            for (i=pos; i < *num-1; i++) {​
                vAula[i] = vAula[i+1]; ​
            } ​

            vAula = realloc(vAula,(*num-1)*sizeof(tipoAula));​

            if (vAula == NULL && (*num-1) != 0){​
                printf ("Erro na alocacao de memoria ");​
                vAula = pAula;   // restaura valor de vAula
            }​
            (*num)--; // Atualiza numero funcionarios
        }​
    } ​
    return vAula;

} ​*/




/*
int adicionarAula(tipoAula vetor[MAX_AULAS], int *num){
    tipoAula dados;
    int posicao;

    if(*num == MAX_AULAS){
        printf("Impossivel Acrescentar");
    }
    else{
        desigAula = vetor[desigAula].designacao;
        aulaExiste = procuraNumero(desigAula, vetor, *num);

        if(aulaExiste == -1){
            if(vetor[numExiste].telefone != -1){
                    num++;
            }
                vetor[num]=lerDadosContacto();
                vetor[num].telefone=numTelefone;
            }
            else{
                printf("O numero ja existe");
            }

        //dados=lerDadosAula();
        //posicao = procuraAula(vetor,*num,dados.designacao);

        //if(posicao != -1){
        //    printf("Nome da Aula já existente");
        //}else{
        //    vetor[*num] = dados;
        //    (*num)++;
        //}
    }
    //return num;
}
*/



/*
int procuraCodigoUc(tipoUc vetor[], int n, int procCodigo){
    int i, pos;
    pos = -1;

    for ()


}*/





/*Função para eleminar uma Aula Agendada */
/*
void eliminaAula(tipoAulaOnline vetor[], int *numDeAulas){
    int i,posicao;
    char nome[20];

    if (*numDeAulas == 0){
        printf("\n\tNão existem Aulas Agendadas");
    }else{
        lerString("Designação da Aula a eliminar: ",20);
        posicao = procuraNumero(nome, vetor,*numDeAulas);

        if (posicao == -1) {
            printf ("\n\tERROR - Nome de Aula não existente");
        }else{
            for (i = posicao; i < *numDeAulas-1; i++){
                vetor[i] = vetor[i+1];
            }
            (*numDeAulas)--;
            printf ("\n\tAula Removida!");
        }
    }
}
*/

/*
tipoAula *lerFicheiroBin(tipoAula vAulas[],int *num){
    int lerDados, erro;

    FILE *ficheiro;
    tipoAula *pAula;
    pAula = vAula; ​// ponteiro auxiliar

    ficheiro = fopen("dadosAula.dat", "rb");

    if (ficheiro == NULL) {
        printf ("Impossível abrir ficheiro");
    }
    else {
        fread(&(*num),sizeof(int),1,ficheiro); //fwrite(&quantidade,sizeof(int),1,ficheiro)

        // usar o realloc para se conseguir ler o vetor dinamico
        // criar um vetor dinamico antes de se fazer a leitura

        vAula = realloc(vAula,(*num)*sizeof(tipoAula));​

        if (vAula == NULL && != 0){​
            printf ("Erro ao reservar memoria ");​
            vAula = pAula;   // restaura valor de vAula
        }​
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
    return vAula;
}
*/

/*
tipoAula *gravaFicheiroBin(tipoAula vAulas[],int *num){
    int gravarDados, erro;

    FILE *ficheiro;
    tipoAula *pAula;
    pAula = vAula; ​// ponteiro auxiliar

    ficheiro = fopen("dadosAula.dat", "ab");

    if (ficheiro == NULL) {
        printf ("Impossível abrir ficheiro");
    }
    else {
        fwrite(&(*num),sizeof(int),1,ficheiro); //fwrite(&quantidade,sizeof(int),1,ficheiro)

        // usar o realloc para se conseguir ler o vetor dinamico
        // criar um vetor dinamico antes de se fazer a leitura

        vAula = realloc(vAula,(*num)*sizeof(tipoAula));​

        if (vAula == NULL && != 0){​
            printf ("Erro ao reservar memoria ");​
            vAula = pAula;   // restaura valor de vAula
        }​
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
    return vAula;
}
*/



