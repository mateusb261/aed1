#include <stdio.h>

void processamento(){
    float lista[10];
    int i;
    for(i = 0; i < 10; i++){
        scanf("%f", & lista[i]); //recebe o valor da posição i do vetor
    }
    
    for(i = 0; i < 10; i++){
        printf("%.1f\n", lista[i]);
    }
}

