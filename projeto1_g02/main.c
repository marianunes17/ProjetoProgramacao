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
            case 'U':   printf("Escolheu a op��o U");
                do{
                    opcaoSubMenuUc=subMenuUc(vetorUc);
                    switch(opcaoSubMenuUc){
                        case 'L': //Listar UC
                                printf("Escolheu a op��o: L \n");
                                leFicheiroUcBinario(vetorUc, &numUc);
                                printf("Total de UC: %d\n", numUc);
                                listaDadosUc(vetorUc, numUc);
                                break;
                        case 'I': //Inserir nova UC
                                printf("Escolheu a op��o: I \n");
                                acrescentaUc(vetorUc, &numUc);
                                gravarUcBinario(vetorUc, numUc);
                                gravarUcTexto(vetorUc, numUc);
                                numUc++;
                                break;
                        case 'P': //Procurar UC
                                codigoUc = lerInteiro("Insira um c�digo: ",1,100);

                                p=procuraUc(vetorUc, numUc, codigoUc);

                                if(p==-1){
                                    printf("O c�digo n�o existe");
                                } else{
                                listaDadosUc(vetorUc, numUc);
                                }
                                break;
                        case 'E': //Eliminar UC
                                printf("Escolheu a op��o: E \n");
                                eliminarDoVetor(vetorUc, &numUc);
                                gravarUcBinario(vetorUc, numUc);
                                gravarUcTexto(vetorUc, numUc);
                                break;
                        case 'M': //Modificar UC
                                printf("Escolheu a op��o: M \n");
                                break;
                        case 'V':
                                menu(numUc);
                                break;

                        default: printf("\nOpcao inv�lida");
                    }
                }while(opcaoSubMenuUc!='V');

                break;
            case 'A':
                do{
                opSubmenu = menuAulas();
                switch(opSubmenu){
                    // ----- LISTAR AULA  -----
                    case 'L':
                        printf("Escolheu a op��o de Listar Aulas");

                        break;

                    // ----- AGENDAR AULA  -----
                    case 'A':
                        printf("Escolheu a op��o de Agendar uma Aula");
                        leFicheiroUcBinario(vetorUc, &numUc); // funcao maria

                        codigoUc = lerInteiro("Indique codiogo Uc: ",1,100);
                        posUc = procuraUc(vetorUc, numUc, codigoUc);
                        if(posUc == -1){
                            printf("Uc n�o existe");
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
                                    lerString("Designa��o da Aula a Eliminar: ", desigAula, 30);
                                    //vAulas = eliminaAula(vAulas, &numAula, desigAula);
                                    // s� d� se a aula estiver com estado 'agendada' ou 'realizada'
                                break;

                                // ----- ALTERAR AULA  -----
                                case 'A':
                                    printf("Escolheu a op��o de Alterar um Aula Agendada");
                                            // s� d� se a aula estiver com estado 'agendada'
                                    break;
                                case 'V':
                                    break;
                                default:    printf("\n\n Op��o Inv�lida! Tente Novamente...\n");
                            }
                        }while(opSubmenu2!='V');
                        break;

                    // ----- SAIR SUBMENU  -----
                    case 'V':
                        break;
                    default:    printf("\n\n Op��o Inv�lida! Tente Novamente...\n");
                    }
                }while(opSubmenu!='V');
            break;

            case 'R':   printf("Escolheu a op��o R");
            break;
            case 'E':   printf("Escolheu a op��o E");
            break;
            case 'S':   printf("Escolheu a op��o S");
            break;
            case 'V':
                    printf("Escolheu a op��o R");
                    break;
            case 'F':
                    printf("Escolheu a op��o F \n Fim do Programa");
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


