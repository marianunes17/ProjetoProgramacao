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
    tipoAula *vAulas = NULL;   // Ponteiro (para vetor dinamico)
    //tipoAula vAulas[MAX_UC];

    int numUc=0, numAula=0, codigoUc,p,posUc;
    char opcao,opSubmenu, opSubmenu2, desigAula, opcaoSubMenuUc;

   // vAulas = *lerFicheiroBin(vAulas[], &numAula); //carrega os elementos existentes para o vetor



     do{
        opcao = menu(numUc);
        switch(opcao){
            case 'U':   printf("Escolheu a opção U");
                do{
                    opcaoSubMenuUc=subMenuUc(vetorUc);
                    switch(opcaoSubMenuUc){
                        case 'L': //Listar UC
                                printf("Escolheu a opção: L \n");
                                leFicheiroUcBinario(vetorUc, &numUc);
                                printf("Total de UC: %d\n", numUc);
                                listaDadosUc(vetorUc, numUc);
                                break;
                        case 'I': //Inserir nova UC
                                printf("Escolheu a opção: I \n");
                                acrescentaUc(vetorUc, &numUc);
                                gravarUcBinario(vetorUc, numUc);
                                gravarUcTexto(vetorUc, numUc);
                                numUc++;
                                break;
                        case 'P': //Procurar UC
                                codigoUc = lerInteiro("Insira um código: ",1,100);

                                p=procuraUc(vetorUc, numUc, codigoUc);

                                if(p==-1){
                                    printf("O código não existe");
                                } else{
                                listaDadosUc(vetorUc, numUc);
                                }
                                break;
                        case 'E': //Eliminar UC
                                printf("Escolheu a opção: E \n");
                                eliminarDoVetor(vetorUc, &numUc);
                                gravarUcBinario(vetorUc, numUc);
                                gravarUcTexto(vetorUc, numUc);
                                break;
                        case 'M': //Modificar UC
                                printf("Escolheu a opção: M \n");
                                break;
                        case 'V':
                                menu(numUc);
                                break;

                        default: printf("\nOpcao inválida");
                    }
                }while(opcaoSubMenuUc!='V');

                break;
            case 'A':
                do{
                opSubmenu = menuAulas();
                switch(opSubmenu){
                    // ----- LISTAR AULA  -----
                    case 'L':
                        printf("Escolheu a opção de Listar Aulas");

                        break;

                    // ----- AGENDAR AULA  -----
                    case 'A':
                        printf("Escolheu a opção de Agendar uma Aula");
                        leFicheiroUcBinario(vetorUc, &numUc); // funcao maria

                        codigoUc = lerInteiro("Indique codiogo Uc: ",1,100);
                        posUc = procuraUc(vetorUc, numUc, codigoUc);
                        if(posUc == -1){
                            printf("Uc não existe");
                        }
                        else{
                            //vAula = acrescentaAula(vAula,&numAula,vetorUc,codigoUc);
                            acrescentaAula(vAulas,&numAula);
                        }
                        break;

                    // ----- MODIFICAR AULA  -----
                    case 'M':
                        do{
                            opSubmenu2 = menuAulas();
                            switch(opSubmenu2){
                                // ----- ELIMINAR AULA  -----
                                case 'E':
                                    lerString("Designação da Aula a Eliminar: ", desigAula, 30);
                                    //vAulas = eliminaAula(vAulas, &numAula, desigAula);
                                    // só dá se a aula estiver com estado 'agendada' ou 'realizada'
                                break;

                                // ----- ALTERAR AULA  -----
                                case 'A':
                                    printf("Escolheu a opção de Alterar um Aula Agendada");
                                            // só dá se a aula estiver com estado 'agendada'
                                    break;
                                case 'V':
                                    break;
                                default:    printf("\n\n Opção Inválida! Tente Novamente...\n");
                            }
                        }while(opSubmenu2!='V');
                        break;

                    // ----- SAIR SUBMENU  -----
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
            case 'V':
                    printf("Escolheu a opção R");
                    break;
            case 'F':
                    printf("Escolheu a opção F \n Fim do Programa");
                    break;
            default:
                printf("\nOpcao invalida");
       }
    }while(opcao!='F');
/*
    gravaFicheiroBin(vAulas,numAula); //grava os elementos antes de sair do programa

    free(vAulas);  // Liberta memoria do vetor dinamico
*/

    return 0;
}


