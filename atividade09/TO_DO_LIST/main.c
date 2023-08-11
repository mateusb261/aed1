/*
    Integrantes de equipe:

    Nome: Victor Albarado Braga - Matrícula: 2115310065;
	Nome: Mateus Bastos Magalhães Mar - Matrícula: 2215310063.

	Curso: Sistemas de Informação
*/

#include <stdio.h>
#include "todolist.h"
#include <string.h>

int main() {
    FilaTarefas dias[7];

    for (int i = 0; i < 7; i++) {
        inicializarFila(&dias[i]);
    }

    FILE *arquivo = fopen("tarefa.txt", "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[TAMANHO_MAX_LINHA];
    int diaAtual = -1;

    while (fgets(linha, TAMANHO_MAX_LINHA, arquivo)) {
        if (linha[strlen(linha) - 1] == '\n') {
            linha[strlen(linha) - 1] = '\0';
        }

        if (linha[strlen(linha) - 1] == ':') {
            // É um dia da semana
            diaAtual++;
        } else if (diaAtual >= 0 && diaAtual < 7) {
            // É uma tarefa
            enfileirar(&dias[diaAtual], linha);
        }
    }

    fclose(arquivo);

    printf("Lista de Tarefas Atualizada:\n");
    for (int i = 0; i < 7; i++) {
        printf("%s:\n", DIA_SEMANA[i]);
        imprimirFila(&dias[i]);
        printf("\n");
    }

    for (int i = 0; i < 7; i++) {
        imprimirTarefasConcluidas(&dias[i], DIA_SEMANA[i]);
        while (!filaVazia(&dias[i])) {
            desenfileirar(&dias[i]);
        }
    }

    return 0;
}
