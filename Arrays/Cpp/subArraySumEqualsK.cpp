#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>

using namespace std;

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int count = 0;
        int n = nums.size();
        vector<int> PS(n,0);
        PS[0] = nums[0];
        for(int i = 1;i<n;i++){
            PS[i] = PS[i-1] + nums[i];
        }

        for(int j = 0;j<n;j++){
            if(PS[j] == k) count++;

            int val = PS[j] - k;
            if(m.find(val) != m.end()){
                count += m[val];
            }
            m[PS[j]]++;
        } 

        return count;
    }

int main() {
 
    return 0;
}