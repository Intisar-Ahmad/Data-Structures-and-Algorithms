#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int srow = 0;
        int scol = 0;
        int erow = m - 1;
        int ecol = n - 1;
        vector<int> vec;


        while(scol <= ecol && srow <= erow){
            for(int i = scol;i<=ecol;i++){
                vec.push_back(matrix[srow][i]);
            }
            for(int i = srow+1;i<=erow;i++){
                vec.push_back(matrix[i][ecol]);
            }
            for(int i = ecol-1;i>=scol;i--){
                if(srow == erow) break;
                vec.push_back(matrix[erow][i]);
            }
            for(int i = erow-1;i>=srow+1;i--){
                if(scol == ecol) break;
                vec.push_back(matrix[i][scol]);
            }

            srow++;erow--;
            scol++;ecol--;
        }

    return vec;


    }

int main() {
 
    return 0;
}