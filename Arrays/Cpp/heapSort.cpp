#include <iostream>
using namespace std;

// Heapify function (sift down)
void heapify(int arr[],int i,int n) {
   int maxIdx = i; // will be used later for checking if the element changed its position
   int leftChildIdx = (i * 2) + 1;
   int righttChildIdx = (i * 2) + 2;

    if(leftChildIdx < n && arr[leftChildIdx] > arr[maxIdx]){
        maxIdx = leftChildIdx;
    }

    if(righttChildIdx < n && arr[righttChildIdx] > arr[maxIdx]){
        maxIdx = righttChildIdx;
    }

    if(maxIdx != i){
        swap(arr[i],arr[maxIdx]);
        heapify(arr,maxIdx,n);
    }

}

// Heap sort function
void heapSort(int arr[], int n) {
    
    // first making a heap
    for (int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr,i,n);
    }

    // deleting elements and then fixing heap accordingly
    for (int i = n-1; i > 0; i--)
    {
        swap(arr[0],arr[i]); // deleting element from heap
        heapify(arr,0,i);
    }
    
    
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}
