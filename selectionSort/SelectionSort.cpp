#include <iostream>
#include <algorithm>
using namespace std;

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

// The function implements selection sort
void selectionSort(int* tab, int n)
{
    int k;
    for(int i=0; i<n-1; i++){
            k = i;
        // Find the minimum element in subarray
        for(int j=i; j<n; j++)
            if(tab[i] > tab[j])
                k = j;
        // Swapping the minimum with the first element in array
        swap(tab[i], tab[k]);
    }
}

void show(int el)
{
    cout << el << " ";
}

int main()
{
    int size = 10;
    int* tab = new int[size];
    for(int i=size, j=0; i>0; i--, j++)
        tab[j] = i;
    cout << "Entry array: ";
    for_each(tab, tab+size, show);

    selectionSort(tab, size);

    cout << endl << "Sorted array: ";
    for_each(tab, tab+size, show);

    return 0;
}
