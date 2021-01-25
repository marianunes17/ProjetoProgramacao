#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_aulasAssistidas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_estatistica.h"
#include "funcoes_estudantes.h"
#include "funcoes_menus.h"
#include "funcoes_uc.h"


tipoAula lerDadosAula(){
    tipoAula aula;

    lerString("Indique Descricao: ", aula.designacao, MAX_STRING);
    lerString("Docente: ", aula.docente, MAX_STRING);

    aula.codigo = 0;
    return aula;
}


int procuraAulaNome(tipoAula vAula[], int num, char procAula[]){
    int i, pos;
    pos = -1;

    for (i=0; i<num; i++){
        if (strcmp(vAula[i].designacao, procAula) == 0){  // Elemento encontrado
            pos = i;       // guarda posição de numero em vAula
            i = num;       // para concluir pesquisa (sair do for)
        }
    }
    return pos;
}


void pesquisaAula(tipoAula vAulas[], tipoAulasAssistidas vAulasAssistidas[], int num, int numAulasAssistidas, tipoUc vetorUc[], int numTotalUc){
    int posAula, codigoUc, posUc;
    char designacao[20];
    int contadorAulas = 0, contadorGravacoes = 0;

    lerString("Designacao da Aula a procurar: ", designacao, MAX_STRING);
    posAula = procuraAulaNome(vAulas,num,designacao);

    codigoUc = vAulas[posAula].codigo;
    posUc = procuraUc(vetorUc, numTotalUc, codigoUc);

    if(posAula == -1){
        printf("A Designação inserida não foi encontrada.");
    }
    else{
        // apresenta os dados da aula inserida
        printf("\n\tDescrição da UC: %s\n",vetorUc[posUc].designacao);
        printf("\tRegime: ");
        if( (strcmp(vetorUc[posUc].regime, "D")==0) ){
            printf("Diurno\n");
        } else {
            printf("Pós-Laboral\n");
        }

        printf("\n\tDescrição da Aula: %s\n",vAulas[posAula].designacao);
        printf("\tDocente: %s\n",vAulas[posAula].docente);
        printf("\tHora de inicio: %d:%d\n",vAulas[posAula].hora.h,vAulas[posAula].hora.m);
        printf("\tHora de Fim: %d:%d\n",vAulas[posAula].horaFim,vAulas[posAula].minFim);
        printf("\tData: %d/%d/%d\n",vAulas[posAula].data.dia,vAulas[posAula].data.mes,vAulas[posAula].data.ano);
        printf("\tEstado da Aula: %s\n",vAulas[posAula].estadoAula);

        if((strcmp(vAulas[posAula].gravacao, "A") != 0) ){
            printf("\tGravacao: " );
            if( (strcmp(vAulas[posAula].gravacao, "S") == 0) ){
                printf("Sim\n");
            } else {
                printf("Nao\n");
            }
        }


        if( (strcmp(vAulas[posAula].estadoAula, "Realizada") == 0)){
            printf("\n\tDados dos alunos que assistiram a aula:\n");
            procuraAulaAssistidaAula(vAulasAssistidas, numAulasAssistidas, designacao, &contadorAulas);
            printf("\t\tNumero de alunos: %d\n", contadorAulas);

            printf("\n\n\tDados dos alunos que assistiram a gravacao:\n");
            procuraAulaAssistidaGravacao(vAulasAssistidas, numAulasAssistidas, designacao, &contadorAulas);
            printf("\t\tNumero de alunos: %d", contadorGravacoes);
        } else {
            if(strcmp(vAulas[posAula].estadoAula, "A decorrer") == 0){
                printf("\n\tDados dos alunos que estão a assistir a aula:\n");
                procuraAulaAssistidaAula(vAulasAssistidas, numAulasAssistidas, designacao, &contadorAulas);
                printf("\t\tNumero de alunos: %d\n", contadorAulas);
            }
        }
        if(strcmp(vAulas[posAula].estadoAula, "Agendada") == 0){
            printf("\n\tAula com estado Agendada. Sem informação adicional.\n");

        }
    }
}

