#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>


#include "constantes.h"
#include "funcoes_menus.h"
#include "funcoes_auxiliares.h"
#include "funcoes_uc.h"
#include "funcoes_aulas.h"


char menu(tipoUc vetorUc[], int numTotalUc, tipoAula vAulas[], int numTotalAulas){
    char opcao;

    printf("\n\n************************ Menu Principal ************************");
    printf("\nQuantidade de UC's: %d", numTotalUc);
    printf("\tQnt. aulas agendadas: %d",numTotalAulas);
    printf("\nQnt. aulas realizadas: **** ");
    printf("\tQnt. aulas gravadas: ****\n");

    printf("\nU - Unidades Curriculares");
    printf("\nA - Aulas online");
    printf("\nS - Salas de Aula online");
    printf("\nE - Estudantes");
    printf("\nR - Raking");
    printf("\nD - Dados Estatísticos");
    printf("\nG - Gravar Dados");
    printf("\nF - Fim/Sair");
    printf("\n\nInsira Opção ->");
    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}


char menuAulas(){
    char opcao;
    printf("\n\n ----------------- Menu Aulas Online -----------------");
    printf("\n L - Listar Aulas");
    printf("\n P - Procurar Aula");
    printf("\n A - Agendar Aula");
    printf("\n M - Modificar Agendamento");
    printf("\n E - Eliminar Aula");
    printf("\n V - Voltar");
    printf("\n\nInsira Opção ->");
    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

char submenuAulas(){
    char opcao;
    printf("\n\n ---------- Sub Menu das Listagens das Aulas  ---------");
    printf("\n Pretende Listas:");
    printf("\n T - Todas as Aula");
    printf("\n A - Aulas Agendadas");
    printf("\n D - Aulas a Decorrer");
    printf("\n R - Aulas Realizadas");
    printf("\n V - Voltar");
    printf("\n\nInsira Opção ->");
    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

char subMenuUc(){
    char opcao;

    printf("\n\n ----------------- Sub Menu de Unidades Curriculares -----------------");
    printf("\n L - Listar UC's");
    printf("\n P - Pesquisar Código UC");
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
    printf("\n T - Terminar Aula");
    printf("\n A - Assistir à Aula Online");
    printf("\n G - Gravações das aula");
    printf("\n V - Voltar\n");
    printf("\n Insira Opção ->");


    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}


char subMenuDadosEstatisticos(){
    char opcaoDados;

    printf("\n\t Q - Quantidade média de presenças em cada aulas online");
    printf("\n\t P - Per)");
    printf("\n\t V - Voltar\n");
    printf("\n\t Insira Opção ->");

    scanf(" %c", &opcaoDados);
    opcaoDados = toupper(opcaoDados);
    limpaBufferStdin();
    return opcaoDados;
}




//Menu para escolher a parte do vetor se quer alterar no vetor Uc
char subMenuAlteraUC(){
    char opcaoUc;
    printf("\n\n Alterar Campo das Unidades Curriculares");
    printf("\n\t A - Designação");
    printf("\n\t B - Tipo de Aula (S-Obrigatorio, N-Opcional)");
    printf("\n\t C - Tipo de UC (T, TP ou PL)");
    printf("\n\t D - Semestre");
    printf("\n\t E - Regime (D,PL)");
    printf("\n\t F - Total de horas previstas");
    printf("\n\t G - Duração de cada aula(em minutos)");
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
    printf("\n\t N - Nome Docente");
    printf("\n\t H - Hora");
    printf("\n\t D - Data");
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
    printf("\n\n Alterar Dados do Estudante: ");
    printf("\n\t A - Nome");
    printf("\n\t B - Regime)");
    printf("\n\t V - Voltar\n");
    printf("\n\t Insira Opção ->");

    scanf(" %c", &opcaoAula);
    opcaoAula = toupper(opcaoAula);
    limpaBufferStdin();
    return opcaoAula;
}
