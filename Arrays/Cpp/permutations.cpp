#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getPerms(vector<int> &nums,vector<vector<int>> &ans,int idx,int n){
        if(idx == n) {
            ans.push_back({nums});
            return;
        }

        for(int i = idx;i<n;i++){
            swap(nums[idx],nums[i]);
            getPerms(nums,ans,idx+1,n);
            swap(nums[idx],nums[i]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms(nums,ans,0,nums.size());

        return ans;
    }

int main() {
 
    return 0;
}