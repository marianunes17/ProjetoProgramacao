#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_menus.h"
#include "funcoes_auxiliares.h"
#include "funcoes_uc.h"
#include "funcoes_aulas.h"


char menu(tipoUc vetorUc[], int numTotalUc, tipoAula vAulas[], int numTotalAulas){
    char opcao;
    leFicheiroUcBinario(vetorUc, &numTotalUc);
    vAulas = lerFicheiroBin(vAulas, &numTotalAulas);

    printf("\n\n************************ Menu Principal ************************");
    printf("\nQuantidade de UC's: %d", numTotalUc);
    printf("\t\tQnt. aulas agendadas: %d", numTotalAulas);
    printf("\nQnt. aulas realizadas: **** ");
    printf("\tQnt. aulas gravadas: ****\n");

    printf("\n U - Unidades Curriculares");
    printf("\n A - Aulas online");
    printf("\n S - Salas de Aula online");
    printf("\n R - Raking");
    printf("\n E - Estat�stica");
    printf("\n F - Fim/Sair");
    printf("\n\nInsira Op��o ->");
    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

/*
char menu(){
    char opcao;
    printf("\n\n************************ Menu Principal ************************");
    printf("\nQuantidade de UC's: **** \tQnt. aulas agendadas: ** horas  \nQnt. aulas realizadas: **** \tQnt. aulas gravadas: ****\n");
    printf("\n U - Unidades Curriculares\n A - Aulas online\n R - Raking\n E - Estat�stica");
    printf("\n S - Salas de Aula online\n F - Fim/Sair\n\n Insira Op��o ->");
    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}*/


char menuAulas(){
    char opcao;
    printf("\n\n ----------------- Menu das Aulas Online -----------------");
    printf("\n L - Listar Aulas");
    printf("\n A - Agendar Aula");
    printf("\n M - Modificar Aula");
    printf("\n V - Voltar\n");
    printf("\n Insira Op��o ->");
    scanf(" %c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

char submenuAulas(){
    char opcao;
    printf("\n\n ****--------------- Modificar Aula ---------------****");
    printf("\n E - Eliminar Aula");
    printf("\n A - Alterar Agendamento");
    printf("\n V - Voltar\n");
    printf("\n Insira Op��o ->");
    scanf(" %c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

char subMenuUc(tipoUc vetorUc[]){
    char opcao;

    printf("\n\n ----------------- Menu de Unidades Curriculares -----------------");
    printf("\n L - Listar UC's");
    printf("\n I - Inserir UC");
    printf("\n M - Modificar UC");
    printf("\n E - Eliminar UC");
    printf("\n V - Voltar\n");
    printf("\n Insira Op��o ->");

    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

char subMenuSalasOnline(){
    char opcao;
    printf("\n\n ----------------- Menu Salas de Aula online-----------------");
    printf("\n C - Come�ar Aula");
    printf("\n A - Assistir � Aula");
    printf("\n V - Voltar\n");
    printf("\n Insira Op��o ->");


    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

//Menu para escolher a parte do vetor se quer alterar no vetor Uc
char subMenuAlteraUC(){
    char opcaoUc;
    printf("\n\n Alterar Campo das Unidades Curriculares");
    printf("\n\t A - Designa��o");
    printf("\n\t B - Tipo (T, TP ou PL)");
    printf("\n\t C - Semestre");
    printf("\n\t D - Regime (D,PL)");
    printf("\n\t E - Dura��o de cada aula(em minutos)");
    printf("\n\t V - Voltar\n");
    printf("\n\t Insira Op��o ->");

    scanf(" %c", &opcaoUc);
    opcaoUc = toupper(opcaoUc);
    limpaBufferStdin();
    return opcaoUc;
}

//Menu para escolher a parte do vetor se quer alterar no vetor Aula
char subMenuAlteraAula(){
    char opcao;
    printf("\n\n Alterar Campo das Aulas");
    printf("\n\t N - Designa��o");
    printf("\n\t D - Docente)");
    printf("\n\t V - Voltar\n");
    printf("\n V - Voltar\n");
    printf("\n Insira Op��o ->");
    scanf(" %c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

