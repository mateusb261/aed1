/*
    Integrantes de equipe:

    Nome: Victor Albarado Braga - Matrícula: 2115310065;
	Nome: Mateus Bastos Magalhães Mar - Matrícula: 2215310063.

	Curso: Sistemas de Informação
*/

#include "todolist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *DIA_SEMANA[7] = {
    "Segunda-feira",
    "Terça-feira",
    "Quarta-feira",
    "Quinta-feira",
    "Sexta-feira",
    "Sábado",
    "Domingo"
};

void inicializarFila(FilaTarefas *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(FilaTarefas *fila) {
    return fila->inicio == NULL;
}

void enfileirar(FilaTarefas *fila, const char *tarefa) {
    NodoTarefa *novaTarefa = (NodoTarefa *)malloc(sizeof(NodoTarefa));
    if (novaTarefa == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tarefa.\n");
        exit(1);
    }
    strcpy(novaTarefa->tarefa, tarefa);
    novaTarefa->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novaTarefa;
    } else {
        fila->fim->prox = novaTarefa;
    }
    fila->fim = novaTarefa;
}

void desenfileirar(FilaTarefas *fila) {
    if (filaVazia(fila)) {
        fprintf(stderr, "A fila está vazia, não é possível desenfileirar.\n");
        return;
    }
    NodoTarefa *temp = fila->inicio;
    fila->inicio = fila->inicio->prox;
    free(temp);
}

void imprimirFila(FilaTarefas *fila) {
    NodoTarefa *atual = fila->inicio;
    while (atual != NULL) {
        printf(" %s\n", atual->tarefa);
        atual = atual->prox;
    }
}

void imprimirTarefasConcluidas(FilaTarefas *fila, const char *dia) {
    printf("Tarefas Concluídas para %s:\n", dia);
    imprimirFila(fila);
    printf("\n");
}
