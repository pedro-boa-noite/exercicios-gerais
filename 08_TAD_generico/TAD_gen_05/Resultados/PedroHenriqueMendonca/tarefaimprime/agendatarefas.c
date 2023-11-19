#include "tarefaimprime.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include "agendatarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*Fptr)(void*);

typedef struct tTarefa {
    int prioridade;
    void* conteudoDaTarefa;
    Fptr executa; //void (*executa)(void*);
    Fptr destroi; //void (*destroi)(void*);
} tTarefa;

struct agendatarefas{
    tTarefa** tarefas;
    int numElem;
    int numAtualTarefas;
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    tAgendaTarefas* agenda = (tAgendaTarefas*) malloc (sizeof(tAgendaTarefas));

    agenda->tarefas = malloc(sizeof(tTarefa*)*numElem);
    agenda->numElem = numElem;
    agenda->numAtualTarefas = 0;

    return agenda;
}

void DesalocaTarefa(tTarefa* tarefa) {
    tarefa->destroi(tarefa->conteudoDaTarefa);
    free(tarefa);
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
    if(tar != NULL){
        if(tar->tarefas != NULL){
            for(int i=0; i<tar->numElem; i++){
                DesalocaTarefa(tar->tarefas[i]);
            }
            free(tar->tarefas);
        }
        free(tar);
    }
}

tTarefa* CadastraTarefa(void* tarefaAFazer, int prioridade, Fptr executa, Fptr destroi) {
    tTarefa* tarefa = malloc(sizeof(tTarefa));
    tarefa->prioridade = prioridade;
    tarefa->conteudoDaTarefa = tarefaAFazer;
    tarefa->executa = executa;
    tarefa->destroi = destroi;
    return tarefa;
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
    tar->numAtualTarefas += 1;
    tar->tarefas = realloc(tar->tarefas, sizeof(tTarefa*)*(tar->numAtualTarefas));
    tar->tarefas[tar->numAtualTarefas - 1] = CadastraTarefa(tarefa, prioridade, executa, destroi);
}   

void OrdenaTarefas(tTarefa** tarefas, int qtdTarefas) {
    tTarefa* aux;
    for(int i = 0; i < qtdTarefas; i++) {
        for(int j = i+1; j < qtdTarefas; j++) {
            if(tarefas[j]->prioridade > tarefas[i]->prioridade) {
                aux = tarefas[j];
                tarefas[j] = tarefas[i];
                tarefas[i] = aux;
            }
        }
    }
}

void ExecutaTarefa(tTarefa* tarefa) {
    tarefa->executa(tarefa->conteudoDaTarefa);
}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    OrdenaTarefas(tar->tarefas, tar->numAtualTarefas);
    for(int i = 0; i < tar->numAtualTarefas; i++) {
        ExecutaTarefa(tar->tarefas[i]);
    }
}