void calculaHora( int *horaF, int *minF){
    int min_hora = 60;
    *horaF=*minF/min_hora;              // calcula a hora
    *minF=(*minF-(min_hora*(*horaF)));  //calcula os minutos
}



int procuraHora(tipoAula vAula[], int numTotalAulas, int codigoUC, int ano, int mes, int dia, int hora, int minuto){
    int i, posicao;
    posicao = -1;

    for (i=0; i<numTotalAulas; i++){
        if(codigoUC == vAula[i].codigo) {
            if (ano == vAula[i].data.ano && mes== vAula[i].data.mes && dia== vAula[i].data.dia){

                if( (hora < vAula[i].hora.h || hora > vAula[i].horaFim) ||  (hora < vAula[i].hora.h && hora > vAula[i].horaFim)){
                    if(minuto < vAula[i].hora.m || minuto > vAula[i].minFim){
                        posicao = i;
                        i = numTotalAulas; // Quando se encontra o codigoUc iguala-se o i=numTotalUc (sair do for)
                    }
                }
            }
        }
    }
    return posicao;
}


tipoAula *acrescentaAula(tipoAula vAula[], int *num, tipoUc vetorUc[], int posUc){
    tipoAula *pAula, dados;
    int posAula, hora, min, horaTotal, duracaoUc=0, horaF=0, minF, quantHorasUc=0, duracaoUcRest=0, posHora;
    int codigoUC, caclHoraTotal=0;
    char regimeUc[3];
    pAula = vAula;

    strcpy(regimeUc,vetorUc[posUc].regime);
    strupr(regimeUc); // coloca string em maiúscula

    duracaoUc = vetorUc[posUc].duracao;
    quantHorasUc = vetorUc[posUc].quantidadeHoras;
    codigoUC = vetorUc[posUc].codigo;

    dados = lerDadosAula();
    posAula = procuraAulaNome(vAula,*num,dados.designacao);


    if(posAula != -1){
        printf("A Designação inserida não foi encontrada.\n");
    }
    else{
        dados.codigo = vetorUc[posUc].codigo;
        strcpy(dados.regimeAula,regimeUc);
        dados.data = lerData();

        // calcula a hora inicio/fim consoante o regime e o tipo de aula
        if(strcmp(regimeUc, "D") == 0){

            printf("Insira as Horas:\n");
            dados.hora = lerHora(8,17);
            hora = dados.hora.h;
            min = dados.hora.m;

            caclHoraTotal = (hora*60) + min; //soma a hora em minutos com os minutos

        }
        else{ // se for do regime pós-laboral

            printf("Insira as Horas:\n");
            dados.hora = lerHora(18,24);
            hora = dados.hora.h;
            min = dados.hora.m;

            caclHoraTotal = (hora*60) + min; // soma a hora em minutos com os minutos
        }

        // calcula hora de FIM
        horaTotal = caclHoraTotal + duracaoUc;
        minF = horaTotal;
        calculaHora(&horaF,&minF);
        dados.horaFim = horaF;
        dados.minFim = minF;

        // verifica se data/hora já existe
        posHora= procuraHora(vAula, *num, codigoUC, dados.data.ano, dados.data.mes, dados.data.dia, dados.hora.h, dados.hora.m );

        if(posHora != -1){
            printf("\n\nNão foi possível marcar uma aula para esta hora, pois já há existe uma com a mesma hora.");
        }
        else{
            printf("\n Inicio da Aula: %d:%d",hora,min);
            printf("\n Fim da Aula: %d:%d\n\n",horaF,minF);

            quantHorasUc = (quantHorasUc*60); // passa horas para minutos
            duracaoUcRest = quantHorasUc - duracaoUc; // faz a redução
            duracaoUcRest = duracaoUcRest/60; // passa minutos para horas
            printf("\n Numero de horas restante na UC %s: %d",vetorUc[posUc].designacao,duracaoUcRest);

            strcpy(dados.estadoAula, "Agendada");
            strcpy(dados.gravacao, "A");

            vAula = realloc(vAula, (*num+1)*sizeof(tipoAula));

            if(vAula == NULL){
                printf("ERRO - impossivel inserir aula");
                vAula = pAula;
            }
            else{
                vAula[*num] = dados;
                (*num)++;

                // atualiza a quantidade de aulas no vetor da UC e a acrescenta +1 à quantidade de aulas agendadas
                vetorUc[posUc].quantidadeHoras = duracaoUcRest;
                vetorUc[posUc].quantidadeAulasAgendadas = vetorUc[posUc].quantidadeAulasAgendadas + 1;

                printf("\n\nAula agendada com sucesso!\n");
            }
        }

    }
    return vAula;
}


