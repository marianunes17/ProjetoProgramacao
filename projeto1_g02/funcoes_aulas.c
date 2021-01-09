#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_uc.h"
#include "funcoes_menus.h"


tipoAula lerDadosAula(){
    tipoAula aula;

    lerString("Indique Descrição: ", aula.designacao, MAX_STRING_AULAS);

    lerString("Docente: ", aula.docente, MAX_STRING_AULAS);
    //campo tipo contador - tem a haver com a funcionalidade do programa
    aula.codigo = 0;
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

        dados.codigo = vetorUc[posUc].codigo;
        dados.data = lerData();

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

void mostrarDadosAula(tipoAula vAulas[], int numAula) {
    int i;
    if (numAula == 0) {
        printf("\nSem dados!");
    }
    else{
        printf("\nListagem das Aulas ->\n\n");

        for(i=0; i<numAula; i++) {
            printf(" Descricao: %s\n",vAulas[i].designacao);
            printf(" Docente: %s\n",vAulas[i].docente);
            printf(" Codigo UC: %d\n",vAulas[i].codigo);
            printf(" Data: %d / %d / %d\n\n",vAulas[i].data.dia,vAulas[i].data.mes,vAulas[i].data.ano);
        }
    }
}

void escreveDadosAulas(tipoAula vAulas){
    printf("\tDescricao: %s\n",vAulas.designacao);
    printf("\tDocente: %s\n",vAulas.docente);
    printf("\tCodigo UC: %d\n",vAulas.codigo);
    printf("\tData: %d / %d / %d\n\n",vAulas.data.dia, vAulas.data.mes,vAulas.data.ano);
}




tipoAula *lerFicheiroBin(tipoAula vAulas[],int *num){
    FILE *ficheiro;

    int erro;
    tipoAula *pAula;

    ficheiro = fopen("dataAulas.dat", "rb");

    if (ficheiro == NULL) {
        printf ("\nImpossível abrir ficheiro");
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
            fread(vAulas,sizeof(tipoAula),*num,ficheiro);
        }

        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d ao fechar ficheiro", erro);
        }
    }
    return vAulas;
}


void gravaFicheiroTextAula(tipoAula vAulas[],int num){

    FILE *ficheiro;
 int lerDados,i,erro;
    ficheiro = fopen("dadosAulas.txt", "a+");

    if (ficheiro == NULL) {
        printf ("Impossível abrir ficheiro");
    }
    else {

        fprintf(ficheiro, "Todas as Aulas: %d\n\n",num);

        for (i=0; i<num; i++){
            fprintf(ficheiro,"Designacao -> %s\n",vAulas[i].designacao);
            fprintf(ficheiro,"Docente -> %s\n",vAulas[i].docente);
            fprintf(ficheiro,"Codigo UC -> %d\n",vAulas[i].codigo);
            fprintf(ficheiro,"Data -> %d\t",vAulas[i].data.dia);
            fprintf(ficheiro,"%d\t",vAulas[i].data.mes);
            fprintf(ficheiro,"%d\n",vAulas[i].data.ano);
        }

        //fclose(ficheiro);
        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d no fecho ficheiro", erro);
        }
    }

}

void  gravaFicheiroBin(tipoAula vAulas[],int num) {

    FILE *ficheiro;
    int gravarDados,erro;

    ficheiro = fopen("dataAulas.dat", "wb");

    if (ficheiro == NULL)
    {
        printf ("Impossível abrir ficheiro");
    }
    else
    {
        fwrite(&num,sizeof(int),1,ficheiro);
        gravarDados = fwrite(vAulas,sizeof(tipoAula),num,ficheiro);
        printf("Aulas escritas gravadas = %d \n", gravarDados);

       gravaFicheiroTextAula(vAulas,num);

        //fclose(ficheiro);
        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d no fecho ficheiro", erro);
        }
    }

}



tipoAula *lerFicheiroTextAula(tipoAula vAulas[],int *num){

    FILE *ficheiro;

    tipoAula *pAulas;
    int lerDados,i,erro;

    ficheiro = fopen("dadosAulas.txt", "r");

    if (ficheiro == NULL) {
        printf ("Impossível abrir ficheiro");
    }
    else {
        pAulas = vAulas;
        fprintf(ficheiro,"Lista Aulas: %d\n", *num);

        for (i=0; i<*num; i++){
            fprintf(ficheiro,"%s\n",pAulas[i].designacao);
            fprintf(ficheiro,"%s\n",pAulas[i].docente);
            fprintf(ficheiro,"%d\n",pAulas[i].codigo);
        }

        //fclose(ficheiro);
        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d no fecho ficheiro", erro);
        }
    }
    return vAulas;
}


// só dá se a aula estiver com estado 'agendada' ou 'realizada'!!!!!!!!
tipoAula *eliminaAula(tipoAula vAula[], int *num, char designacao[]){
    int i, pos;
    tipoAula *pAula;
    pAula = vAula; // ponteiro auxiliar

    if(*num != 0){

        pos = procuraAulaNome(vAula, *num, designacao);

        if(pos == -1){
            printf ("Aula nao existe!");
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
            (*num)--; // Atualiza numero aulas retirando uma
           gravaFicheiroBin(vAula, *num);
        }
    }
    return vAula;
}

tipoAula *alteraAulas(tipoAula vAula[], int *numAulas,  char designacaoAula[]){
    int  posicao, i;
    char opcao;
    tipoAula aula;

    if(*numAulas == 0 ){
        printf("Não existem Aulas. \n");
    }
    else{
        posicao=procuraAulaNome(vAula, *numAulas, designacaoAula);

        if(posicao==-1){
            printf("A designação nao existe.");
        } else {
            for (i=0; i<*numAulas; i++){
                if (strcmp(vAula[i].designacao, designacaoAula)) {

                    do{
                        opcao=subMenuAlteraAula();
                        switch(opcao){
                            case 'A':
                                    lerString("Indique Descrição: ", vAula[i].designacao, MAX_STRING_AULAS);
                                     break;
                            case 'B':
                                     lerString("Docente: ", vAula[i].docente, MAX_STRING_AULAS);
                                    break;
                            case 'V':
                                    printf("Voltar");
                                    break;
                            default: printf("Opção Invalida.");
                        }
                    } while(opcao!='V');

                   gravaFicheiroBin(vAula, *numAulas);
                   gravaFicheiroTextAula(vAula, *numAulas);

                   i=*numAulas;
                }
            }
        }
    }
    return vAula;
}

void quantidadeAulasOnline(tipoAula vAulas[], int numTotalAulas,tipoUc vetorUc[]){
    int contador=0, maior=0, conta=0;
    int i, j;

    if(numTotalAulas==0){
        printf("\nNão existem aulas agendadas.");
    } else {
        for(i=0; i<numTotalAulas; i++){
            contador=0;
            for(j=0; j<numTotalAulas; j++){
                if(vAulas[i].codigo == vAulas[j].codigo){
                    contador++;
                    maior = vAulas[j].codigo;
                }
            }
        }


        printf("\n A disciplina com mais aulas online é: %d \n", maior);
        for(i=0; i<numTotalAulas; i++){
            if(vAulas[i].codigo == maior){
                escreveDadosAulas(vAulas[i]);
                conta++;
            }
        }
    }
}



