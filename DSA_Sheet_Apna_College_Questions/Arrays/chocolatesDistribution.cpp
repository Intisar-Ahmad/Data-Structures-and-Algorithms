#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

 int findMinDiff(vector<int>& a, int m) {
        // code here
           sort(a.begin(),a.end());
           int i = 0;
           int j = m - 1;
           int minDiff = INT_MAX;
           int n = a.size();
           
           
           while(j<n){
               int diff = a[j++] - a[i++];
               minDiff = min(diff,minDiff);
           }
           
           return minDiff;
    }

int main() {
 
    return 0;
}