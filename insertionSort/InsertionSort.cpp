#include <iostream>
#include <algorithm>
using namespace std;

// The function implement Insersion Sort
void insertionSort(int* tab, int n)
{
    for(int i=1; i<n; i++){

        int key = tab[i];
        int j = i-1;
        //We are moving elements of arr[0..i-1],
        //that are greater than key,
        //on one position ahead from their current position
        for(; j>=0 && tab[j] > key; j--)
            tab[j+1] = tab[j];

        // If the checking element is smaller than our key,
        // then we insert the key to the position is after the position of checking element
        tab[j+1] = key;
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
    insertionSort(tab, size);
    cout << endl << "Sorted array: ";
    for_each(tab, tab+size, show);

    return 0;
}
