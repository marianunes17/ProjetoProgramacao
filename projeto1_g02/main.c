#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_estudantes.h"
#include "funcoes_uc.h"
#include "funcoes_aulas.h"
#include "funcoes_menus.h"


int main(){
    setlocale(LC_ALL, "");     // Permite texto com acentos

    tipoUc vetorUc[MAX_UC];
    tipoAula *vAulas;   // Ponteiro (para vetor dinamico)
    vAulas = NULL; // iniciar vetor dinamico a NULL

    int numTotalUc=0, numAula=0, codigoUc,posicaoUcVetor, posicaoAulaVetor;
    char opcao,subMenuAula, subSubMenuAula, designacao[80], opcaoSubMenuUc;

    vAulas = lerFicheiroBin(vAulas, &numAula); //carrega os elementos existentes para o vetor
    leFicheiroUcBinario(vetorUc, &numTotalUc);


     do{
        opcao = menu(vetorUc, numTotalUc);
        switch(opcao){
            case 'U':   printf("Escolheu a opção U");
                do{
                    opcaoSubMenuUc=subMenuUc(vetorUc);
                    switch(opcaoSubMenuUc){
                        case 'L': //Listar UC
                                printf("Escolheu a opção: Listar Unidades Curriculares:");
                                printf("\nTotal de UC: %d\n", numTotalUc);
                                listaDadosUc(vetorUc, numTotalUc);
                                break;

                        case 'I': //Inserir nova UC
                                printf("Escolheu a opção: Inserir nova Unidade Curricular \n");
                                    codigoUc=lerInteiro("\tCodigo: ",1000,2000);
                                    acrescentaUc(vetorUc, &numTotalUc, codigoUc);

                                break;

                        case 'E': //Eliminar UC
                                printf("Escolheu a opção: Eliminar Unidade Curricular \n");
                                eliminarDoVetor(vetorUc, &numTotalUc);
                                break;

                        case 'M': //Modificar UC
                                printf("Escolheu a opção: Modificar Unidade Curricular \n");

                                alterarVetorUc(vetorUc, &numTotalUc);


                                break;

                        case 'V':
                                 printf("\nSair do menu de UC. ");
                                break;

                        default: printf("\nOpcao inválida. ");
                    }
                } while(opcaoSubMenuUc!='V');

                break;
            case 'A':
                do{
                subMenuAula = menuAulas();
                switch(subMenuAula){
                    // ----- LISTAR AULA  -----
                    case 'L':   printf("Escolheu a opção de Listar Aulas");
                        //vAulas = lerFicheiroBin(vAulas, &numAula);
                        mostrarDadosAula(vAulas,numAula);
                        break;

                    // ----- AGENDAR AULA  -----
                    case 'A':
                        printf("Escolheu a opção de Agendar uma Aula");
                        leFicheiroUcBinario(vetorUc, &numTotalUc); // funcao maria

                        codigoUc = lerInteiro("Indique codiogo Uc: ",1000,2000);
                        posicaoUcVetor = procuraUc(vetorUc, numTotalUc, codigoUc);
                        if(posicaoUcVetor == -1){
                            printf("Uc não existe");
                        }
                        else{
                            vAulas = acrescentaAula(vAulas,&numAula,vetorUc,posicaoUcVetor);
                            gravaFicheiroBin(vAulas,numAula);
                            //acrescentaAula(vAulas,&numAula);

                            gravaFicheiroTextAula(vAulas,numAula);
                        }
                        break;

                    // ----- MODIFICAR AULA  -----
                    case 'M':
                        do{
                            subSubMenuAula = submenuAulas();
                            switch(subSubMenuAula){
                                 // ----- ELIMINAR AULA  -----
                                case 'E':  lerString("Designação da Aula a Eliminar: ", designacao, 30);
                                           vAulas = eliminaAula(vAulas, &numAula, designacao);
                                           gravaFicheiroBin(vAulas,numAula);
                                            break;

                                // ----- ALTERAR AULA  -----
                                case 'A':   printf("Escolheu a opção de Alterar um Aula Agendada");
                                            lerString("Designação da Aula: ", designacao, 30);
                                            vAulas = alteraAulas(vAulas, &numAula, designacao);
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

    free(vAulas);  // Liberta memoria do vetor dinamico

    return 0;
}


