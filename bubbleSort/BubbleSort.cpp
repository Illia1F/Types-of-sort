#include <iostream>
#include <algorithm>
using namespace std;

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

// The function implements bubble sort
void bubbleSort(int* tab, int size)
{
    for(int i=0; i<size; i++)
        // Last i elements are already placed
        for(int j=1; j<size-i; j++)
        // We are checking each element with next
            if(tab[j - 1] > tab[j])
            // and if they are in wrong order then we're swapping them
                swap(&tab[j - 1], &tab[j]);
}

void show(int el)
{
    cout << el << " ";
}

int main()
{
    int size = 10;
    int* tab = new int[size];
    for(int i=size, j=0; i>=0; i--, j++)
        tab[j] = i;

    cout << "Entry array: ";
    for_each(tab, tab+size, show);
    bubbleSort(tab, size);
    cout << endl << "Sorted array: ";
    for_each(tab, tab+size, show);

    return 0;
}
