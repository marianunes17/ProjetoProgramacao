#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_menus.h"
#include "funcoes_auxiliares.h"
#include "funcoes_uc.h"
#include "funcoes_aulas.h"




char menu(tipoUc vetorUc[], int numUc){
    char opcao;
    leFicheiroUcBinario(vetorUc, &numUc);

    printf("\n\n************************ Menu Principal ************************");
    printf("\nQuantidade de UC's: %d", numUc);
    printf("\tQnt. aulas agendadas: ** horas  ");
    printf("\nQnt. aulas realizadas: **** ");
    printf("\tQnt. aulas gravadas: ****\n");

    printf("\n U - Unidades Curriculares\n A - Aulas online\n R - Raking\n E - Estatística");
    printf("\n S - Salas de Aula online\n F - Fim/Sair\n\n Insira Opção ->");
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
    printf("\n L - Listar Aulas\n A - Agendar Aula\n M - Modificar Aula\n E - Eliminar \n P - Procurar");
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
    int codigoUC, numUcs=0;

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



