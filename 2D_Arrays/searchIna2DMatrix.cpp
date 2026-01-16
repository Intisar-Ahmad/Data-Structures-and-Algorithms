#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int end = m*n - 1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(matrix[mid/n][mid%n] == target){
                return true;
            }
            else if(matrix[mid/n][mid%n] > target){
                end = mid - 1;
            }
            else if(matrix[mid/n][mid%n] < target){
                st = mid + 1;
            }
        }
        return false;
    }
int main() {
 
    return 0;
}