#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool isSafe(vector<string> &board,int row,int col,int n){
         // check horizontally and vertically
        for(int j = 0;j<n;j++){
            if(board[row][j] == 'Q'){
                return false;
            }
            if(board[j][col] == 'Q'){
                return false;
            }
        }

        // diagonals
        for(int i = row,j = col;i>=0 && j >= 0;i--,j--){
            if(board[i][j] == 'Q') return false;

        }

        for(int i = row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }

    void nQueens(vector<string> &board,int row,int n,vector<vector<string>> &ans){

        if(row == n){
            ans.push_back({board});
            return;
        }

        for(int i = 0;i<n;i++){
            if(isSafe(board,row,i,n)){
                board[row][i] = 'Q';
                nQueens(board,row+1,n,ans);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
         vector<vector<string>> ans;
         nQueens(board,0,n,ans);
         return ans;
    }
};

int main() {
 
    return 0;
}