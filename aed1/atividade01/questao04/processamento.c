#include <stdio.h>

void processamento(){
    float nota, media = 0, media_notas[10];
    int n, i;

    for (n = 0; n < 10; n++) {
        for (i = 0; i < 4; i++) {
            printf("Digite a nota %d do aluno %d: \n", i + 1, n + 1);
            scanf("%f", &nota);
            media += nota;
        }
        media /= 4;
        media_notas[n] = media;
        media = 0;
    }

    int alunos = 0;
    for (n = 0; n < 10; n++){
        if (media_notas[n] >= 7)
            alunos++;
    }

    printf("\n");
    printf("O numero de alunos com media maior ou igual a 7.0 e: %d\n", alunos);
}

