#include <iostream>

using namespace std;

// insertion sort
void insertionSort(int arr[], int size){
    for (int i = 0; i < size;i++)
    {
        int key = arr[i];
        int j = i - 1;
        while ( j >= 0 && arr[j] > key )
        {
           arr[j+1] = arr[j];
           j--;
        }
        arr[j+1] = key;

        
    }
    
}

int main() {
    int arr[] = {2,3,1,5,4,7};

    insertionSort(arr,6);


    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}