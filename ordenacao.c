
void bubbleSort(int *vet, int n)
{
    int i, j, aux;
    for (i = n - 1; i >= 1; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

void selectionSort(int *vet, int n)
{
    int min, i, j, aux;
    for (i = 0; i <= n - 2; i++)
    {
        min = i;
        for (j = i + 1; j <= n - 1; j++)
        {
            if (vet[j] < vet[min])
            {
                min = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

void insertionSort(int *vet, int n)
{
    int key, i, j;
    for (j = 1; j < n; j++)
    {
        key = vet[j];
        i = j - 1;
        while (i >= 0 && vet[i] > key)
        {
            vet[i + 1] = vet[i];
            i = i - 1;
        }
        vet[i + 1] = key;
    }
}

void merge(int *vet, int inicio, int meio, int fim)
{
    int a = meio - inicio + 1;
    int b = fim - meio;
    int *left, *right, i, j, k;

    left = malloc(a * sizeof(int));
    right = malloc(b * sizeof(int));

    for (i = 0; i < a; i++)
    {
        left[i] = vet[inicio + i];
    }
    for (j = 0; j < b; j++)
    {
        right[j] = vet[meio + j + 1];
    }
    i = 0;
    j = 0;
    k = inicio;
    while (i < a && j < b)
    {
        if (left[i] <= right[j])
        {
            vet[k] = left[i];
            i++;
        }
        else
        {
            vet[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < a)
    {
        vet[k] = left[i];
        i++;
        k++;
    }
    while (j < b)
    {
        vet[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *vet, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}

int quick(int *vet, int inicio, int fim)
{
    int pivo = vet[fim - 1];
    int i = inicio - 1;
    int j, aux;
    for (j = inicio; j < fim; j++)
    {
        if (vet[j] <= pivo)
        {
            i++;
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    }
    aux = vet[i + 1];
    vet[i] = vet[fim - 1];
    vet[fim - 1] = aux;
    return i;
}

void quickSort(int *vet, int inicio, int fim)
{
    if (inicio < fim)
    {
        int novo = quick(vet, inicio, fim);
        quickSort(vet, inicio, novo);
        quickSort(vet, novo + 1, fim);
    }
}