void escreveDadosAulas(tipoAula vAulas){
    printf("\n\tDescricao: %s\n",vAulas.designacao);
    printf("\tDocente: %s\n",vAulas.docente);
    printf("\tHora: %d:%d as",vAulas.hora.h,vAulas.hora.m);
    printf(" %d:%d\n",vAulas.horaFim,vAulas.minFim);
    printf("\tData: %d/%d/%d\n",vAulas.data.dia, vAulas.data.mes,vAulas.data.ano);
    printf("\tEstado da Aula: %s\n",vAulas.estadoAula);

    if((strcmp(vAulas.gravacao, "A") != 0) ){
        printf("\tGravacao: " );
        if((strcmp(vAulas.gravacao, "S") == 0)){
            printf("Sim");
        } else {
            printf("Nao");
        }
    }
    printf("\n");
}

void mostrarDadosAula(tipoAula vAulas[], int numAulas) {
    int i;
    if (numAulas == 0) {
        printf("\nNão existem dados referentes às Aulas Online.\n");
    }
    else{
        printf("\n\tListagem de todas as Aulas:\n\n");

        for(i=0; i<numAulas; i++) {
            escreveDadosAulas(vAulas[i]);
        }
    }
}

void lerQuantAulasAgendadas(int *quantidade, tipoAula vAulas[], int numAulas){
    int i, conta=0;

    for (i=0; i<numAulas; i++){
        if (strcmp(vAulas[i].estadoAula, "Agendada") == 0){
            conta++;
        }
    }
    *quantidade = conta;
}

void lerQuantAulasRealizadas(int *quantidade, tipoAula vAulas[], int numAulas){
    int i, conta=0;

    for (i=0; i<numAulas; i++){
        if (strcmp(vAulas[i].estadoAula, "Realizada") == 0){
            conta++;
        }
    }
    *quantidade = conta;
}

void lerQuantAulasGravadas(int *quantidade, tipoAula vAulas[], int numAulas){
    int i, conta=0;

    for (i=0; i<numAulas; i++){
        if (strcmp(vAulas[i].gravacao, "S") == 0){
            conta++;
        }
    }
    *quantidade = conta;
}


void listaAulasAgendadas(tipoAula vAulas[], int numAulas) {
    int i,conta=0;

    if(numAulas == 0){
        printf("Não existem dados referentes às Aulas Online.\n");
     }else{
        for (i=0; i<numAulas; i++){
            if (strcmp(vAulas[i].estadoAula, "Agendada") == 0){
                escreveDadosAulas(vAulas[i]);
                conta++;
            }
        }
        if (conta == 0){
            printf("De momento não existem aulas a agendadas.\n");
        }
    }
}


void listaAulasDecorrer(tipoAula vAulas[], int numAulas) {
    int i, conta=0;

    if(numAulas == 0){
        printf("Não existem dados referentes às Aulas Online.\n");
     }else{

        for (i=0; i<numAulas; i++){
            if (strcmp(vAulas[i].estadoAula, "A decorrer") == 0){
                escreveDadosAulas(vAulas[i]);
                conta++;
            }
        }
        if (conta == 0){
            printf("De momento não existem aulas a decorrer.\n");
        }
    }
}

void listaAulasRealizadas(tipoAula vAulas[], int numAulas) {
    int i,conta=0;

    if(numAulas == 0){
        printf("Não existem dados referentes às Aulas Online.\n");
    }else{
        for (i=0; i<numAulas; i++){
            if (strcmp(vAulas[i].estadoAula, "Realizada") == 0){
                escreveDadosAulas(vAulas[i]);
                conta++;
            }
        }
        if (conta == 0){
            printf("De momento não existem aulas a realizadas.\n");
        }
    }
}


