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

void calculaHora( int *horaF, int *minF){
    int min_hora = 60;
    *horaF=*minF/min_hora; //calcula hora
    *minF=(*minF-(min_hora*(*horaF))); //calcula minutos
}


tipoAula *acrescentaAula(tipoAula vAula[], int *num, tipoUc vetorUc[], int posUc){

    tipoAula *pAula, dados;
    int posAula, hora, min, horaTotal, duracaoUc=0, horaF=0, minF, quantHorasUc, duracaoUcRest=0;
    char regimeUc[3];
    pAula = vAula;

    strcpy(regimeUc,vetorUc[posUc].regime);
    strupr(regimeUc); //por string em maiuscula

    duracaoUc = vetorUc[posUc].duracao;
    quantHorasUc = vetorUc[posUc].quantidadeHoras;

    dados = lerDadosAula();
    posAula = procuraAulaNome(vAula,*num,dados.designacao);


    if(posAula != -1){
        printf("Nome de Aula ja existente\n");
    }
    else{
        dados.codigo = vetorUc[posUc].codigo;
        strcpy(dados.regimeAula,regimeUc);
        dados.data = lerData();

        //calcula a hora inicio/fim consoante o regime e o tipo de aula
        if(strcmp(regimeUc, "D") == 0){

            printf("...regime D, confer -> %s\n",regimeUc);
            //do{

                dados.hora = lerHora(8,18);
                hora = dados.hora.h;
                min = dados.hora.m;
                printf("\n Inicio da Aula: %d:%d",hora,min);

                hora = (hora*60);
                horaTotal = hora + min;

                //calculação da hora de Fim
                horaTotal = horaTotal + duracaoUc;
                minF = horaTotal;
                calculaHora(&horaF,&minF); //funcao calcula hora de FIM
                printf("\n Fim da Aula: %d:%d\n\n",horaF,minF);

                dados.horaFim = horaF;
                dados.minFim = minF;

                quantHorasUc = (quantHorasUc*60); //passa horas para minutos
                duracaoUcRest = quantHorasUc - duracaoUc; //faz a redução
                duracaoUcRest = duracaoUcRest/60; //passa minutos para horas
                printf("\n Numero de horas restante na UC %s: %d",vetorUc[posUc].designacao,duracaoUcRest);

            //}while(hora < 8 || hora > 18);

        }
        else{
            printf("...regime PL, confer -> %s\n",regimeUc);
            //do{
                dados.hora = lerHora(18,24);
                hora = dados.hora.h;
                min = dados.hora.m;
                printf("\n Inicio da Aula: %d:%d",hora,min);

                hora = (hora*60);
                horaTotal = hora + min;

                //calculação da hora de Fim
                horaTotal = horaTotal + duracaoUc;
                minF = horaTotal;
                calculaHora(&horaF,&minF); //funcao calcula hora de FIM
                printf("\n Fim da Aula: %d:%d",horaF,minF);

                dados.horaFim = horaF;
                dados.minFim = minF;

                quantHorasUc = (quantHorasUc*60); //passa horas para minutos
                duracaoUcRest = quantHorasUc - duracaoUc; //faz a redução
                duracaoUcRest = duracaoUcRest/60; //passa minutos para horas
                printf("\n Numero de horas restante na UC %s: %d",vetorUc[posUc].designacao,duracaoUcRest);

            //}while(hora < 18 || hora > 24);

        }

        strcpy(dados.estadoAula, "Agendada");
    }


    vAula = realloc(vAula, (*num+1)*sizeof(tipoAula));

    if(vAula == NULL){
        printf("ERRO - impossivel inserir aula");
        vAula = pAula;
    }else
    {
        vAula[*num] = dados;
        (*num)++;

        //actualizar a quantidade de aulas no vetor da UC
        //vetorUc[posUc].quantidadeHoras = duracaoUcRest;


        printf("\n\nAula agendada com sucesso!\n");

    }

    return vAula;
}


