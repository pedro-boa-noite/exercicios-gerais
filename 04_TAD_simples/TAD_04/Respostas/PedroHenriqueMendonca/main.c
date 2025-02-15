#include <stdio.h>
#include "aluno.h"

int main(){

    int n, num_aprovados=0;
    scanf("%d", &n);
    tAluno aluno, vetor_alunos[n], savevalue;

    for(int i=0; i<n; i++){
        aluno = LeAluno();
        if(VerificaAprovacao(aluno)){
            vetor_alunos[num_aprovados] = aluno;
            num_aprovados++;
        }
    }

    for(int i=0; i<num_aprovados; i++){
        for(int j=i+1; j<num_aprovados; j++){
            if(ComparaMatricula(vetor_alunos[i], vetor_alunos[j]) == 1){
                savevalue = vetor_alunos[i];
                vetor_alunos[i] = vetor_alunos[j];
                vetor_alunos[j] = savevalue;
            }
        }
    }

    for(int i=0; i<num_aprovados; i++){
        ImprimeAluno(vetor_alunos[i]);
    }

    return 0;
}