tipoAula *eliminaAula(tipoAula vAula[], int *num, char designacao[], tipoUc vetorUc[], int numTotalUc){
    int i, posAula, codigoUc, posicaoUcVetor, duracaoUc, quantHorasUc;
    char estAula[12], eliminacao;
    tipoAula *pAula;
    pAula = vAula;

    if(*num != 0){

        posAula = procuraAulaNome(vAula, *num, designacao);
        strcpy(estAula,vAula[posAula].estadoAula);

        //vai buscar valores da UC para atualizar a quantidade de horas
        codigoUc = vAula[posAula].codigo;
        posicaoUcVetor = procuraUc(vetorUc, numTotalUc, codigoUc);
        duracaoUc = vetorUc[posicaoUcVetor].duracao;
        quantHorasUc = vetorUc[posicaoUcVetor].quantidadeHoras;


        if(posAula == -1){
            printf ("A Designação inserida não foi encontrada.");
        }
        else{
            if(strcmp(estAula, "Agendada") == 0 ){
                do{
                    printf("\nTem a certeza que quer eliminar a aula %s'?(S-Sim, N-Nao): ", vAula[posAula].designacao);
                    scanf("%c", &eliminacao);
                    limpaBufferStdin();
                    eliminacao = toupper(eliminacao);

                    if(eliminacao!='S' && eliminacao!='N' ){
                        printf("Inseriu uma opcao invalida.\n");
                    }

                }while (eliminacao!='S' && eliminacao!='N');

                if(eliminacao == 'S'){

                    for(i=posAula; i<*num-1; i++){
                        vAula[i] = vAula[i+1];
                    }

                    vAula = realloc(vAula,(*num-1)*sizeof(tipoAula));

                    if(vAula == NULL && (*num-1) != 0){
                        printf ("Erro na alocacao de memoria");
                        vAula = pAula;
                    }
                    (*num)--; // Atualiza numero aulas
                    printf (" Aula eliminada!\n\n");

                    quantHorasUc = (quantHorasUc*60); //passa horas para minutos
                    quantHorasUc += duracaoUc; //faz a redução
                    quantHorasUc = quantHorasUc/60; //passa minutos para horas
                    vetorUc[posicaoUcVetor].quantidadeHoras = quantHorasUc;

                    printf("\n\tA Aula %s foi eliminada. \n", vAula[posAula].designacao);
                }else {
                    printf("\n\tA Aula não foi eliminada. \n");
                }
            }else{
                printf ("\nImpossível  Remover! A aula de %s, está a decorrer ou já foi realizada, por isso não pode ser eliminada \n", vAula[posAula].designacao);
            }
        }
        return vAula;
    }
}


