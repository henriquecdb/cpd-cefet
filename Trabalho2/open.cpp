#include <bits/stdc++.h>

using namespace std;

const int tam = 80000;

struct hsh {
    int chave;
    char livre;
};

int funcao_hashing (int num) {
    return num % tam;
}

void mostrar_hash (hsh tabela[]) {
    for (int i = 0; i < tam; i++) {
        if (tabela[i].livre == 'O')
            cout << "\nEntrada " << i <<": " << tabela[i].chave;
    }
}

void inserir (hsh tabela[], int pos, int n) {
    int i = 0;
    while (i < tam && tabela[(pos+i)%tam].livre != 'L' && tabela[(pos+i)%tam].livre != 'R') {
        i++;
    }
    if (i < tam) {
        tabela[(pos+i)%tam].chave = n;
        tabela[(pos+i)%tam].livre = 'O';
    }
    else cout << "\nTabela cheia";
}

void inserir_quadratico(hsh tabela[], int n) {
        int pos = funcao_hashing(n);
        int i = 1;
        while(i <= tam && tabela[(pos + i * i) % tam].livre != 'L' && tabela[(pos + i * i) % tam].livre != 'R'){
            pos = (pos+i)%tam;
            i++;
        }
        if(i <= tam) {
            tabela[pos].chave = n;
            tabela[pos].livre = 'O';
        } 
        else cout << "\nTabela cheia";
}

int buscar (hsh tabela[], int n) {
    int i = 0;
    int pos = funcao_hashing(n);
    while(i< tam && tabela[(pos+i)%tam].livre != 'L' && tabela[(pos+i)%tam].chave != n)
        i++;
    if (tabela[(pos+i)%tam].chave == n && tabela[(pos+i)%tam].livre != 'R')
        return (pos+i)%tam;
    else return tam;
}

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize (int arr[], int n) {
    srand (time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

int main()
{
    hsh tabela[tam];
    int op, pos;
    int num, i;
    int vet[tam];
    randomize(vet, tam);

    //inserindo
    clock_t start = clock();
    for (i = 0; i < tam; i++) tabela[i].livre = 'L';
    for (int i = 0; i < tam; i++) {
        pos = funcao_hashing(vet[i]);
        inserir_quadratico(tabela, vet[i]);
    }
    clock_t end = clock();
    double time_inserir = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de insercao: " << time_inserir << endl;

    //buscar
    start = clock();
    for (i = 0; i < tam; i++) buscar(tabela, i);
    end = clock();
    double time_buscar = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de busca: " << time_buscar << endl;
    
    // mostrar hash
    //mostrar_hash(tabela);
}