#include <stdio.h>

void processamento() {

    int vet[5], i;
    for (i = 0; i < 5; i++) {
        scanf("%d", &vet[i]);
    }

    for (i = 0; i < 5; i++) {
        printf("%d\n", vet[i]);
    }
}
