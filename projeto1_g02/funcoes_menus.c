#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_menus.h"
#include "funcoes_auxiliares.h"
#include "funcoes_uc.h"



//n�o sei se funciona a 100% !!!!

char menu(int numUc){
    char opcao;
    printf("\n\n************************ Menu Principal ************************");
    printf("\nQuantidade de UC's: %d", numUc);
    printf("\tQnt. aulas agendadas: ** horas  ");
    printf("\nQnt. aulas realizadas: **** ");
    printf("\tQnt. aulas gravadas: ****\n");

    printf("\n U - Unidades Curriculares\n A - Aulas online\n R - Raking\n E - Estat�stica");
    printf("\n S - Salas de Aula online\n F - Fim/Sair\n\n Insira Op��o ->");
    scanf("%c", &opcao);
    limpaBufferStdin();
    opcao = toupper(opcao);
    return opcao;
}

void subMenuAulas(){
    char op;

    do{
    printf("\n\n ----------------- Menu das Aulas Online -----------------");
    printf("\n L - Listar Aulas\n A - Agendar Aula\n M - Modificar Aula");
    printf("\n V - Voltar\n\n Insira Op��o ->");
    scanf("%c", &op);
    limpaBufferStdin();
    op = toupper(op);


            //op = menu();
            switch(op){
                case 'L':   printf("Escolheu a op��o L");
                break;
                case 'A':   printf("Escolheu a op��o A");
                break;
                case 'M':   printf("Escolheu a op��o M");
                break;
                case 'V':
                break;
                default: printf("\nOpcao inv�lida");
            }
        }while(op!='V');
        //return op;
}




void subMenuUc(tipoUc vetorUc[], int numUc){
    char op;
    int codigoUC, numUcs=0;
       do{
    printf("\n\n ----------------- Menu de Unidades Curriculares -----------------");
    printf("\n L - Listar UC's");
    printf("\n I - Inserir UC");
    printf("\n P - Procurar UC");
    printf("\n M - Modificar UC");
    printf("\n E - Eliminar UC");
    printf("\n V - Voltar\n");
    printf("\n Insira Op��o ->");

    scanf("%c", &op);
    limpaBufferStdin();
    op = toupper(op);


            switch(op){
                case 'L':
                        printf("Escolheu a op��o: L \n");
                        leFicheiroUcBinario(vetorUc, &numUc);
                        printf("Total de UC: %d", numUc);
                        listaDadosUc(vetorUc, numUc);
                        break;
                case 'I':
                        printf("Escolheu a op��o: I \n");
                        acrescentaUc(vetorUc, &numUc);
                        gravarUcBinario(vetorUc, numUc);
                        gravarUcTexto(vetorUc, numUc);
                        numUcs++;
                        break;
                case 'P':
                        printf("Insira um c�digo: ");
                        scanf("%d", &codigoUC);
                        procuraUc(vetorUc, numUc, codigoUC);
                        break;
                case 'E':
                        printf("Escolheu a op��o: E \n");
                        eliminarDoVetor(vetorUc, &numUc);
                        gravarUcBinario(vetorUc, numUc);
                        gravarUcTexto(vetorUc, numUc);
                        break;
                case 'M':
                        printf("Escolheu a op��o: M \n");
                        break;
                case 'V':
                        menu(numUc);
                        break;

                default: printf("\nOpcao inv�lida");
            }
        }while(op!='V');
        //return op;
}



