/*
   Curso: Sistemas de Informação
   Disciplina: Algoritmos e Estruturas de Dados
   Aluno: Mateus Bastos Magalhães Mar
   Matrícula: 2215310063
*/

#include <stdio.h>

void ordenar_vetor (int tamanho, int vetor[tamanho], char tipo_de_ordem)
{
    int parada = 0;
    int variavel_1;
    int variavel_2;
    int troca = 0;

    while (parada < tamanho - 2)
    {
    	parada = 0;

	for (int i = 0; i < tamanho - 1; i++) //passagem pelo vetor
	{
	    variavel_1 = vetor[i];
	    variavel_2 = vetor[i+1];
	    troca = 0;

	    if (tipo_de_ordem == 'c' && variavel_1 > variavel_2)
		troca = 1;
	    if (tipo_de_ordem == 'd' && variavel_1 < variavel_2)
		troca = 1;
	    if (troca)
	    {
		vetor[i] = variavel_2;
		vetor[i+1] = variavel_1;
	    }
	    else
		parada++;
	}
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





