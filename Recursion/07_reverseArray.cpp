#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void func(int arr[],int size,int i){
    if(i < size){
        int el = arr[i];
        func(arr,size,i+1);
        arr[size - i - 1] = el;
    }
}

int main() {
    int arr[] = {1,2,3,4,5};

    func(arr,5,0);

    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    cout << endl;
    
    return 0;
}