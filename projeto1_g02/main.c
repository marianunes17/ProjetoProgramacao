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
    tipoAula *vAulas;   // Ponteiro (para vetor dinamico)
    vAulas = NULL; // iniciar vetor dinamico a NULL

    int numUc=0, numAula=0, codigoUc;
    char opcao,opSubmenu, opSubmenu2, designacao;

    vAulas = lerFicheiroBin(vAulas, &numAula); //carrega os elementos existentes para o vetor


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





    /* ------------- Menu NOVO ------------ */
    /*



     do{
        opcao = menu();
        switch(opcao){
            case 'U':   printf("Escolheu a opção U");
            break;
            case 'A':
                do{
                opSubmenu = menuAulas();
                switch(opSubmenu){
                // ----- LISTAR AULA  -----
                    case 'L':   printf("Escolheu a opção de Listar Aulas");
                        break;

                // ----- AGENDAR AULA  -----
                    case 'A':   printf("Escolheu a opção de Agendar uma Aula");
                        codigoUc = lerInteiro("Indique codiogo Uc: ", 00, 99);
                        vAulas = acrescentaAula(vAulas, &numAula, vetorUc, codigoUc);

                        break;

                // ----- MODIFICAR AULA  -----
                    case 'M':
                        do{
                            opSubmenu2 = submenuAulas();
                            switch(opSubmenu2){
                                 // ----- ELIMINAR AULA  -----
                                case 'E':  lerString("Designação da Aula a Eliminar: ", designacao, 30);
                                           vAulas = eliminaAula(vAulas, &numAula, designacao);
                                           // só dá se a aula estiver com estado 'agendada' ou 'realizada'
                                    break;

                                // ----- ALTERAR AULA  -----
                                case 'A':   printf("Escolheu a opção de Alterar um Aula Agendada");
                                            // só dá se a aula estiver com estado 'agendada'
                                    break;
                                case 'V':
                                    break;
                                default:    printf("\n\n Opção Inválida! Tente Novamente...\n");
                            }
                        }while(opSubmenu2!='V');
                        break;

                    case 'V':
                        break;
                    default:    printf("\n\n Opção Inválida! Tente Novamente...\n");
                    }
                }while(opSubmenu!='V');
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
    }while(opcao!='F');

    gravaFicheiroBin(vAulas,numAula); //grava os elementos antes de sair do programa

    free(vAulas);  // Liberta memoria do vetor dinamico



    */
    /* ------------ FIm Menu NOVO !!!! ----------- */




    return 0;
}


