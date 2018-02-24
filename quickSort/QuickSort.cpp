#include <iostream>
#include <algorithm>
using namespace std;

// The function implements quick sort Hoare
void quickSort(int* tab, int left, int right) {

    // Assigning point i and j
    int i = left, j = right;
    // Choosing a pivot value
    int pivot = tab[(left+right+1)/2];

    // Partition
    for(; i<=j; i++, j--){

        while(tab[i] < pivot)
            i++;

        while(tab[j] > pivot)
            j--;

        if(i<=j){
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
    }

    // Recursion
    if(left < j)
        quickSort(tab, left, j);

    if(right > i)
        quickSort(tab, i, right);
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

    quickSort(tab, 0, size-1);

    cout << endl << "Sorted array: ";
    for_each(tab, tab+size, show);


    return 0;
}
