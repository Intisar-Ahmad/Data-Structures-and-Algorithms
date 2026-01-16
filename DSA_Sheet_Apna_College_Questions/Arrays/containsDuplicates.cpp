#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

   bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> freqs;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            freqs[nums[i]]++;
            if(freqs[nums[i]] > 1){
                return true;
            }
        }

        return false;
    }

int main()
{
    vector<int> arr = {1,2,3,1};
    cout << containsDuplicate(arr);
    return 0;
}