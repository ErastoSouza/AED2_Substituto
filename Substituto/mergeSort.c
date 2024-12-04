#include "mergeSort.h"

void merge(int vetor[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int esquerdo[n1], direito[n2];

    for (int i = 0; i < n1; i++){
        esquerdo[i] = vetor[inicio + i];
    }

    for (int j = 0; j < n2; j++){
        direito[j] = vetor[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (esquerdo[i] <= direito[j]) {
            vetor[k] = esquerdo[i];
            i++;
        } else {
            vetor[k] = direito[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esquerdo[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = direito[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}
