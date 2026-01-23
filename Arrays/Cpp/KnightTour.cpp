#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> checkSafety(vector<vector<int>> &grid,int pos,int r,int c){
       vector<std::vector<int>> moves = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };
    int n = grid.size();
        for(auto &move: moves){
            int currRow = r + move[0];
            int currCol = c + move[1];

            if(currRow < n && currCol < n && currRow >= 0 && currCol >= 0 && grid[currRow][currCol] == pos+1){
                return move;
            }
        }
        return {0, 0};
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
       vector<int> currPos = {0,0};
        int pos = grid[currPos[0]][currPos[1]];
        int n = grid.size();
        for(int i =0;i<n*n-1;i++){
            
                vector<int> move = checkSafety(grid,pos,currPos[0],currPos[1]);
                if(move[0] == 0 || move[1] == 0) return false;
                else{
                    currPos[0] = currPos[0] + move[0];
                    currPos[1] = currPos[1] + move[1];
                    pos = grid[currPos[0]][currPos[1]];
                
            }
        }
        return true;
    }
};

int main() {
 
    return 0;
}