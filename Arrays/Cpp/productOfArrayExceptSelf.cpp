#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size,1);
        int prefix = 1, suffix = 1;
        for(int i = 1; i < size; i++){
            prefix  *= nums[i-1];
            ans[i] = prefix;
        }


        for(int i = size - 2;i>=0;i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }

        return ans;
    }

int main() {
    vector<int> arr = {1,2,3,4};

    vector<int> res = productExceptSelf(arr);


    for (auto &&i : res)
    {
        cout << i << " ";
    }

    cout << endl;
    
    return 0;
}