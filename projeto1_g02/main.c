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

    int numUc=0, numAula=0, codigoUc,posicao,posUc;
    char opcao,subMenuAula, subSubMenuAula, designacao[80], opcaoSubMenuUc;

   // vAulas = *lerFicheiroBin(vAulas[], &numAula); //carrega os elementos existentes para o vetor


     do{
        opcao = menu(vetorUc, numUc);
        switch(opcao){
            case 'U':   printf("Escolheu a opção U");
                do{
                    opcaoSubMenuUc=subMenuUc(vetorUc);
                    switch(opcaoSubMenuUc){
                        case 'L': //Listar UC
                                printf("Escolheu a opção: L \n");
                                leFicheiroUcBinario(vetorUc, &numUc);
                                printf("\n\nLista de Unidades Curriculares:");
                                printf("\nTotal de UC: %d\n", numUc);
                                listaDadosUc(vetorUc, numUc);
                                break;

                        case 'I': //Inserir nova UC
                                printf("Escolheu a opção: I \n");
                                do{ //Verifica se o codigo inserido já existe
                                    codigoUc=lerInteiro("Codigo: ",1000,2000);;
                                    leFicheiroUcBinario(vetorUc, &numUc);
                                    posicao=procuraUc(vetorUc, numUc, codigoUc);

                                    if(posicao==-1){
                                        acrescentaUc(vetorUc, &numUc, codigoUc);
                                        gravarUcBinario(vetorUc, numUc);
                                        gravarUcTexto(vetorUc, numUc);
                                    } else{
                                        printf("O codigo já existe.");
                                    }
                                } while(posicao!=-1);

                                numUc++;
                                break;

                        case 'P': //Procurar UC
                                leFicheiroUcBinario(vetorUc, &numUc);
                                codigoUc = lerInteiro("Insira um código: ",1000,2000);

                                posicao=procuraUc(vetorUc, numUc, codigoUc);

                                if(posicao==-1){
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

                                codigoUc = lerInteiro("Insira um código: ",1000,2000);
                                posicao=procuraUc(vetorUc, numUc, codigoUc);
                                if(posicao==-1){
                                    printf("O código não existe");
                                } else{
                                alterarVetorUc(vetorUc);

                                gravarUcBinario(vetorUc, numUc);
                                gravarUcTexto(vetorUc, numUc);
                                }

                                break;

                        case 'V':
                                 printf("\nSair do menu de UC. ");
                                break;

                        default: printf("\nOpcao inválida. ");
                    }
                }while(opcaoSubMenuUc!='V');

                break;
            case 'A':
                do{
                subMenuAula = menuAulas();
                switch(subMenuAula){
                    // ----- LISTAR AULA  -----
                    case 'L':   printf("Escolheu a opção de Listar Aulas");
                        vAulas = lerFicheiroBin(vAulas, &numAula); //carrega os elementos existentes para o vetor
                        break;

                    // ----- AGENDAR AULA  -----
                    case 'A':
                        printf("Escolheu a opção de Agendar uma Aula");
                        leFicheiroUcBinario(vetorUc, &numUc); // funcao maria

                        codigoUc = lerInteiro("Indique codiogo Uc: ",1000,2000);
                        posUc = procuraUc(vetorUc, numUc, codigoUc);
                        if(posUc == -1){
                            printf("Uc não existe");
                        }
                        else{
                            vAulas = acrescentaAula(vAulas,&numAula,vetorUc,codigoUc);
                            gravaFicheiroBin(vAulas,numAula);
                            //acrescentaAula(vAulas,&numAula);

                            gravaFicheiroTextAula(vAulas,numAula);
                        }
                        break;

                    // ----- MODIFICAR AULA  -----
                    case 'M':
                        do{
                            subSubMenuAula = menuAulas();
                            switch(subSubMenuAula){
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
                        }while(subSubMenuAula!='V');
                        break;
                    // ----- SAIR SUBMENU AULA -----
                    case 'V':
                        break;
                    default:    printf("\n\n Opção Inválida! Tente Novamente...\n");
                    }
                }while(subMenuAula!='V');
                break;

            case 'R':   printf("Escolheu a opção R");
            break;
            case 'E':   printf("Escolheu a opção E");
            break;
            case 'S':   printf("Escolheu a opção S");
            break;
            case 'V':
                    printf("Escolheu a opção V");
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


