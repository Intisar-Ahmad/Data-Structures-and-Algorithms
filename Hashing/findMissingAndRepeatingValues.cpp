#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

   vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2,0);
        int n = grid.size();
        unordered_map<int,int> m;
       
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                m[grid[i][j]]++;
                if(m[grid[i][j]] > 1){
                    ans[0] = grid[i][j];
                }
            }
        }
        for(int i = 1;i<=n*n;i++){
            if(m[i] == 0){
                ans[1] = i;
                break;
            }
        }
        return ans;
    }

int main() {
 
    return 0;
}