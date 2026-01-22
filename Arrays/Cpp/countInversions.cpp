#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int merge(vector<int> &arr,int st,int mid,int end){
    int i = st;
    int j = mid + 1;
    vector<int> temp;
    int count = 0;
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                count+=mid-i+1;
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(arr[i++]);
        }

        while(j <= end){
            temp.push_back(arr[j++]);
        }

        i = st;
        for (auto &&key : temp)
        {
            arr[i++] = key;
        }
        return count;
}

void mergeSort(vector<int> &arr,int st,int end){
 
    if(st < end){
        // left
        int mid = st + (end - st)/2;

        mergeSort(arr,st,mid);

        //right
        mergeSort(arr,mid+1,end);


        merge(arr,st,mid,end);
    }
  
}

int main() {
    vector<int> arr = {10,5,3,2,6,8,9};
    // int count  = 0;
    mergeSort(arr,0,6);

    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}