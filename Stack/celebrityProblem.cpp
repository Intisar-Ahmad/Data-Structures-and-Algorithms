#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>


using namespace std;

int func(vector<vector<int>> grid){
    stack<int> s;
    int n = grid.size(); // its n*n
    for(int i = 0;i<n;i++){
        s.push(i);
    }


    
    while(s.size() > 1){
        int i = s.top();s.pop();
        int j = s.top();s.pop();

        if(grid[i][j] == 0){
            s.push(i);
        }
        else{
            s.push(j);
        }
    }


    int celeb = s.top();
    for(int i = 0;i<n;i++){
        if(i != celeb){
            if(grid[i][celeb] != 1){
                return -1;
            }
        }
    }

    return celeb;

}

int main() {
 
    return 0;
}