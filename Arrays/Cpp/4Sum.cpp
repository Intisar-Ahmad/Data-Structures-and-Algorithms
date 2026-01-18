 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include<set>
 
 using namespace std;
 
 vector<vector<int>> fourSum(vector<int>& nums, int target) {// this makes me wanna throw up
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        int n = nums.size();
        for(int i = 0;i<n-3;i++){
            for(int j = i+1;j<n-2;j++){
                int k = j+1;
                int l = n-1;
                long long sumIJ = nums[i] + nums[j];
                long long currTarget = target - sumIJ;
                while(k<l){
                    int sum = nums[k] + nums[l];
                    if(sum == currTarget){
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                    }
                    else if(sum > currTarget){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }

 int main() {
  
     return 0;
 }