void escreveDadosAulas(tipoAula vAulas){
    printf("\tCodigo UC: %d\n",vAulas.codigo);
    printf("\tDescricao: %s\n",vAulas.designacao);
    printf("\tDocente: %s\n",vAulas.docente);
    printf("\tHora de inicio: %d:%d\n",vAulas.hora.h,vAulas.hora.m);
    printf("\tHora de Fim: %d:%d\n",vAulas.horaFim,vAulas.minFim);
    printf("\tRegime: %s\n",vAulas.regimeAula);
    printf("\tData: %d/%d/%d\n",vAulas.data.dia, vAulas.data.mes,vAulas.data.ano);
    printf("\tEstado da Aula: %s\n\n",vAulas.estadoAula);
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
        fread(&(*num),sizeof(int),1,ficheiro);
        pAula = vAulas;

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

void alteraAulas(tipoAula vAula[], int *numAulas, char designacaoAula[], tipoUc vetorUc[]){
    int  posAula, i, hora, min, horaTotal, duracaoUc=0, horaF=0, minF, quantHorasUc, duracaoUcRest=0;
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
                            case 'A':
                                    printf("Escolheu a opção de Alterar Docente\n");
                                    lerString("Docente: ", vAula[i].docente, MAX_STRING);
                                    break;
                            case 'B':
                                    printf("Escolheu a opção de Alterar Docente\n");

                                    if(strcmp(vetorUc[i].regime, "D") == 0){
                                            vAula[i].hora = lerHora(8,18);
                                            hora = vAula[i].hora.h;
                                            min = vAula[i].hora.m;
                                            printf("\n Inicio da Aula: %d:%d",hora,min);

                                            hora = (hora*60);
                                            horaTotal = hora + min;

                                            //calculação da hora de Fim
                                            horaTotal = horaTotal + duracaoUc;
                                            minF = horaTotal;
                                            calculaHora(&horaF,&minF); //funcao calcula hora de FIM
                                            printf("\n Fim da Aula: %d:%d\n\n",horaF,minF);

                                            vAula[i].horaFim = horaF;
                                            vAula[i].minFim = minF;
                                        } else{
                                            vAula[i].hora = lerHora(18,24);
                                            hora = vAula[i].hora.h;
                                            min = vAula[i].hora.m;
                                            printf("\n Inicio da Aula: %d:%d",hora,min);

                                            hora = (hora*60);
                                            horaTotal = hora + min;

                                            //calculação da hora de Fim
                                            horaTotal = horaTotal + duracaoUc;
                                            minF = horaTotal;
                                            calculaHora(&horaF,&minF); //funcao calcula hora de FIM
                                            printf("\n Fim da Aula: %d:%d",horaF,minF);

                                            vAula[i].horaFim = horaF;
                                            vAula[i].minFim = minF;

                                            quantHorasUc = (quantHorasUc*60); //passa horas para minutos
                                            duracaoUcRest = quantHorasUc - duracaoUc; //faz a redução
                                            duracaoUcRest = duracaoUcRest/60; //passa minutos para horas
                                            printf("\n Numero de horas restante na UC %s: %d",vetorUc[i].designacao,duracaoUcRest);

                                        }
                                    break;
                            case 'c':
                                    printf("Escolheu a opção de Alterar Data\n");
                                    break;
                            case 'V':
                                    printf("Escolheu a opção Voltar atras\n");
                                    break;
                            default: printf("Opção Invalida.");
                        }
                    }while(opcao!='V');

                    gravaFicheiroBin(vAula, *numAulas);

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
    char estadoA;

    if(numTotalAulas == 0 ){
        printf("Não existem Aulas. \n");
    }else{
        posicao=procuraAulaNome(vAulas, numTotalAulas, designacaoAula);
        if(posicao == -1){
            printf ("Aula nao está agendada");
        }
        else{
            printf("Quer alterar o estado da aula de 'agendada' para 'a decorrer'?(S-Sim, N-Nao)  %c: ",estadoA);
            scanf("%c", &estadoA);
            estadoA = toupper(estadoA);

            if(estadoA=='S'){
                for(i=0; i<numTotalAulas; i++){
                      if(( strcmp(vAulas[i].estadoAula, "Agendada")==0)){
                            strcmp(vAulas[i].estadoAula, "A decorrer");
                      }
                    }
                }
             gravaFicheiroBin(vAulas, numTotalAulas);
             gravaFicheiroTextAula(vAulas, numTotalAulas);
            }

        }
    }
