/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
    Nome: Lucas Almeida Trovão
    Matrícula: 2215310018
	Curso: Sistemas de Informação
*/
#include <stdio.h>

long fatorial_iterativo(long n)
{
    long fat;

    if ((n==1) || (n==0))
        fat = 1;
    else
        for (fat = 1; n > 1; n--)
            fat = fat * n;

    return fat;
}
