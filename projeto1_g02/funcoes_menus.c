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
    printf("\nE - Estudantes");
    printf("\nR - Raking");
    printf("\nD - Dados Estatísticos");
    printf("\nF - Fim/Sair");
    printf("\n\nInsira Opção ->");
    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}


char menuAulas(){
    char opcao;
    printf("\n\n ----------------- Sub Menu de Aulas Online -----------------");
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

char subMenuUc(){
    char opcao;

    printf("\n\n ----------------- Sub Menu de Unidades Curriculares -----------------");
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

char subMenuEstudantes(){
    char opcao;

    printf("\n\n ----------------- Sub Menu de Estudantes -----------------");
    printf("\n L - Listar Estudantes");
    printf("\n I - Inserir Estudante");
    printf("\n M - Modificar Estudante");
    printf("\n E - Eliminar Estudante");
    printf("\n V - Voltar\n");
    printf("\n Insira Opção ->");

    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

char subMenuSalasOnline(){
    char opcao;
    printf("\n\n ----------------- Sub Menu Salas de Aula online-----------------");
    printf("\n C - Começar Aula");
    printf("\n A - Assistir à Aula Online");
    printf("\n G - Gravações das aula");
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

//Menu para escolher a parte do vetor se quer alterar no vetor Estudante
char subMenuAlteraEstudante(){
    char opcaoAula;
    printf("\n\n Alterar Dados do Estudante");
    printf("\n\t A - Nome");
    printf("\n\t B - Regime)");
    printf("\n\t V - Voltar\n");
    printf("\n\t Insira Opção ->");

    scanf(" %c", &opcaoAula);
    opcaoAula = toupper(opcaoAula);
    limpaBufferStdin();
    return opcaoAula;
}

