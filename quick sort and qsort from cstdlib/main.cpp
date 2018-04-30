#include <iostream> // cout
#include <cstdlib> // qsort
#include <vector>
#include <chrono> // time
using namespace std;

// the function implements quick sort
template<class T>
void quickSort(T*, const int);
// the help function for quick sort
template<class T>
void qs(T*, const int, const int);

int main()
{
    // size of future table
    const int SIZE = 200000;
    // create the table
    vector<int> v;
    // insert elements to the table
    for(int i = 0; i < SIZE; i++)
        v.push_back(SIZE - i);

    // create the table 2 for sort function QSORT
    vector<int> c{v};

    // the time we are gonna calculate with the help of <chrono> library
    auto begin = std::chrono::steady_clock::now();
    // launch the Quick sort function
    quickSort(v.data(), v.size());
    auto end = std::chrono::steady_clock::now();
    // calculate the working time of function
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout << "The time of quick sort function: " << elapsed_ms.count() << " ms\n";


    // we do the same with the "qsort" function
    begin = std::chrono::steady_clock::now();
    // launch the function
    qsort(c.data(), SIZE, sizeof(int), [](const void* a, const void* b){ return *(int*)a - *(int*)b; });
    end = std::chrono::steady_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout << "The time of qsort function: " << elapsed_ms.count() << " ms\n";


    //for(auto i : v)
      //  cout << i << " ";

    return 0;
}

template<class T>
void quickSort(T* tab, const int _size)
{
    qs(tab, 0, _size - 1);
}

template<class T>
void qs(T* tab, const int _begin, const int _end)
{
    int left = _begin, right = _end;
    int K = tab[(left + right) / 2];
    do
    {
        while(tab[left] < K && left <= right)
            left++;
        while(tab[right] > K && right >= left)
            right--;

        if(left <= right)
        {
            swap(tab[left], tab[right]);
            left++;
            right--;
        }

    }while(left <= right);

    if(left < _end)
        qs(tab, left, _end);
    if(right > _begin)
        qs(tab, _begin, right);
}
