#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<climits>


using namespace std;


// my solution
 vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        int maxIdx = -1;
        int maxElement = INT_MIN;
        stack<int> s;
        vector<int> ans(n,-1);


        // find the max of the array
        for(int i = 0;i<n;i++){
            if(arr[i] > maxElement){
                maxElement = arr[i];
                maxIdx = i;
            }
        }
        int j = maxIdx;
        do{
            
            while(!s.empty() && arr[j] >= arr[s.top()]){
                s.pop();
            }

            if(!s.empty()){
                ans[j] = arr[s.top()];
            }

            s.push(j);
            j--;
            if(j < 0) j = n - 1;
        }while(j!=maxIdx);
        
        return ans;
    }


int main() {
 
    return 0;
}