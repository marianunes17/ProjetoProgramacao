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

    int numTotalUc=0, numAula=0, codigoUc, posicaoUcVetor, posicaoAulaVetor;
    char opcao,subMenuAula, subSubMenuAula, opcaoSubMenuUc, subMenuSala;
    char designacao;

    vAulas = lerFicheiroBin(vAulas, &numAula); //carrega os elementos existentes para o vetor
    leFicheiroUcBinario(vetorUc, &numTotalUc);

     do{
        opcao = menu(vetorUc, numTotalUc, vAulas, &numAula);
        switch(opcao){
            case 'U':   printf("Escolheu a op��o U");
                do{
                    opcaoSubMenuUc=subMenuUc(vetorUc);
                    switch(opcaoSubMenuUc){
                        case 'L': //Listar UC
                                printf("Escolheu a op��o: Listar Unidades Curriculares:");
                                printf("\nTotal de UC: %d\n", numTotalUc);
                                listaDadosUc(vetorUc, numTotalUc);
                                break;

                        case 'I': //Inserir nova UC
                                printf("Escolheu a op��o: Inserir nova Unidade Curricular \n");
                                    codigoUc=lerInteiro("\tCodigo: ",1000,2000);
                                    acrescentaUc(vetorUc, &numTotalUc, codigoUc);

                                break;

                        case 'E': //Eliminar UC
                                printf("Escolheu a op��o: Eliminar Unidade Curricular \n");
                                eliminarDoVetor(vetorUc, &numTotalUc);
                                break;

                        case 'M': //Modificar UC
                                printf("Escolheu a op��o: Modificar Unidade Curricular \n");
                                alterarVetorUc(vetorUc, &numTotalUc);
                                break;

                        case 'V':
                                 printf("\nSair do menu de UC. ");
                                break;

                        default: printf("\nOpcao inv�lida. ");
                    }
                } while(opcaoSubMenuUc!='V');

                break;
            case 'A':
                do{
                subMenuAula = menuAulas();
                switch(subMenuAula){
                    // ----- LISTAR AULA  -----
                    case 'L':   printf("Escolheu a op��o de Listar Aulas");
                        //vAulas = lerFicheiroBin(vAulas, &numAula);
                        mostrarDadosAula(vAulas,numAula);
                        break;

                    // ----- AGENDAR AULA  -----
                    case 'A':
                        printf("Escolheu a op��o de Agendar uma Aula\n");
                        leFicheiroUcBinario(vetorUc, &numTotalUc); // funcao maria

                        codigoUc = lerInteiro("Indique codiogo Uc: ",1000,2000);
                        posicaoUcVetor = procuraUc(vetorUc, numTotalUc, codigoUc);
                        if(posicaoUcVetor != -1){

                            if(vetorUc[posicaoUcVetor].quantidadeAulas == 0){
                                printf("ja esgotou as horas");
                            }
                            else{
                                printf("Uc: %s", vetorUc[posicaoUcVetor].designacao);
                                printf("\tAinda tem disponivel %d horas\n\n", vetorUc[posicaoUcVetor].quantidadeAulas);
                                vAulas = acrescentaAula(vAulas,&numAula,vetorUc,posicaoUcVetor);
                                gravaFicheiroBin(vAulas,numAula);
                            }
                        }
                        else{
                            //vAulas = acrescentaAula(vAulas,&numAula,vetorUc,posicaoUcVetor);
                            //gravaFicheiroBin(vAulas,numAula);
                            //gravaFicheiroTextAula(vAulas,numAula);
                            printf("Uc n�o existe");
                        }
                        break;

                    // ----- MODIFICAR AULA  -----
                    case 'M':
                        do{
                            subSubMenuAula = submenuAulas();
                            switch(subSubMenuAula){
                                 // ----- ELIMINAR AULA  -----
                                case 'E':  lerString("Designa��o da Aula a Eliminar: ", designacao, MAX_STRING);
                                           vAulas = eliminaAula(vAulas, &numAula, designacao);
                                           gravaFicheiroBin(vAulas,&numAula);
                                    break;

                                // ----- ALTERAR AULA  -----
                                case 'A':   printf("Escolheu a op��o de Alterar um Aula Agendada");
                                            lerString("Designa��o da Aula: ", designacao, MAX_STRING);
                                            alteraAulas(vAulas, &numAula, designacao);
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

            case 'S':   printf("Escolheu a op��o Salas de Aula online");
                        do{
                            subMenuSala = subMenuSalasOnline();
                            switch(subMenuSala){
                                case 'C':
                                        printf("Escolheu a op��o de Come�ar Aula");
                                        lerString("Designa��o da Aula: ", designacao, MAX_STRING);
                                        comecarAula(vAulas, numAula, designacao);
                                        break;
                                case 'A':
                                        printf("Escolheu a op��o de Assistir � aula");
                                        break;
                                case 'V':
                                        printf("\nSair do menu de UC. ");
                                        break;
                                default: printf("\nOpcao inv�lida. ");
                            }
                        }while(subMenuSala!='V');

                        break;
            case 'R':   printf("Escolheu a op��o Raking");

                        break;
            case 'E':   printf("\nEscolheu a op��o Estatistica");
                        quantidadeAulasOnline(vAulas, numAula, vetorUc);
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

    free(vAulas);  // Liberta memoria do vetor dinamico

    return 0;
}


