#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& vec, int target) {
        int low = 0, high = vec.size() - 1;
        if(vec[low] == target){
            return low;
        }
        if(vec[high] == target){
            return high;
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            if(vec[mid] == target){
                return mid;
            }
            if(vec[low] <= vec[mid]){
                if(vec[low] <= target && target <= vec[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(vec[mid] <= target && target <= vec[high]){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }
        }
        return -1;
    }

int main() {
 
    return 0;
}