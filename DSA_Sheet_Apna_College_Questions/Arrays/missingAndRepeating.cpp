#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>

using namespace std;

   vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
      int actualSum = 0;
      int n = grid.size();
      int R = 0;
      vector<int> ans;
      unordered_map<int,int> m;
      for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            actualSum+=grid[i][j];
            m[grid[i][j]]++;
            if(m[grid[i][j]] > 1){
                R = grid[i][j];
            }
        }
      }
      int M = (n*n)*((n*n)+1)/2 - actualSum + R;
      ans = {R,M};
      return ans;
    }

int main() {
 
    return 0;
}