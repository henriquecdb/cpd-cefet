#include <iostream>
#include <ctime>
#include "cpd.h"
#define MAXN 100001

using namespace std;

int main()
{
    int array[MAXN];
    randInt(array, MAXN);

    clock_t start = clock();
    bubbleSort(array, MAXN);
    clock_t end = clock();
    double time_bubble = (double)(end - start) / CLOCKS_PER_SEC;

    clock_t start = clock();
    bubbleSort(array, MAXN);
    clock_t end = clock();
    double time_bubble = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    insertionSort(array, MAXN);
    end = clock();
    double time_insertion = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    selectionSort(array, MAXN);
    end = clock();
    double time_selection = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "Bubble Time: " << time_bubble << endl;
    cout << "Insertion Time: " << time_insertion << endl; 
    cout << "Selection Time: " << time_selection << endl;
    return 0;
}
