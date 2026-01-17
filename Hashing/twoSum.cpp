#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>

using namespace std;

    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> m;
        int n = arr.size();
        vector<int> ans(2,0);
        for(int i = 0;i<n;i++){
            int first = arr[i];
            if(m.find(target-first) != m.end())
            {
                ans[0] = i;
                ans[1] = m[target-first];
                break;
            }
            else
            {
                m[first] = i;
            }
        }

        return ans;
    }

int main() {
 
    return 0;
}