#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//brute force

/*class Solution {
public:
    void func(vector<vector<int>> &ans,vector<int> &arr,vector<int> ds,int i,int tar){
        if(i == arr.size()){
            if(tar == 0){
                for(auto &j:ans){
                    if(j == ds){
                        return;
                    }
                }
                ans.push_back({ds});
            }
            return;
        }
         if(tar == 0){
                for(auto &j:ans){
                    if(j == ds){
                        return;
                    }
                }
                ans.push_back({ds});
                return;
            }
        // included
        ds.push_back(arr[i]);
        func(ans,arr,ds,i+1,tar-arr[i]);

        //excluded
        ds.pop_back();
        func(ans,arr,ds,i+1,tar);

    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> ans;

        vector<int> ds;
        func(ans,arr,ds,0,target);


        return ans;
    }
};
*/

class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> &arr, vector<int> &ds, int start, int tar){
        if(tar == 0){
            ans.push_back(ds);
            return;
        }

        for(int idx = start; idx < arr.size(); idx++){
            if(arr[idx] > tar) break; 
            if(idx > start && arr[idx] == arr[idx - 1]) continue;

            ds.push_back(arr[idx]);
            func(ans, arr, ds, idx + 1, tar - arr[idx]);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); 
        vector<vector<int>> ans;
        vector<int> ds;
        func(ans, arr, ds, 0, target);
        return ans;
    }
}; // it almost killed me

int main() {
 
    return 0;
}