#include <iostream>
#include <ctime>
#include "cpd.h"
#define MAXN 100001

using namespace std;

void sortDescending(int array[], int length);
void sortGrowing(int array[], int length);

int main()
{
    int array_randint[MAXN], array_growing[MAXN], array_descending[MAXN];
    randInt(array_randint, MAXN);
    sortDescending(array_descending, MAXN);
    sortGrowing(array_growing, MAXN);

    // For random numbers
    clock_t start = clock();
    bubbleSort(array_randint, MAXN);
    clock_t end = clock();
    double time_bubble = (double)(end - start) / CLOCKS_PER_SEC;
    randInt(array_randint, MAXN);

    start = clock();
    insertionSort(array_randint, MAXN);
    end = clock();
    double time_insertion = (double)(end - start) / CLOCKS_PER_SEC;
    randInt(array_randint, MAXN);

    start = clock();
    selectionSort(array_randint, MAXN);
    end = clock();
    double time_selection = (double)(end - start) / CLOCKS_PER_SEC;
    randInt(array_randint, MAXN);

    cout << "## Random Numbers: " << endl;
    cout << "Bubble Time: " << time_bubble << endl;
    cout << "Insertion Time: " << time_insertion << endl; 
    cout << "Selection Time: " << time_selection << endl << endl;

    // For growing numbers, but already sorted
    start = clock();
    bubbleSort(array_growing, MAXN);
    end = clock();
    time_bubble = (double)(end - start) / CLOCKS_PER_SEC;
    sortGrowing(array_growing, MAXN);

    start = clock();
    insertionSort(array_growing, MAXN);
    end = clock();
    time_insertion = (double)(end - start) / CLOCKS_PER_SEC;
    sortGrowing(array_growing, MAXN);

    start = clock();
    selectionSort(array_growing, MAXN);
    end = clock();
    time_selection = (double)(end - start) / CLOCKS_PER_SEC;
    sortGrowing(array_growing, MAXN);

    cout << "## Growing Numbers: " << endl;
    cout << "Bubble Time: " << time_bubble << endl;
    cout << "Insertion Time: " << time_insertion << endl; 
    cout << "Selection Time: " << time_selection << endl << endl;

    // For descending numbers, but already sorted
    start = clock();
    bubbleSort(array_descending, MAXN);
    end = clock();
    time_bubble = (double)(end - start) / CLOCKS_PER_SEC;
    sortDescending(array_descending, MAXN);

    start = clock();
    insertionSort(array_descending, MAXN);
    end = clock();
    time_insertion = (double)(end - start) / CLOCKS_PER_SEC;
    sortDescending(array_descending, MAXN);

    start = clock();
    selectionSort(array_descending, MAXN);
    end = clock();
    time_selection = (double)(end - start) / CLOCKS_PER_SEC;
    sortDescending(array_descending, MAXN);

    cout << "## Descending Numbers: " << endl;
    cout << "Bubble Time: " << time_bubble << endl;
    cout << "Insertion Time: " << time_insertion << endl; 
    cout << "Selection Time: " << time_selection << endl << endl;

    return 0;
}

void sortDescending(int array[], int length) {
    for (int i = MAXN - 1; i >= 0; i--) {
        array[i] = i;
    }
}

void sortGrowing(int array[], int length) {
    for (int i = 0; i < MAXN; i++) {
        array[i] = i;
    }
}
