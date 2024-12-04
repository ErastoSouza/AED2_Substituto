#include "insertionSort.h"

void InsertionSort(int vetor[],int n){

    int i, j, k, vaux[n], atual;
    vaux[0] = vetor[0];
    for(i=1;i<n;i++){
        atual = vetor[i];

        for(j=0; j<=i; j++){
            if(j==i){
                vaux[j] = atual;
                break;
            }
            if(atual <= vaux[j]){
                for(k=i-1; k>=j; k--){
                    vaux[k+1] = vaux[k];
                    }
                vaux[j] = atual;
                break;
            }
        }
    }
    for(i=0;i<n;i++){
        vetor[i] = vaux[i];
    }
}
