#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_estudantes.h"
#include "funcoes_uc.h"
#include "funcoes_aulas.h"
#include "funcoes_menus.h"




int main(){
    setlocale(LC_ALL, "");     // Texto com acentos

    tipoUc vetorUc[MAX_UC];
int numUc=0;
    char opcao;

    do{
        opcao = menu(numUc);
        switch(opcao){
            case 'U':   printf("Escolheu a opção U");
                        subMenuUc(vetorUc, numUc);
                        break;

            case 'A':   printf("Escolheu a opção A");
                        subMenuAulas();
                        break;

            case 'R':   printf("Escolheu a opção R");
                        break;

            case 'E':   printf("Escolheu a opção E");
                        break;

            case 'S':   printf("Escolheu a opção S");
                        break;

            case 'F':
                        break;
            default:
                        printf("\nOpcao invalida");
        }
    } while(opcao!='F');

    return 0;
}


