#include "cpd.h"
#include <ctime>
#include <algorithm>

void bubbleSort(int array[], int length) {
    int i, j;
    for(i = length - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(array[j] > array[j+1]) {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void randInt(int array[], int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 100000;
    }
}

void insertionSort(int array[], int length) {
    for (int i = 1; i < length; i++) {
		int escolhido = array[i];
		int j = i - 1;
		
		while ((j >= 0) && (array[j] > escolhido)) {
			array[j + 1] = array[j];
			j--;
		}
		
		array[j + 1] = escolhido;
	}
}

void selectionSort(int vetor[], int tam) {
    for (int indice = 0; indice < tam; ++indice) {
        int indiceMenor = indice;
        for (int indiceSeguinte = indice+1; indiceSeguinte < tam; ++indiceSeguinte) {
            if (vetor[indiceSeguinte] < vetor[indiceMenor]) {
                indiceMenor = indiceSeguinte;
            }
        }
        int aux = vetor[indice];
        vetor[indice] = vetor[indiceMenor];
        vetor[indiceMenor] = aux;
    }
}
