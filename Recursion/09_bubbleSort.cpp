#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swapping(int arr[],int j,int i,int n){
    if(j < n - i - 1){
        if(arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
        swapping(arr,j+1,i,n);
    }
}

void bubbleSort(int arr[],int size, int i){
    if(i < size){
        swapping(arr,0,i,size);

        bubbleSort(arr,size,i+1);
    }
}

int main() {
    int arr[] = {5,4,3,2,1};

    bubbleSort(arr,5,0);

    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    
    cout << endl;

    return 0;
}