#include <iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> array,int target){
    //assuming the the array is sorted
    int size = array.size();

    int low = 1;
    int high = size - 2;
    

    //eliminating first and last elements before hand to avoid out of bounds access
    if(array[0] == target) return 0;
    if(array[size - 1] == target) return size - 1;


    //binary search
    while(low<=high){
        int mid = (low + high)/2; // low + (high - low)/2;


        if(array[mid] == target) return mid;
        else if(array[mid] > target) high = mid - 1;
        else if(array[mid] < target) low = mid + 1;

    }
    
    return -1;

}



int main() {
    vector<int> array = {1,2,3,4,5};
    vector<int> array2 = {6,7,8,9,10};

    cout << binarySearch(array,2)<<endl;
    cout << binarySearch(array2,12)<<endl;
    return 0;
}