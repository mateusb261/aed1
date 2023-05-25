#include <stdio.h>

void processamento(){
    float notas[4], media = 0;
    int i;

    for (i = 0; i < 4; i++){
        printf("Digite a nota %d: \n", i + 1);
        scanf("%f", &notas[i]);
        media += notas[i];
    }

    media /= i;
    printf("\n");
    printf("As notas fornecidas sao:\n");

    for (i = 0; i < 4; i++){
        printf("%.2f\n", notas[i]);
    }

    printf("\n");
    printf("A media das notas e: %.2f\n", media);
}

