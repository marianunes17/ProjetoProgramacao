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
            case 'U':   printf("Escolheu a op��o U");
                do{
                    opcaoSubMenuUc=subMenuUc(vetorUc);
                    switch(opcaoSubMenuUc){
                        case 'L': //Listar UC
                                printf("Escolheu a op��o: L \n");
                                leFicheiroUcBinario(vetorUc, &numUc);
                                printf("\n\nLista de Unidades Curriculares:");
                                printf("\nTotal de UC: %d\n", numUc);
                                listaDadosUc(vetorUc, numUc);
                                break;

                        case 'I': //Inserir nova UC
                                printf("Escolheu a op��o: I \n");
                                do{ //Verifica se o codigo inserido j� existe
                                    codigoUc=lerInteiro("Codigo: ",1000,2000);;
                                    leFicheiroUcBinario(vetorUc, &numUc);
                                    posicao=procuraUc(vetorUc, numUc, codigoUc);

                                    if(posicao==-1){
                                        acrescentaUc(vetorUc, &numUc, codigoUc);
                                        gravarUcBinario(vetorUc, numUc);
                                        gravarUcTexto(vetorUc, numUc);
                                    } else{
                                        printf("O codigo j� existe.");
                                    }
                                } while(posicao!=-1);

                                numUc++;
                                break;

                        case 'P': //Procurar UC
                                leFicheiroUcBinario(vetorUc, &numUc);
                                codigoUc = lerInteiro("Insira um c�digo: ",1000,2000);

                                posicao=procuraUc(vetorUc, numUc, codigoUc);

                                if(posicao==-1){
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

                                codigoUc = lerInteiro("Insira um c�digo: ",1000,2000);
                                posicao=procuraUc(vetorUc, numUc, codigoUc);
                                if(posicao==-1){
                                    printf("O c�digo n�o existe");
                                } else{
                                alterarVetorUc(vetorUc);

                                gravarUcBinario(vetorUc, numUc);
                                gravarUcTexto(vetorUc, numUc);
                                }

                                break;

                        case 'V':
                                 printf("\nSair do menu de UC. ");
                                break;

                        default: printf("\nOpcao inv�lida. ");
                    }
                }while(opcaoSubMenuUc!='V');

                break;
            case 'A':
                do{
                subMenuAula = menuAulas();
                switch(subMenuAula){
                    // ----- LISTAR AULA  -----
                    case 'L':   printf("Escolheu a op��o de Listar Aulas");
                        vAulas = lerFicheiroBin(vAulas, &numAula); //carrega os elementos existentes para o vetor
                        break;

                    // ----- AGENDAR AULA  -----
                    case 'A':
                        printf("Escolheu a op��o de Agendar uma Aula");
                        leFicheiroUcBinario(vetorUc, &numUc); // funcao maria

                        codigoUc = lerInteiro("Indique codiogo Uc: ",1000,2000);
                        posUc = procuraUc(vetorUc, numUc, codigoUc);
                        if(posUc == -1){
                            printf("Uc n�o existe");
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
                                case 'E':  lerString("Designa��o da Aula a Eliminar: ", designacao, 30);
                                           vAulas = eliminaAula(vAulas, &numAula, designacao);
                                           // s� d� se a aula estiver com estado 'agendada' ou 'realizada'
                                    break;

                                // ----- ALTERAR AULA  -----
                                case 'A':   printf("Escolheu a op��o de Alterar um Aula Agendada");
                                            // s� d� se a aula estiver com estado 'agendada'
                                    break;
                                case 'V':
                                    break;
                                default:    printf("\n\n Op��o Inv�lida! Tente Novamente...\n");
                            }
                        }while(subSubMenuAula!='V');
                        break;
                    // ----- SAIR SUBMENU AULA -----
                    case 'V':
                        break;
                    default:    printf("\n\n Op��o Inv�lida! Tente Novamente...\n");
                    }
                }while(subMenuAula!='V');
                break;

            case 'R':   printf("Escolheu a op��o R");
            break;
            case 'E':   printf("Escolheu a op��o E");
            break;
            case 'S':   printf("Escolheu a op��o S");
            break;
            case 'V':
                    printf("Escolheu a op��o V");
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


