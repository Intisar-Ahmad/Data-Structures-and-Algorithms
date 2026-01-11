#include <iostream>

using namespace std;

void merge(int arr[],int st,int mid,int end){
    // conquer

    int temp[end - st + 1];
    int i = st; // counter for left sub array
    int j = mid + 1; // counter for right sub array
    int k = 0; // counter for temp's indices


    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++]; 
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    // checking if anything got missed
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    

    // finally adding the array

    i = st;
    j = 0;
   while(i <= end && j<k){
    arr[i++] = temp[j++];
   }
    
    


}

void mergeSort(int arr[],int st,int end){
    // divide
    if(st < end){
        int mid = st + (end - st)/2;


        // left
        mergeSort(arr,st,mid);
        //right
        mergeSort(arr,mid+1,end);

        merge(arr,st,mid,end);
    }

}

int main() {
    int arr[] = {-1,3,1,6,4,9};

    mergeSort(arr,0,5);

   for (auto &&i : arr)
   {
    cout << i << " ";
   }
   
    cout << endl;

    return 0;
}