#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

   void allSubsets(vector<int> &arr,vector<int> &s,int i,int n,vector<vector<int>> &ans){
        if(i == n){
            ans.push_back(s);
            return;
        }

        // inclusive
        s.push_back(arr[i]);
        allSubsets(arr,s,i+1,n,ans);


        //exclusive
        s.pop_back();
        int idx = i + 1;
        while(idx < n && arr[idx] == arr[i]){
            idx++;
        }
        allSubsets(arr,s,idx,n,ans);

    }


    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;    
        vector<int> s;
        allSubsets(arr,s,0,arr.size(),ans);

        return ans;


    }

int main() {
 
    return 0;
}