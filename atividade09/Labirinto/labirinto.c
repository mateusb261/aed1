/*
    Integrantes de equipe:

    Nome: Victor Albarado Braga - Matrícula: 2115310065;
	Nome: Mateus Bastos Magalhães Mar - Matrícula: 2215310063.

	Curso: Sistemas de Informação
*/

#include "labirinto.h"
#include <stdio.h>

void imprimir_labirinto(int labirinto[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", labirinto[i][j]);
        }
        printf("\n");
    }
}

int encontrar_caminho(int labirinto[SIZE][SIZE], int x, int y) {
    // Verificar se a posição atual é a posição final
    if (x == SIZE - 1 && y == SIZE - 1) {
        labirinto[x][y] = 3;  // Marcar como caminho correto
        return 1;  // Caminho encontrado
    }

    // Verificar se a posição atual é válida
    if (x >= 0 && y >= 0 && x < SIZE && y < SIZE && labirinto[x][y] == 0) {
        // Marcar a posição como caminho percorrido
        labirinto[x][y] = 2;

        // Tentar mover para a direita
        if (encontrar_caminho(labirinto, x, y + 1)) {
            return 1;
        }

        // Tentar mover para baixo
        if (encontrar_caminho(labirinto, x + 1, y)) {
            return 1;
        }

        // Tentar mover para a esquerda
        if (encontrar_caminho(labirinto, x, y - 1)) {
            return 1;
        }

        // Tentar mover para cima
        if (encontrar_caminho(labirinto, x - 1, y)) {
            return 1;
        }

        // Se nenhum movimento levar ao caminho correto, marcar como beco sem saída
        labirinto[x][y] = 4;
        return 0;
    }

    return 0;  // Posição inválida
}

int ler_labirinto(const char *arquivo, int labirinto[SIZE][SIZE]) {
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (fscanf(file, "%d", &labirinto[i][j]) != 1) {
                printf("Erro ao ler o labirinto do arquivo.\n");
                fclose(file);
                return 0;
            }
        }
    }

    fclose(file);
    return 1;
}
