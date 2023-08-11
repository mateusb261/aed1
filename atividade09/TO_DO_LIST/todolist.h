/*
    Integrantes de equipe:

    Nome: Victor Albarado Braga - Matrícula: 2115310065;
	Nome: Mateus Bastos Magalhães Mar - Matrícula: 2215310063.

	Curso: Sistemas de Informação
*/

#ifndef TODOLIST_H
#define TODOLIST_H

#define TAMANHO_MAX_LINHA 100

typedef struct NodoTarefa {
    char tarefa[TAMANHO_MAX_LINHA];
    struct NodoTarefa *prox;
} NodoTarefa;

typedef struct {
    NodoTarefa *inicio;
    NodoTarefa *fim;
} FilaTarefas;

extern const char *DIA_SEMANA[7];

void inicializarFila(FilaTarefas *fila);
int filaVazia(FilaTarefas *fila);
void enfileirar(FilaTarefas *fila, const char *tarefa);
void desenfileirar(FilaTarefas *fila);
void imprimirFila(FilaTarefas *fila);
void imprimirTarefasConcluidas(FilaTarefas *fila, const char *dia);

#endif // TODOLIST_H
