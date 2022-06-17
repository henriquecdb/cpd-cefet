#include <bits/stdc++.h>

using namespace std;

const int tam = 100000;

typedef struct hash {
    int chave;
    hash* prox;
} Hash;

void inserir (Hash* tabela[], int pos, int n) {
    Hash* novo;
    novo = new Hash();
    novo->chave = n;
    novo->prox = tabela[pos];
    tabela[pos] = novo;
}

int funcao_hashing (int num) {
    return num%tam;
}

void mostrar_hash (Hash* tabela[]) {
    Hash* aux;
    for(int i = 0; i < tam; i++){
        aux = tabela[i];
        while ( aux != NULL){
            cout << "\n Entrada " << i << ": " << aux->chave;
            aux = aux->prox;
        }
    }
}

Hash* buscar (Hash *tabela[], int n) {
    int pos = funcao_hashing(n);
    Hash* aux = NULL;
    if(tabela[pos] != NULL){
        aux = tabela[pos];
        while(aux->prox != NULL && aux->chave != n){
             aux = aux->prox;
        }
    }
    return aux;
}

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize (int arr[], int n) {
    srand (time(NULL));
    for (int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
} 

int main()
{
    Hash* tabela[tam];
    int op, pos;
    int num, i;
    int vet[200000];
    randomize(vet, 200000);
    
    //inserir
    clock_t start = clock();
    for (int i = 0; i < tam; i++) {
        pos = funcao_hashing(vet[i]);
        inserir(tabela, pos, vet[i]);
    }
    clock_t end = clock();
    double time_inserir = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de insercao: " << time_inserir << endl;

    //buscar
    start = clock();
    for (i = 0; i < tam; i++) buscar(tabela, vet[i]);
    end = clock();
    double time_buscar = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de busca: " << time_buscar << endl;
}
