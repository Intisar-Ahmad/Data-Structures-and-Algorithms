#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSorted(int *arr,int size){
    if(size == 1 || size == 0) return true;
    if(arr[size-1] > arr[size - 2]){
        return isSorted(arr,size-1);
    }
    return false;
}

int main() {
    int arr[] = {1,2,7};


   cout << isSorted(arr,5);
    return 0;
}