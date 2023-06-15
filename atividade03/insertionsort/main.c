/*
   Curso: Sistemas de Informação
   Disciplina: Algoritmos e Estruturas de Dados
   Aluno: Mateus Bastos Magalhães Mar
   Matrícula: 2215310063
*/

#include <stdio.h>
#include <time.h>
#include "insertionsort.c"

int main(int argc, char** argv)
{
    int tamanho;
    char tipo_de_ordem;

    //pegando os dados do vetor
//    printf("tipo de ordem, crescente ou decrescente ('c' ou 'd'): ");
    scanf("%c", &tipo_de_ordem);
//    printf("%c \n", tipo_de_ordem);

//    printf("tamanho do vetor: ");
    scanf("%i", &tamanho);
//    printf("%i\n", tamanho);
    int vetor_principal[tamanho];

//    printf("vetor original: ");
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%i", &vetor_principal[i]);
//      printf("%i ", vetor_principal[i]);
    }

    double start = (double) clock() / CLOCKS_PER_SEC;

    //funçao ordenar_vetor com os parametros de: o tamanho do vetor, o vetor para ordenar,
    //e a forma de ordenaçao crescente ou decrescente ('c' ou 'd')
    insertionsort(tamanho, vetor_principal, tipo_de_ordem);

    double finish = (double) clock() / CLOCKS_PER_SEC;

    double elapsed = (double) finish - start;

    printf("\n%f s \n", elapsed);

    //output do vetor ordenado
/*    printf("\nvetor ordenado: ");
    for (int i = 0; i < tamanho; i++)
        printf("%i ", vetor_principal[i]);
    printf("\n");
*/
    return 0;

}







