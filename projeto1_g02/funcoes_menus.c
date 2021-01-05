#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_menus.h"
#include "funcoes_auxiliares.h"
#include "funcoes_uc.h"



//não sei se funciona a 100% !!!!

char menu(int numUc){
    char opcao;
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

void subMenuAulas(){
    char op;

    do{
    printf("\n\n ----------------- Menu das Aulas Online -----------------");
    printf("\n L - Listar Aulas\n A - Agendar Aula\n M - Modificar Aula");
    printf("\n V - Voltar\n\n Insira Opção ->");
    scanf("%c", &op);
    limpaBufferStdin();
    op = toupper(op);


            //op = menu();
            switch(op){
                case 'L':   printf("Escolheu a opção L");
                break;
                case 'A':   printf("Escolheu a opção A");
                break;
                case 'M':   printf("Escolheu a opção M");
                break;
                case 'V':
                break;
                default: printf("\nOpcao inválida");
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
    printf("\n Insira Opção ->");

    scanf("%c", &op);
    limpaBufferStdin();
    op = toupper(op);


            switch(op){
                case 'L':
                        printf("Escolheu a opção: L \n");
                        leFicheiroUcBinario(vetorUc, &numUc);
                        printf("Total de UC: %d", numUc);
                        listaDadosUc(vetorUc, numUc);
                        break;
                case 'I':
                        printf("Escolheu a opção: I \n");
                        acrescentaUc(vetorUc, &numUc);
                        gravarUcBinario(vetorUc, numUc);
                        gravarUcTexto(vetorUc, numUc);
                        numUcs++;
                        break;
                case 'P':
                        printf("Insira um código: ");
                        scanf("%d", &codigoUC);
                        procuraUc(vetorUc, numUc, codigoUC);
                        break;
                case 'E':
                        printf("Escolheu a opção: E \n");
                        eliminarDoVetor(vetorUc, &numUc);
                        gravarUcBinario(vetorUc, numUc);
                        gravarUcTexto(vetorUc, numUc);
                        break;
                case 'M':
                        printf("Escolheu a opção: M \n");
                        break;
                case 'V':
                        menu(numUc);
                        break;

                default: printf("\nOpcao inválida");
            }
        }while(op!='V');
        //return op;
}



