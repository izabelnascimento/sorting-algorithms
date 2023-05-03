#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ordenacao.c"
#define N 10000

// Izabel Nascimento
void lerArquivo(int *numsBubble, int *numsSelection, int *numsInsertion, int *numsMerge, int *numsQuick);
void atualizarArquivo(int algt, int *vet);

int main()
{
    time_t time;
    int *numsBubble, *numsSelection, *numsInsertion, *numsMerge, *numsQuick;

    numsBubble = (int *)malloc(N * sizeof(int));
    numsSelection = (int *)malloc(N * sizeof(int));
    numsInsertion = (int *)malloc(N * sizeof(int));
    numsQuick = (int *)malloc(N * sizeof(int));
    numsMerge = (int *)malloc(N * sizeof(int));
    lerArquivo(numsBubble, numsSelection, numsInsertion, numsMerge, numsQuick);

    time = clock();
    bubbleSort(numsBubble, N);
    time = clock() - time;
    printf("- BUBBLE SORT -\n");
    printf("Tempo de execucao: %.2lf milissegundos\n", ((double)time));
    atualizarArquivo(1, numsBubble);

    time = clock();
    selectionSort(numsSelection, N);
    time = clock() - time;
    printf("- SELECTION SORT -\n");
    printf("Tempo de execucao: %.2lf milissegundos\n", ((double)time));
    atualizarArquivo(2, numsSelection);

    time = clock();
    insertionSort(numsInsertion, N);
    time = clock() - time;
    printf("- INSERTION SORT -\n");
    printf("Tempo de execucao: %.2lf milissegundos\n", ((double)time));
    atualizarArquivo(3, numsInsertion);

    time = clock();
    mergeSort(numsMerge, 0, N);
    time = clock() - time;
    printf("- MERGE SORT -\n");
    printf("Tempo de execucao: %.2lf milissegundos\n", ((double)time));
    atualizarArquivo(4, numsMerge);

    time = clock();
    quickSort(numsQuick, 0, N);
    time = clock() - time;
    printf("- QUICK SORT -\n");
    printf("Tempo de execucao: %.2lf milissegundos\n", ((double)time));
    atualizarArquivo(5, numsQuick);

    return 0;
}

void lerArquivo(int *numsBubble, int *numsSelection, int *numsInsertion, int *numsMerge, int *numsQuick)
{
    FILE *arq;
    arq = fopen("numeros.txt", "r");

    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        getchar();
        exit(0);
    }

    int i = 0;
    char w[100], *y;

    while (fgets(w, 100, arq) != NULL)
    {
        y = malloc(100 * sizeof(int));
        int tam = strlen(w);
        for (int j = 0; j < tam - 1; j++)
        {
            y[j] = w[j];
        }
        numsBubble[i] = atoi(y);
        numsSelection[i] = atoi(y);
        numsInsertion[i] = atoi(y);
        numsMerge[i] = atoi(y);
        numsQuick[i] = atoi(y);
        free(y);
        i++;
    }
    fclose(arq);
}

void atualizarArquivo(int algt, int *vet)
{
    FILE *arq;
    switch (algt)
    {
    case 1:
        arq = fopen("bubbleSort.txt", "w");
        break;
    case 2:
        arq = fopen("selectionSort.txt", "w");
        break;
    case 3:
        arq = fopen("insertionSort.txt", "w");
        break;
    case 4:
        arq = fopen("mergeSort.txt", "w");
        break;
    case 5:
        arq = fopen("quickSort.txt", "w");
        break;
    }

    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo aq\n");
        getchar();
        exit(0);
    }

    char s[200];
    int result;
    for (int i = 0; i < N; i++)
    {
        sprintf(s, "%d", vet[i]);
        result = fputs(s, arq);
        if (result == EOF)
        {
            printf("Erro na gravacao!\n");
        }
        result = fputs("\n", arq);
    }
}
