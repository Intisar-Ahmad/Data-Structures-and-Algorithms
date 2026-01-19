#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int shifting(int arr[], int j,int key)
{
    if (j >= 0 && key < arr[j])
    {
        arr[j + 1] = arr[j];
        return shifting(arr, j - 1,key);
    }
    return j + 1;
}

void insertionSort(int arr[], int size, int i)
{
    if (i < size)
    {
        int key = arr[i];

        int j = shifting(arr, i - 1,key);
        arr[j] = key;
        insertionSort(arr, size, i + 1);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};

    insertionSort(arr, 5, 1);

    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}