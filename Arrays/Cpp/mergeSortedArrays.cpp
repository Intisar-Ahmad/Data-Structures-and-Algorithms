#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = (m+n)-1;
        int k = m-1;
        int j = n-1;

        while(j>=0){
            if(k>=0 && nums1[k] > nums2[j]){
                nums1[i] = nums1[k];
                k--;
            }
            else {
                nums1[i] = nums2[j];
                j--;
            }
            i--;
        }
      
    }
void runTest(vector<int> nums1, int m, vector<int> nums2, int n) {
    merge(nums1, m, nums2, n);
    for (int x : nums1) cout << x << " ";
    cout << endl;
}

int main() {

    // Normal case
    runTest({1,3,5,0,0,0}, 3, {2,4,6}, 3);

    // nums2 smaller elements
    runTest({4,5,6,0,0,0}, 3, {1,2,3}, 3);

    // nums2 larger elements
    runTest({1,2,3,0,0,0}, 3, {4,5,6}, 3);

    // nums1 empty
    runTest({0,0,0}, 0, {1,2,3}, 3);

    // nums2 empty
    runTest({1,2,3}, 3, {}, 0);

    // Mixed duplicates
    runTest({1,2,2,0,0,0}, 3, {2,2,3}, 3);

    // Single element
    runTest({2,0}, 1, {1}, 1);

    return 0;
}