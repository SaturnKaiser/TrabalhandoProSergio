#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_desc(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) { // Ordem decrescente
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int partition_asc(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Ordem crescente
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort_desc(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_desc(arr, low, high);

        quickSort_desc(arr, low, pi - 1);
        quickSort_desc(arr, pi + 1, high);
    }
}

void quickSort_asc(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_asc(arr, low, high);

        quickSort_asc(arr, low, pi - 1);
        quickSort_asc(arr, pi + 1, high);
    }
}

void shuffle(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

int main() {
    int arr[SIZE];
    srand(time(0));

    // Gerar vetor com 100000 números aleatórios
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 9999999;
    }

    // Copiar vetor para preservar valores iniciais entre ordenações
    int arr_copy[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr_copy[i] = arr[i];
    }

    // Ordenar em ordem decrescente e medir o tempo
    clock_t start = clock();
    quickSort_desc(arr, 0, SIZE - 1);
    clock_t end = clock();
    printf("Tempo para ordenar em ordem decrescente: %f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Restaurar o vetor original para ordenação crescente
    for (int i = 0; i < SIZE; i++) {
        arr[i] = arr_copy[i];
    }

    // Ordenar em ordem crescente e medir o tempo
    start = clock();
    quickSort_asc(arr, 0, SIZE - 1);
    end = clock();
    printf("Tempo para ordenar em ordem crescente: %f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Restaurar o vetor original para ordenação mista
    for (int i = 0; i < SIZE; i++) {
        arr[i] = arr_copy[i];
    }

    // Ordenar a primeira metade em ordem crescente e a segunda metade em ordem decrescente e medir o tempo
    start = clock();
    quickSort_asc(arr, 0, SIZE / 2 - 1);           // Primeira metade em ordem crescente
    quickSort_desc(arr, SIZE / 2, SIZE - 1);       // Segunda metade em ordem decrescente
    end = clock();
    printf("Tempo para ordenar a primeira metade crescente e a segunda metade decrescente: %f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Restaurar o vetor original para desordená-lo completamente
    for (int i = 0; i < SIZE; i++) {
        arr[i] = arr_copy[i];
    }

    // Desordenar o vetor e medir o tempo
    start = clock();
    shuffle(arr, SIZE);
    end = clock();
    printf("Tempo para desordenar o vetor: %f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    system("pause");

    return 0;
}
