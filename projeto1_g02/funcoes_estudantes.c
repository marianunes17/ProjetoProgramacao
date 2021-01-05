#include <stdio.h>
#include <ctype.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"

tipoEstudante lerDadosEstudante(){
    tipoEstudante e;
    lerString("Indique nome do estudante: ", e.nome, MAX_STRING);
    return e;
}

void mostrarDados(tipoEstudante turma[], int numEstudantes){
    int i;
    for(i=0;i<numEstudantes;i++){
        printf("\nNúmero: %d \t Nome: %s\n", turma[i].numero, turma[i].nome);
    }
}
