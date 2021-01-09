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

    printf("\n\n************************ Menu Principal ************************");
    printf("\nQuantidade de UC's: %d", numTotalUc);
    printf("\tQnt. aulas agendadas: ** horas");
    printf("\nQnt. aulas realizadas: **** ");
    printf("\tQnt. aulas gravadas: ****\n");

    printf("\nU - Unidades Curriculares");
    printf("\nA - Aulas online");
    printf("\nS - Salas de Aula online");
    printf("\nR - Raking");
    printf("\nE - Estatística");
    printf("\nF - Fim/Sair");
    printf("\n\nInsira Opção ->");
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
    printf("\n U - Unidades Curriculares\n A - Aulas online\n R - Raking\n E - Estatística");
    printf("\n S - Salas de Aula online\n F - Fim/Sair\n\n Insira Opção ->");
    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}*/


char menuAulas(){
    char opcao;
    printf("\n\n ----------------- Menu das Aulas Online -----------------");
    printf("\n L - Listar Aulas\n A - Agendar Aula\n M - Modificar Aula");
    printf("\n V - Voltar\n\n Insira Opção ->");
    scanf(" %c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

char submenuAulas(){
    char opcao;
    printf("\n\n ****------------**** Modificar Aula ****------------****");
    printf("\n E - Eliminar Aula \n A - Alterar Agendamento");
    printf("\n V - Voltar\n\n Insira Opção ->");
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
    printf("\n Insira Opção ->");

    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

char subMenuSalasOnline(){
    char opcao;
    printf("\n\n ----------------- Menu Salas de Aula online-----------------");
    printf("\n C - Começar Aula");
    printf("\n A - Assistir à Aula");
    printf("\n V - Voltar\n");
    printf("\n Insira Opção ->");


    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

//Menu para escolher a parte do vetor se quer alterar no vetor Uc
char subMenuAlteraUC(){
    char opcaoUc;
    printf("\n\n Alterar Campo das Unidades Curriculares");
    printf("\n\t A - Designação");
    printf("\n\t B - Tipo (T, TP ou PL)");
    printf("\n\t C - Semestre");
    printf("\n\t D - Regime (D,PL)");
    printf("\n\t E - Duração de cada aula(em minutos)");
    printf("\n\t V - Voltar\n");
    printf("\n\t Insira Opção ->");

    scanf(" %c", &opcaoUc);
    opcaoUc = toupper(opcaoUc);
    limpaBufferStdin();
    return opcaoUc;
}

//Menu para escolher a parte do vetor se quer alterar no vetor Aula
char subMenuAlteraAula(){
    char opcaoAula;
    printf("\n\n Alterar Campo das Aulas");
    printf("\n\t A - Designação");
    printf("\n\t B - Docente)");
    printf("\n\t V - Voltar\n");
    printf("\n\t Insira Opção ->");

    scanf(" %c", &opcaoAula);
    opcaoAula = toupper(opcaoAula);
    limpaBufferStdin();
    return opcaoAula;
}

