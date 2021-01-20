#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>


#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_estudantes.h"
#include "funcoes_uc.h"
#include "funcoes_aulas.h"
#include "funcoes_estudantes.h"
#include "funcoes_menus.h"


int main(){
    setlocale(LC_ALL,"Portuguese");    // Permite texto com acentos

    tipoUc vetorUc[MAX_UC];
    tipoAula *vAulas;   // Ponteiro (para vetor dinamico)
    vAulas = NULL; // iniciar vetor dinamico a NULL
    tipoEstudante vEstudante[MAX_ESTUDANTES];

    int numTotalUc=0, numAula=0, numTotalEstudantes=0;
    int codigoUc, numeroEstudante, posicaoUcVetor, posicaoAulaVetor;
    char opcao,subMenuAula, subSubMenuAula, opcaoSubMenuUc, subMenuSala, subMenuEstudante;
    char designacao[80];

    vAulas = lerFicheiroBin(vAulas, &numAula); //carrega os elementos existentes para o vetor
    leFicheiroUcBinario(vetorUc, &numTotalUc);
    leEstudantesBinario(vEstudante, &numTotalEstudantes);


     do{
        opcao = menu(vetorUc, numTotalUc, vAulas, numAula);
        switch(opcao){
            case 'U':   printf("Escolheu a op��o U");
                do{
                    opcaoSubMenuUc=subMenuUc(vetorUc);
                    switch(opcaoSubMenuUc){
                        case 'L': //Listar UC
                                printf("Escolheu a op��o: Listar Unidades Curriculares:\n");
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
                                eliminarVetorUc(vetorUc, &numTotalUc);
                                break;

                        case 'M': //Modificar UC
                                printf("Escolheu a op��o: Modificar Unidade Curricular \n");
                                alterarVetorUc(vetorUc, numTotalUc);
                                break;


                        case 'P': //Modificar UC
                                printf("Escolheu a op��o: Pesquisar Unidade Curricular \n");
                                pesquisaCodigoUc(vetorUc, numTotalUc);
                                break;

                        case 'V':
                                 printf("\nSair do menu de UC. ");
                                //gravarUcBinario(vetorUc, numTotalUc);
                                //gravarUcTexto(vetorUc, numTotalUc);

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
                    case 'L':
                        printf("Escolheu a op��o: Listagem de Aulas\n");
                        //mostrarDadosAula(vAulas,numAula);
                         do{
                            subSubMenuAula = submenuAulas();
                            switch(subSubMenuAula){
                                 // ----- LISTAR TODAS AULAS  -----
                                case 'T':
                                    printf("Escolheu a op��o na Listagem das Aulas\n");
                                    mostrarDadosAula(vAulas,numAula);
                                    break;

                                // ----- LISTAR AULAS AGENDADAS -----
                                case 'A':
                                    printf("Escolheu a op��o das Aulas Agendadas\n");
                                    break;

                                // ----- LISTAR AULAS A DECORRER -----
                                case 'D':
                                    printf("Escolheu a op��o das Aulas A Decorrer\n");
                                    break;

                                // ----- LISTAR AULAS REALIZADAS -----
                                case 'R':
                                    printf("Escolheu a op��o das Aulas Realizadas\n");
                                    break;

                                case 'V':
                                    break;
                                default:    printf("\n\n Op��o Inv�lida\n");
                            }
                        }while(subSubMenuAula!='V');

                        break;

                    // ----- PROCURAR AULA  -----
                    case 'P':
                        printf("Escolheu a op��o: Procurar Aula\n");
                        pesquisaAula(vAulas, numAula);
                        break;

                    // ----- AGENDAR AULA  -----
                    case 'A':
                            printf("Escolheu a op��o: Agendar uma Aula\n\n");

                            codigoUc = lerInteiro("Indique codiogo Uc: ",1000,2000);
                            posicaoUcVetor = procuraUc(vetorUc, numTotalUc, codigoUc); // funcao Maria
                            if(posicaoUcVetor == -1){
                                printf("Uc inserida n�o foi encontrada, ou n�o existe!");
                            }
                            else{
                                if(vetorUc[posicaoUcVetor].quantidadeHoras == 0){
                                    printf("Esgotou as horas para o agendamento");
                                }
                                else{
                                    printf("Uc de %s", vetorUc[posicaoUcVetor].designacao);
                                    printf(" e ainda tem disponivel %d horas\n", vetorUc[posicaoUcVetor].quantidadeHoras);
                                    vAulas = acrescentaAula(vAulas,&numAula,vetorUc,posicaoUcVetor);
                                }
                            }
                            break;

                    // ----- MODIFICAR AGENDAMENTO  -----
                    case 'M':
                            lerString("Designa��o da Aula que prentende alterar: ", designacao, MAX_STRING);
                            alteraAulas(vAulas, &numAula, designacao, vetorUc, numTotalUc);
                            break;

                    // ----- ELIMINAR AULA  -----
                    case 'E':
                            lerString("Designa��o da Aula a Eliminar: ", designacao, MAX_STRING);
                            vAulas = eliminaAula(vAulas, &numAula, designacao, vetorUc, numTotalUc);
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
                                        printf("Escolheu a op��o de Come�ar Aula\n");
                                        lerString("Designa��o da Aula: ", designacao, MAX_STRING);
                                        comecarAula(vAulas, numAula, designacao, vetorUc, numTotalUc);
                                        break;
                                case 'T':
                                        printf("Escolheu a op��o de Terminar Aula\n");
                                        lerString("Designa��o da Aula: ", designacao, MAX_STRING);
                                        terminarAula(vAulas, numAula, designacao);
                                        break;
                                case 'A':
                                        printf("Escolheu a op��o de Assistir � aula\n");
                                        lerString("Designa��o da Aula que pretende assistir: ", designacao, MAX_STRING);
                                        assistirAula(vEstudante, numTotalEstudantes, vAulas, numAula, designacao);

                                        break;
                                case 'G':
                                        printf("Escolheu a op��o de Ver Grava��es\n");
                                        lerString("Designa��o da Aula da qual pretende ver a grava��o: ", designacao, MAX_STRING);
                                        assistirGravacaoAula(vEstudante, numTotalEstudantes, vAulas,  numAula, designacao);
                                        break;
                                case 'V':
                                        break;
                                default: printf("\nOpcao inv�lida. \n");
                            }
                        }while(subMenuSala!='V');
                        break;

            case 'E':   printf("Escolheu a op��o Estudantes");
                        do{
                            subMenuEstudante = subMenuEstudantes();
                            switch(subMenuEstudante){
                                case 'L': //Listar Estudante
                                        printf("Escolheu a op��o: Listar Estudantes:\n");
                                        printf("\nTotal de Estudantes: %d\n", numTotalEstudantes);
                                        listaDadosEstudante(vEstudante, numTotalEstudantes);
                                        break;

                                case 'I': //Inserir novo Estudante
                                        printf("Escolheu a op��o: Inserir um novo Estudante \n");
                                        numeroEstudante=lerInteiro("\tNumero de Estudante: ",1000,2000);
                                        acrescentaEstudante(vEstudante, &numTotalEstudantes, numeroEstudante);

                                        break;

                                case 'E': //Eliminar Estudante
                                        printf("Escolheu a op��o: Eliminar Estudante \n");
                                        eliminarEstudante(vEstudante, &numTotalEstudantes);
                                        break;

                                case 'M': //Modificar Estudante
                                        printf("Escolheu a op��o: Modificar dados de um Estudante \n");
                                        alterarVetorEstudante(vEstudante, numTotalEstudantes);
                                        break;
                                case 'V':
                                        printf("\nSair do menu de UC. ");
                                        gravarEstudantesBinario(vEstudante, numTotalEstudantes);
                                        gravarEstudantesTexto(vEstudante, numTotalEstudantes);
                                        break;
                                default: printf("\nOpcao inv�lida. ");
                            }
                        }while(subMenuEstudante!='V');

                        break;
            case 'R':   printf("Escolheu a op��o Raking");

                        break;
            case 'D':   printf("\nEscolheu a op��o Dados Estatisticos");
                       /* printf("\n\tPercentagem de Ucs com aulas gravadas:");

                        printf("\n\tUC(s) com a menor quantidade de aulas online realizadas: ");*/

                        printf("\n\tUC(s) com a maior quantidade de aulas online realizadas: ");
                        quantidadeAulasOnline(vAulas, numAula, vetorUc);


                       /* printf("\n\tTipo de aula com a maior quantidade de acessos �s grava��es: ");
                        printf("\n\tAula(s) online realizada(s) h� mais tempo.: ");*/
                        break;
            case 'G':
                        printf("\tEscolheu de Gravar Dados");
                        gravaFicheiroBin(vAulas,numAula);
                        gravarUcBinario(vetorUc, &numTotalUc);
                        printf("\tGravacao Concluida!");
                        break;
            case 'F':
                    printf("Escolheu a op��o F \n Fim do Programa");
                    break;
            default:
                printf("\nOpcao invalida");
       }
    }while(opcao!='F');

    gravaFicheiroBin(vAulas, numAula); // grava automaticamente o ficheiro TXT
        printf("\n gravou aula"); // para confirmar se d� - tirar depois

    gravarUcTexto(vetorUc, numTotalUc);
        printf("\n gravou uc bin"); // para confirmar se d� - tirar depois
    gravarUcBinario(vetorUc, &numTotalUc);
        printf("\n gravou uc txt"); // para confirmar se d� - tirar depois

    free(vAulas);  // Liberta memoria do vetor dinamico

    return 0;
}


