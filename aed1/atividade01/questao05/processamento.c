#include <stdio.h>

void processamento(){
    int num[20], i, num_par = 0, num_imp = 0;

    for (i = 0; i < 20; i++){
        printf("Digite um numero inteiro: \n");
        scanf("%d", &num[i]);
        if ((num[i] % 2) == 0)
            num_par++;
        if ((num[i]) % 2 != 0)
            num_imp++;
    }

    int par[num_par], impar[num_imp], ind1 = 0, ind2 = 0;
    for (i = 0; i < 20; i++){
        if ((num[i] % 2) == 0) {
            par[ind1] = num[i];
            ind1++;
        }
        if ((num[i] % 2) != 0) {
            impar[ind2] = num[i];
            ind2++;
        }
    }

    printf("\n");
    printf("Os valores do vetor principal e: \n");
    for (i = 0; i < 20; i++){
        printf("%d\n", num[i]);
    }

    printf("\n");
    printf("Os valores do vetor dos pares e: \n");
    for (i = 0; i < num_par; i++){
        printf("%d\n", par[i]);
    }

    printf("\n");
    printf("Os valores do vetor dos impares e: \n");
    for (i = 0; i < num_imp; i++){
        printf("%d\n", impar[i]);
    }
}
