#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_uc.h"
#include "funcoes_estudantes.h"
#include "funcoes_menus.h"


tipoAula lerDadosAula(){
    tipoAula aula;

    lerString("Indique Descricao: ", aula.designacao, MAX_STRING);

    lerString("Docente: ", aula.docente, MAX_STRING);

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



//tipoAula *acrescentaAula(tipoAula vAula[], int *num, tipoUc vetorUc[], int numTotalUc, int codigoUc)
tipoAula *acrescentaAula(tipoAula vAula[], int *num, tipoUc vetorUc[], int posUc){
    tipoAula *pAula, dados;
    int posAula, posicaoUc, i, hora, min, horaTotal;
    char regimeUc[3];
    pAula = vAula;

    //posicaoUc = lerInteiro("Indique codiogo Uc: ",1000,2000);

    dados = lerDadosAula();
    posAula = procuraAulaNome(vAula,*num,dados.designacao);
    strcpy(regimeUc,vetorUc[posUc].regime);
    strupr(regimeUc); //por string em maiuscula

    //posicaoUc = procuraUc(vetorUc, numTotalUc, codigoUc);

    /*if(posAula != -1){
        printf("Nome de Aula existente");
    }else{
        if(posicaoUc != -1){
            printf("O codigo da Unidade Curricular não existe");
        } else{
                leDadosUc(codigoUc);
                for(i=0; i<numTotalUc; i++){
                    if(vetorUc[i].codigo == codigoUc){
                        (strcmp(vetorUc[i].regime, vAula->regimeAula)== 0);
                    }
                }


            }
        }
    }*/
    if(posAula != -1){
        printf("Nome de Aula existente");
    }
    else{
        dados.codigo = vetorUc[posUc].codigo;
        strcmp(vAula->regimeAula,regimeUc);
        dados.data = lerData();

        //calcula a hora inicio/fim consoante o regime e o tipo de aula
        if(regimeUc == 'D'){
            //do{
                //vetorUc.duracao <---

                hora = lerInteiro("\tInsira a hora",8,18);
                min = lerInteiro("\tInsira os minutos",0,59);

                hora = (hora*60);
                min = (min*100)%100;
                horaTotal = hora + min;
                printf("hora: %d min: %d total: %d",hora,min,horaTotal);

            //perguntar hora
            //perguntar minuto

            //}while(hora < 8 || hora > 18);

        }
        else{
            //do{
                hora = lerInteiro("\tInsira a hora",18,24);
                min = lerInteiro("\tInsira os minutos",0,59);

                hora = (hora*60);
                min = (min*100)%100;
                horaTotal = hora + min;
                printf("hora: %d min: %d total: %d",hora,min,horaTotal);


            //perguntar hora
            //perguntar minuto

            //}while(hora < 18 || hora > 24);

        }
    }

           // dados=leDadosUc(codigoUc);
           // (strcmp(vetorUc[i].regime, dados[i].regimeAula) == 0)

      //  dados.codigo = vetorUc[posUc].codigo;
        //dados.tipoDeAula = vetorUc[posUc].tipoAula;
        //strcpy(dados.tipoDeAula,vetorUc[posUc].tipoAula);
        //dados.regimeAula = vetorUc[posUc].regime;
        //dados.data = lerData();


        vAula = realloc(vAula, (*num+1)*sizeof(tipoAula));

        if(vAula == NULL){
            printf("ERRO - impossivel inserir aula");
            vAula = pAula;
        }else{
            vAula[*num] = dados;
            (*num)++;

            //actualizar a quantidade de aulas
            // vetorUc[posUc].quantidadeAulas ...

        }

    return vAula;
}

void escreveDadosAulas(tipoAula vAulas){
    printf("\tCodigo UC: %d\n",vAulas.codigo);
    printf("\tDescricao: %s\n",vAulas.designacao);
    printf("\tDocente: %s\n",vAulas.docente);
    printf("\tTipo de Aula: %\n",vAulas.tipoDeAula);
    printf("\tRegime: %c\n",vAulas.regimeAula);
    printf("\tData: %d/%d/%d\n",vAulas.data.dia, vAulas.data.mes,vAulas.data.ano);
    printf("\tEstado da Aula: %c\n\n",vAulas.estadoAula);
}


void mostrarDadosAula(tipoAula vAulas[], int numAulas) {
    int i;
    if (numAulas == 0) {
        printf("\nSem dados!");
    }
    else{
        printf("\nListagem das Aulas:\n\n");

        for(i=0; i<numAulas; i++) {
            escreveDadosAulas(vAulas[i]);
        }
    }
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
    int i,erro;

    ficheiro = fopen("dadosAulas.txt", "a+");

    if (ficheiro == NULL) {
        printf ("Impossível abrir ficheiro");
    }
    else {

        fprintf(ficheiro, "Lista Todas as Aulas: %d\n\n",num);

        for (i=0; i<num; i++){
            fprintf(ficheiro,"Designacao: %s\n",vAulas[i].designacao);
            fprintf(ficheiro,"Docente: %s\n",vAulas[i].docente);
            fprintf(ficheiro,"Codigo UC: %d\n",vAulas[i].codigo);
            fprintf(ficheiro,"Data: %d\t",vAulas[i].data.dia);
            fprintf(ficheiro,"%d\t",vAulas[i].data.mes);
            fprintf(ficheiro,"%d\n",vAulas[i].data.ano);
        }

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

    if (ficheiro == NULL){
        printf ("Impossível abrir ficheiro");
    }
    else{

        fwrite(&num,sizeof(int),1,ficheiro);
        gravarDados = fwrite(vAulas,sizeof(tipoAula),num,ficheiro);
        printf("Aulas escritas gravadas = %d \n", gravarDados);

        gravaFicheiroTextAula(vAulas,num);

        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d no fecho ficheiro", erro);
        }
    }

}



tipoAula *lerFicheiroTextAula(tipoAula vAulas[],int *num){

    FILE *ficheiro;

    tipoAula *pAula;
    int lerDados,i,erro;

    ficheiro = fopen("dadosAulas.txt", "r");

    if (ficheiro == NULL) {
        printf ("Impossível abrir ficheiro");
    }
    else {
        pAula = vAulas;
        //fprintf(ficheiro,"Lista Aulas: %d\n", *num);
        fscanf(ficheiro,"Aulas: %d\n", &(*num));

        vAulas = realloc(vAulas,(*num)*sizeof(tipoAula));

        if(vAulas == NULL && *num !=0){
            printf("Erro ao reservar memoria");
            vAulas = pAula;
        }
        else{
            for (i=0; i<*num; i++){
                fprintf(ficheiro,"%s\n",vAulas[i].designacao);
                //fprintf(ficheiro,"%s\n",vAulas[i].docente);
                fgets(vAulas[i].docente,MAX_STRING,ficheiro);
                //fprintf(ficheiro,"%d\n",vAulas[i].codigo);
                fscanf(ficheiro,"%d\n",&vAulas[i].codigo);
            }
        }

        erro = fclose(ficheiro);
        if (erro != 0){
            printf ("Erro %d no fecho ficheiro", erro);
        }
    }
    return vAulas;
}


// só dá se a aula estiver com estado 'agendada' ou 'realizada'!!!!!!!!
tipoAula *eliminaAula(tipoAula vAula[], int *num, char designacao[]){
    int i, posAula;
    tipoAula *pAula;
    pAula = vAula; // ponteiro auxiliar

    if(*num != 0){

        posAula = procuraAulaNome(vAula, *num, designacao);

        if(posAula == -1){
            printf ("Aula nao existe!");
        }

        else{
            for(i=posAula; i<*num-1; i++){
                vAula[i] = vAula[i+1];
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

void alteraAulas(tipoAula vAula[], int *numAulas, char designacaoAula[]){
    int  posAula, i;
    char opcao;

    if(*numAulas == 0 ){
        printf("Não existem Aulas\n");
    }
    else{
        posAula = procuraAulaNome(vAula, *numAulas, designacaoAula);

        if(posAula == -1){
            printf("A designacao inserida nao foi encontrada\n");
        } else {

            for (i=0; i<*numAulas; i++){

                if (strcmp(vAula[i].designacao, designacaoAula) == 0){

                    do{
                        opcao = subMenuAlteraAula();
                        switch(opcao){
                            case 'D':
                                    lerString("Indique Descrição: ", vAula[i].designacao, MAX_STRING);
                                    break;
                            case 'N':
                                    lerString("Docente: ", vAula[i].docente, MAX_STRING);
                                    break;
                            case 'V':
                                    break;
                            default: printf("Opção Invalida.");
                        }
                    }while(opcao!='V');

                    gravaFicheiroBin(vAula, *numAulas);
                   //  o ficheiro BIN já grava o TEXT automáticamente
                   //gravaFicheiroTextAula(vAula, *numAulas);

                   i = *numAulas;
                }
            }
        }
    }

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


        printf("\n\t A disciplina com mais aulas online é: %d \n", maior);
        for(i=0; i<numTotalAulas; i++){
            if(vAulas[i].codigo == maior){
                escreveDadosAulas(vAulas[i]);
                conta++;
            }
        }
    }
}

void comecarAula(tipoAula vAulas[], int numTotalAulas, char designacaoAula[]){
    int posicao, i;
    char estadoAula;

    if(numTotalAulas == 0 ){
        printf("Não existem Aulas. \n");
    }else{
        posicao=procuraAulaNome(vAulas, numTotalAulas, designacaoAula);
        if(posicao == -1){
            printf ("Aula nao está agendada");
        }
        else{
            printf("Quer alterar o estado da aula de 'agendada' para 'a realizar'?(S-Sim, N-Nao)  %c: ",estadoAula);
            scanf("%c", &estadoAula);
            estadoAula = toupper(estadoAula);

            if(estadoAula=='S'){
                for(i=0; i<numTotalAulas; i++){
                      if(( strcmp(vAulas[i].estadoAula, designacaoAula)==0)){
                            strcmp(vAulas[i].estadoAula, "Agendada");
                      }
                    }
                }
             gravaFicheiroBin(vAulas, numTotalAulas);
             gravaFicheiroTextAula(vAulas, numTotalAulas);
            }

        }
    }