void alteraAulas(tipoAula vAula[], int *numAulas, char designacaoAula[], tipoUc vetorUc[], int numTotalUc){
    int  posAula, i, hora, min, minF, horaF=0, horaTotal, codigoUc, posUc, duracaoUc, caclHoraTotal=0, posHora;
    char opcao, regimeUc[3];

    if(*numAulas == 0 ){
        printf("Não existem dados referentes às Aulas Online.\n");
    }
    else{
        posAula = procuraAulaNome(vAula, *numAulas, designacaoAula);

        if(posAula == -1){
            printf("A designacao inserida nao foi encontrada\n");
        } else {

            for (i=0; i<*numAulas; i++){

                if (strcmp(vAula[i].designacao, designacaoAula) == 0){

                    codigoUc = vAula[posAula].codigo;
                    posUc = procuraUc(vetorUc, numTotalUc, codigoUc);
                    duracaoUc = vetorUc[posUc].duracao;
                    strcpy(regimeUc,vetorUc[posUc].regime);
                    strupr(regimeUc);

                    do{
                        opcao = subMenuAlteraAula();
                        switch(opcao){
                            case 'N':
                                    printf("\tEscolheu a opção de Alterar Nome do Docente\n");
                                    lerString("Insira o novo nome do docente: ", vAula[i].docente, MAX_STRING);
                                    break;
                            case 'D':
                                    printf("\tEscolheu a opção de Alterar Data\n");
                                    vAula[i].data = lerData();
                                    break;
                            case 'H':
                                    printf("\tEscolheu a opção de Alterar Hora\n");

                                    // calcula a hora inicio/fim consoante o regime e o tipo de aula
                                    if(strcmp(regimeUc, "D") == 0){

                                        printf("Insira as Horas:\n");
                                        vAula[posAula].hora = lerHora(8,17);
                                        hora = vAula[posAula].hora.h;
                                        min = vAula[posAula].hora.m;

                                        caclHoraTotal = (hora*60) + min;
                                    }
                                    else{// se for do regime pós-laboral

                                        printf("Insira as Horas:\n");
                                        vAula[posAula].hora = lerHora(18,24);
                                        hora = vAula[posAula].hora.h;
                                        min = vAula[posAula].hora.m;

                                        caclHoraTotal = (hora*60) + min;
                                    }

                                    // calcula hora de FIM
                                    horaTotal = caclHoraTotal + duracaoUc;
                                    minF = horaTotal;
                                    calculaHora(&horaF,&minF);
                                    vAula[posAula].horaFim = horaF;
                                    vAula[posAula].minFim = minF;


                                    posHora= procuraHora(vAula, *numAulas, codigoUc, vAula[posAula].data.ano, vAula[posAula].data.mes, vAula[posAula].data.dia, vAula[posAula].hora.h, vAula[posAula].hora.m );

                                    if(posHora != -1){
                                        printf("\n\nNão foi possível marcar uma aula para esta hora, pois já há existe uma com a mesma hora.");
                                    } else {

                                        printf("\n Inicio da Aula: %d:%d",hora,min);
                                        printf("\n Fim da Aula: %d:%d\n\n",horaF,minF);

                                        printf("\n\nAula Alterada com sucesso!\n");
                                    }

                                    break;
                            case 'V':
                                    break;
                            default: printf("Opção Invalida.");
                        }
                    }while(opcao!='V');

                   i = *numAulas;
                }
            }
        }
    }

}

void comecarAula(tipoAula vAulas[], int numTotalAulas, char designacaoAula[],tipoUc vetorUc[], int numTotalUc){
    int posicao, codigoUc, posUc;
    char estado, opGravacao;

    if(numTotalAulas == 0 ){
        printf("\nNão existem dados referentes às Aulas Online.\n");
    } else {
        posicao=procuraAulaNome(vAulas, numTotalAulas, designacaoAula);

        if(posicao == -1){
            printf ("\nA Designação inserida não foi encontrada.");
        }
        else{

            do{
                //printf("Quer alterar o estado da aula de 'agendada' para 'a decorrer'?(S-Sim, N-Nao): ");
                printf("Pretende dar início à aula de %s?(S-Sim, N-Nao): ",designacaoAula);
                scanf("%c", &estado);
                limpaBufferStdin();
                estado = toupper(estado);

                if(estado!='S' && estado!='N' ){
                    printf("Inseriu uma opcao invalida.\n");
                }

            }while (estado!='S' && estado!='N');

            if(estado == 'S'){

                if(strcmp(vAulas[posicao].estadoAula, "A decorrer") == 0){
                    printf("\nA aula já se encontra a Decorrer!\n");
                }
                else{
                    // procura posicao da UC
                    codigoUc = vAulas[posicao].codigo;
                    posUc = procuraUc(vetorUc, numTotalUc, codigoUc);

                    strcpy(vAulas[posicao].estadoAula, "A decorrer");

                    // gravaçao da Aula
                    do{
                        printf("Pretende gravar a aula?(S-Sim, N-Nao):");
                        scanf("%c", &opGravacao);
                        limpaBufferStdin();
                        opGravacao = toupper(opGravacao);

                        if(opGravacao!='S' && opGravacao!='N' ){
                            printf("Inseriu uma opcao invalida\n");
                        }

                    }while (opGravacao!='S' && opGravacao!='N');

                    if(opGravacao == 'S'){
                        printf("\nComecou a aula de %s, esta aula vai ser gravada.",vAulas[posicao].designacao);
                        strcpy(vAulas[posicao].gravacao, "S");
                        vetorUc[posicao].numGravacoes++;
                    }else{
                        printf("\nComecou a aula de %s, esta aula não vai ser gravada.",vAulas[posicao].designacao);
                        strcpy(vAulas[posicao].gravacao, "N");
                    }

                    // actualiza a quantidade de aulas agendadas no vetor da UC
                    vetorUc[posUc].quantidadeAulasAgendadas = vetorUc[posUc].quantidadeAulasAgendadas - 1;
                }

            }else{
                printf("\nO estado da aula não foi alterado\n");
            }

        }
    }
}



