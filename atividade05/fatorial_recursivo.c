/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
    Nome: Lucas Almeida Trovão
    Matrícula: 2215310018
	Curso: Sistemas de Informação
*/

#include <stdio.h>

long fatorial_recursivo(long n)
{
    if ((n==1) || (n==0))
        return 1;
    else
        return ( fatorial1(n-1)*n );
}