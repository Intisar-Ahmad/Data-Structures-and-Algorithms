#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>

using namespace std;

  int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        int currSum = 0;
        for (int i = 0; i < n; i++)
        {
            currSum = max(currSum+nums[i],nums[i]);
            maxSum = max(currSum,maxSum);
        }
        return maxSum;
    }

int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray(arr);
    return 0;
}