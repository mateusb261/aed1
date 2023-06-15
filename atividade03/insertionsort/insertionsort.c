/*
   Curso: Sistemas de Informação
   Disciplina: Algoritmos e Estruturas de Dados
   Aluno: Mateus Bastos Magalhães Mar
   Matrícula: 2215310063
*/

#include <stdio.h>

void insertionsort(int tamanho, int vetor[], char tipo_de_ordem)
{
    int i, key, j;

    for (i = 1; i < tamanho; i++)
    {
        key = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > key)
        {
            vetor[j + 1] = vetor[j];
            j = j-1;
        }

        vetor[j + 1] = key;
    }
}

void criar_arquivo_ordenado (int tamanho, int vetor[tamanho], char tipo_de_ordem)
{
    FILE * farq;
    if (tipo_de_ordem == 'c')
    {
        char num[10];
        sprintf(num, "%d", tamanho);
        char aux1[] = "dados/crescente/crescente";
        char aux2[] = ".txt";
        char arquivo[100];
        sprintf(arquivo, "%s%s%s", aux1, num, aux2);
        farq = fopen(arquivo, "w");
    }
    else
    {
        char num[10];
        sprintf(num, "%d", tamanho);
        char aux1[] = "dados/decrescente/decrescente";
        char aux2[] = ".txt";
        char arquivo[100];
        sprintf(arquivo, "%s%s%s", aux1, num, aux2);
        farq = fopen(arquivo, "w");
    }
    fprintf(farq, "%c\n", tipo_de_ordem);
    fprintf(farq, "%d\n", tamanho);
    for(int i = 0; i < tamanho; i++)
    {
        fprintf(farq, "%d\n", vetor[i]);
    }
    fclose(farq);
}
