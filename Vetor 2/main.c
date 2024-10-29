#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ARRAY_SIZE 10000 // Você pode ajustar esse tamanho conforme necessário
#define PRINT_SIZE 10000 // AVISO: 10000 para poder ter uma ideia do tempo do método!

// Função para trocar dois elementos
void swap(int* a, int* b) {
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Implementação do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Funções para gerar vetores
void generateDescendingArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i; // Preenche com números de n a 1
    }
}

void generateAscendingArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; // Preenche com números de 1 a n
    }
}

void generateHalfAscendingHalfDescendingArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            arr[i] = i + 1; // Primeira metade crescente
        } else {
            arr[i] = n - i; // Segunda metade decrescente
        }
    }
}

void generateHalfDescendingHalfAscendingArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            arr[i] = n - i; // Primeira metade decrescente
        } else {
            arr[i] = i + 1; // Segunda metade crescente
        }
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Números aleatórios
    }
}

// Função para medir e exibir o tempo de ordenação
void measureSortTime(int arr[], int n) {
    clock_t start, end;
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para ordenar %d números: %f segundos\n", n, time_spent);
}

// Função para imprimir o vetor
void printArray(int arr[], int n) {
    for (int i = 0; i < PRINT_SIZE; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "portuguese");
    srand(time(0));

    long long int arr[ARRAY_SIZE];

    printf("Vetor ordenado decrescentemente:\n");
    generateDescendingArray(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE); // Imprime o vetor original
    measureSortTime(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE); // Imprime o vetor ordenado

    printf("Vetor ordenado crescentemente:\n");
    generateAscendingArray(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE); // Imprime o vetor original
    measureSortTime(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE); // Imprime o vetor ordenado

    printf("Primeira metade crescente, segunda metade decrescente:\n");
    generateHalfAscendingHalfDescendingArray(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE); // Imprime o vetor original
    measureSortTime(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE); // Imprime o vetor ordenado

    printf("Primeira metade decrescente, segunda metade crescente:\n");
    generateHalfDescendingHalfAscendingArray(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE); // Imprime o vetor original
    measureSortTime(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE); // Imprime o vetor ordenado

    printf("Elementos desordenados:\n");
    generateRandomArray(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE); // Imprime o vetor original
    measureSortTime(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE); // Imprime o vetor ordenado

    return 0;
}
