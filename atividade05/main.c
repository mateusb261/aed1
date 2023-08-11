/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
    Nome: Lucas Almeida Trovão
    Matrícula: 2215310018
	Curso: Sistemas de Informação
*/

#include <stdio.h>
#include "iterativo.c"
#include "recursivo.c"

int main(int agrc, char** argv)
{
    long int n = fatorial_recursivo(10);
    printf("%d", n);

    return 0;
}