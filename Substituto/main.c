#include <stdio.h>
#include <stdlib.h>
#include "bubbleSort.h"
#include "mergeSort.h"
#include "insertionSort.h"

#define MAX 100


int particao(int vetor[], int ini, int fim){
    int pivo = (vetor[ini] + vetor[fim] + vetor[(ini +fim)/2]) / 3;
    while(ini < fim){
        while(ini < fim && vetor[ini]<=pivo){
            ini++;
        }
        while(ini < fim && vetor[fim]>pivo){
            fim--;
        }
        int aux = vetor[ini];
        vetor[ini] = vetor[fim];
        vetor[fim] = aux;
    }
    return ini;
}
void quickSort(int vetor[], int ini, int fim){
    if(ini<fim){
        int pos = particao(vetor, ini, fim);
        quickSort(vetor, ini, pos-1);
        quickSort(vetor, pos, fim);
    }
}


void inicializar(int n, int R[], int altura[], int j, int tamanhos[]){
    for(int i =0; i<tamanhos[j]; i++){
        R[i] = i;
        altura[i] = 0;
    }
}
int busca(int i,int R[]) {
    int j = i;

    while (R[j] != j) {
        j = R[j];
    }
    while (R[i] != j) {
        int k = R[i];
        R[i] = j;
        i = k;
    }
    return j;
}

void unir(int a, int b,int altura[], int R[]) {
    int raizA = busca(a, R);
    int raizB = busca(b, R);

    if (raizA != raizB) {
        if (altura[raizA] > altura[raizB]) {
            R[raizB] = raizA;
        } else if (altura[raizA] < altura[raizB]) {
            R[raizA] = raizB;
        } else {
            R[raizB] = raizA;
            altura[raizA]++;
        }
   }
}

void lerEntrada(const char *nomeArquivo, int *n, int *p, int tamanhos[], int *particoes[]) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(arquivo, "%d", n);

    fscanf(arquivo, "%d", p);

    for (int i = 0; i < *p; i++) {
        fscanf(arquivo, "%d", &tamanhos[i]);
    }
    for (int i = 0; i < *p; i++) {
        particoes[i] = malloc(tamanhos[i] * sizeof(int));
        for (int j = 0; j < tamanhos[i]; j++) {
            fscanf(arquivo, "%d", &particoes[i][j]);
        }
    }

    fclose(arquivo);
}

void exibirDados(int n, int p, int tamanhos[], int *particoes[MAX]) {
    printf("Tamanho do vetor: %d\n", n);
    printf("Quantidade de particoes: %d\n", p);
    printf("Tamanhos das particoes: ");
    for (int i = 0; i < p; i++) {
        printf("%d", tamanhos[i]);
        if (i < p - 1) printf(", ");
    }
    printf("\n");

    printf("Particoes:\n");
    for (int i = 0; i < p; i++) {
        printf("Subconjunto %d: {", i + 1);
        for (int j = 0; j < tamanhos[i]; j++) {
            printf("%d", particoes[i][j]);
            if (j < tamanhos[i] - 1) printf(", ");
        }
        printf("}\n");
    }
}



int main() {
    const char *nomeArquivo = "entrada.txt";
    int n, p, tamanhos[MAX], *particoes[MAX];

    lerEntrada(nomeArquivo, &n, &p, tamanhos, particoes);
    altura[n*p];

    exibirDados(n, p, tamanhos, particoes);
    for(int i =0; i<p; i++){
    inicializar(n, particoes[i], altura, i, tamanhos);
    }

    printf("Representantes apos busca e compressao:\n");
    for (int i = 0; i < n; i++) {
        printf("particao(%d)\n", i);
    }
    int vetor[] = {3,4 ,2, 1};
    quickSort(vetor, 0, 3);
    for (int i = 0; i < p; i++) {
        free(particoes[i]);
    }
    for(int i =0; i<4; i++){
        printf("[%d] ", vetor[i]);
        if(i == 3){
            printf("\n");
        }
    }

    return 0;
}
