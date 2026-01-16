#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>

using namespace std;

vector<int> getMinMax(vector<int> &arr) {
        // code here
        vector<int> minMax(2,0);
        int n = arr.size();
        minMax[0] = INT_MAX;
        minMax[1] = INT_MIN;
        
        for(int i = 0;i<n;i++){
            if(arr[i] > minMax[1]) {
                minMax[1] = arr[i];
            }
            if(arr[i] < minMax[0]){
                minMax[0] = arr[i];
            }
        }
        
        return minMax;
        
        
    }

int main() {
 
    return 0;
}