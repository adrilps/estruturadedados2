#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

Aluno * criarAluno(){
    Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));

    if(aluno != NULL){
        aluno->ra = 0;
        aluno->nota = 0.0;
    }
    return aluno;
}

void destruirAluno(Aluno *aluno){
    free(aluno);
}