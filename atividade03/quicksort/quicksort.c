/*
   Curso: Sistemas de Informação
   Disciplina: Algoritmos e Estruturas de Dados
   Aluno: Mateus Bastos Magalhães Mar
   Matrícula: 2215310063
*/

#include <stdio.h>

int partition(int inicio, int fim, int v[] ) {
	int i = inicio-1, j = fim; 
	int x = v[fim];
	int t;
	
	for (;;) {
		while ( v[++i] < x ) ;
		while ( x < v[--j] ) if ( j == inicio ) break;
		if ( i >= j ) break;
		
		t = v[i];
		v[i] = v[j];
		v[j] = t;
	}
	
	t = v[i];
	v[i] = v[fim];
	v[fim] = t;
	
	return i;
}

void quicksort( int inicio, int fim, int v[], char tipo_de_ordem)
{
	if (fim <= inicio) return;
	
	int i = partition( inicio, fim, v );

	quicksort( inicio, i-1, v, 'c');
	quicksort( i+1, fim,v, 'c' );
}
