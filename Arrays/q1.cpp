#include <iostream>
#include<vector>

using namespace std;

//# Find the max number of steps taken in finding a number using binary search.

int binarySearch(vector<int> array){
    //assuming the the array is sorted
    int size = array.size();

    int low = 1;
    int high = size - 2;
    int count = 0;


    //binary search
    while(low<=high){
        int mid = (low + high)/2; // low + (high - low)/2;
        high = mid - 1;
        count++;
    }
        return count;
   
}



int main() {
    vector<int> arr = {1,2,3,4,5,6};
    cout << binarySearch(arr);
    return 0;
}