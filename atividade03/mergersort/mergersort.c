/*------------------------------------------------------------------
	Universidade Federal de Minas Gerais
	Escola de Engenharia
	Programa de Pós-Graduação em Engenharia Elétrica
	Estrutura de Dados e Algoritmos para Eng da Computação
	Prof: Guilherme Augusto
	Aluno: Jucimar Junior ( jucimar.jr@gmail.com )

	Ordena um vetor usando diversos métodos de ordenação

	exemplo de uso: usa quicksort e grava o tempo em q100.txt

	% ./ordenador q 100 < 100.txt > q100.txt
-------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge( int v[], int inicio, int meio, int fim )
{
	int i = inicio;
	int j = meio + 1;
	int k = 0;
	int aux[fim - inicio + 1];

	while ((i <= meio) && (j <= fim))
	{
		if (v[i] <= v[j])
		{
			aux[k] = v[i];
			i++;
		}
		else
		{
			aux[k] = v[j];
			j++;
		}
		k++;
	}

	if (i <= meio)
	{
		j = meio;
		
		while (j >= i)
		{
			v[fim - meio + j] = v[j];
			j--;
		}
	}

	for (i = 0;i < k;i++) 
		v[inicio + i] = aux[i];
}


void mergesort(int inicio, int fim, int v[], char tipo_de_ordem)
{
	if (fim <= inicio) return;

	int m = (fim+inicio)/2;
	
	mergesort(inicio, m, v, 'c');
	
	mergesort(m+1, fim, v, 'c');
	
	merge( v, inicio, m, fim );
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
