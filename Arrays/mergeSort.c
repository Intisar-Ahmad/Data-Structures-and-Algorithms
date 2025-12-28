#include <stdio.h>

// merge
void merge(int arr[],int leftSt,int leftEnd,int rightEnd){

    int temp[rightEnd - leftSt + 1];
    int i = leftSt;
    int j = leftEnd + 1;// right start
    int k = 0;


    while(i <= leftEnd && j <=rightEnd){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
             temp[k++] = arr[j++];
        }
    }

    while(i <= leftEnd){
        temp[k++] = arr[i++];
    }


    while(j <= rightEnd){
        temp[k++] = arr[j++];
    }


    // copying temp to arr
     i = leftSt;
     j = 0;
    while(i <= rightEnd && j < k){
        arr[i++] = temp[j++];
    }



}


// mergesort
void mergeSort(int arr[], int st, int end){
    if(st < end){
        int mid = st + (end - st)/2;
        
        // left half
        mergeSort(arr,st,mid);

        // right half
        mergeSort(arr,mid+1,end);

        // merge
        merge(arr,st,mid,end);

    }
}


int main() {
    int arr[] = {2,4,1,7,3,6};

    for(int i = 0;i < 6;i++){
        printf("%d ",arr[i]);
    }
        printf("\n");
    mergeSort(arr,0,5);

    for(int i = 0;i < 6;i++){
        printf("%d ",arr[i]);
    }

    printf("\n");

    return 0;
}