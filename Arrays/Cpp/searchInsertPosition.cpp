#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 int searchInsert(vector<int>& arr, int target) {
        int st = 0;
        int end = arr.size() - 1;
        int idx = -1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(arr[mid] > target){
                end = mid - 1;
                idx = mid;
            }
            else if(arr[mid] < target){
                st = mid + 1;
                idx = st;
            }
            else{
                return mid;
            }
        }
        return idx;
    }

int main() {
 
    return 0;
}