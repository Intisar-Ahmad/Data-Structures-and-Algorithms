#include <iostream>

using namespace std;


// partiion function
int partition(int arr[], int st , int end){
    int i = st - 1;
    for (int j = st; j < end; j++)
    {
       if(arr[j] <= arr[end]){ // picking end as pivot
        swap(arr[++i],arr[j]);
       }
    }

    // position the pivot correctly
    swap(arr[++i],arr[end]);

    return i;
    
}

// picking the last element as pivot
void quickSort(int arr[], int st, int end){
    if(st < end){ // implicit base case
        // finding correct pivot position
       int corrPivot = partition(arr,st,end);

       // quicksort the left half
       quickSort(arr,st,corrPivot - 1);
       quickSort(arr,corrPivot + 1, end);


    }
}

int main() {
    
    int arr[] = {2,5,1,3,4};

    quickSort(arr,0,4);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    

    return 0;
}