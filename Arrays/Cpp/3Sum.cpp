#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

  vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++){

            if(i > 0 && nums[i] == nums[i-1]) continue;


            int tar = -nums[i];
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                if(nums[j] + nums[k] < tar){
                    j++;
                }
                else if(nums[j] + nums[k] > tar){
                    k--;
                }
                else{
                    vector<int> trip = {nums[i],nums[j],nums[k]};
                    ans.push_back(trip);
                    j++;k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                }
            }
        }


        return ans;
    }

int main() {
 
    return 0;
}