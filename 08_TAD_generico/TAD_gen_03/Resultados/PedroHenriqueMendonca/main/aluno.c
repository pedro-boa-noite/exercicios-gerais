#include "aluno.h"
#include <stdlib.h>

struct Aluno{
    char nome[50];
    float nota;
    char genero;
};

/**
 * @brief Aloca memoria para um aluno
 * 
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
tAluno *CriaAluno(){
    tAluno* aluno = (tAluno*) calloc (1, sizeof(tAluno));

    if(aluno == NULL) exit(0);

    return aluno;
}

/**
 * @brief Libera a memoria alocada para um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
*/
void DestroiAluno(data_type aluno){
    free((tAluno*)aluno);
}

/**
 * @brief Le os dados de um aluno
 * 
 * @param aluno Ponteiro para o aluno
*/
void LeAluno(tAluno *aluno){
    scanf("%49[^;];%c;%f", aluno->nome, &aluno->genero, &aluno->nota);
}

/**
 * @brief Retorna o genero de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
*/
char GetGeneroAluno(tAluno *aluno){
    return aluno->genero;
}

/**
 * @brief Retorna a nota de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
*/
float GetNotaAluno(tAluno *aluno){
    return aluno->nota;
}