void terminarAula(tipoAula vAulas[], int numTotalAulas, char designacaoAula[],tipoUc vetorUc[],int numTotalUc){
    int posicao,codigoUc,posUc;
    char estado;

    if(numTotalAulas == 0 ){
        printf("Não existem dados referentes às Aulas Online.\n");

    } else {
        posicao=procuraAulaNome(vAulas, numTotalAulas, designacaoAula);

        codigoUc = vAulas[posicao].codigo;
        posUc = procuraUc(vetorUc, numTotalUc, codigoUc);

        if(posicao == -1){
            printf ("A Designação inserida não foi encontrada.");
        }
        else{
            do{
                printf("Pretende terminar a aula de %s? (S-Sim, N-Nao): ",designacaoAula);
                scanf(" %c", &estado);
                limpaBufferStdin();
                estado = toupper(estado);

                if(estado!='S' && estado!='N'){
                    printf("\nInsira a opcao 'S' ou 'N'");
                }
            } while (estado!='S' && estado!='N');

            if(estado == 'S'){
                if(strcmp(vAulas[posicao].designacao, "Realizada") == 0){
                    printf("\nA aula que pretende terminar já se encontra realizada!\n");
                }
                else{
                    strcpy(vAulas[posicao].estadoAula, "Realizada");
                    printf("\nFoi terminada a aula de %s.\n",vAulas[posicao].designacao);
                    vetorUc[posUc].quantAulasRealizadas = vetorUc[posUc].quantAulasRealizadas + 1;
                }
            }
            else{
                printf("\nO estado da aula não foi alterado.\n");
            }
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

        fprintf(ficheiro, "NumAulas: %d\n\n",num);

        for (i=0; i<num; i++){
            fprintf(ficheiro,"Designacao: %s\n",vAulas[i].designacao);
            fprintf(ficheiro,"Docente: %s\n",vAulas[i].docente);
            fprintf(ficheiro,"Codigo UC: %d\n",vAulas[i].codigo);
            fprintf(ficheiro,"Data: %d\t",vAulas[i].data.dia);
            fprintf(ficheiro,"%d\t",vAulas[i].data.mes);
            fprintf(ficheiro,"%d\n",vAulas[i].data.ano);
            fprintf(ficheiro,"Hora de Inicio: %d:%d\n",vAulas[i].hora.h,vAulas[i].hora.m);
            fprintf(ficheiro,"Hora de Fim: %d:%d\n\n",vAulas[i].horaFim,vAulas[i].minFim);
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
        //printf("Aulas escritas gravadas = %d \n", gravarDados);

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
    int i,erro;

    ficheiro = fopen("dadosAulas.txt", "r");

    if (ficheiro == NULL) {
        printf ("Impossível abrir ficheiro");
    }
    else {
        pAula = vAulas;
        fscanf(ficheiro,"Aulas: %d\n", &(*num));

        vAulas = realloc(vAulas,(*num)*sizeof(tipoAula));

        if(vAulas == NULL && *num !=0){
            printf("Erro ao reservar memoria");
            vAulas = pAula;
        }
        else{
            for (i=0; i<*num; i++){
                fprintf(ficheiro,"%s\n",vAulas[i].designacao);
                fgets(vAulas[i].docente,MAX_STRING,ficheiro);
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
