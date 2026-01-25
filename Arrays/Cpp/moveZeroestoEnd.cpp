#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    void moveZeroes(vector<int>& nums) {
        int i = 0,j=0;
        int n = nums.size();
        while(j<n){
            if(nums[j] != 0){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
    }

int main() {
 
    return 0;
}