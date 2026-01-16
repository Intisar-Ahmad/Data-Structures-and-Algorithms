#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>

using namespace std;

  void nextPermutation(vector<int>& vec) {
         int n = vec.size();
     
        if (n == 0) return;
        int pivot = n - 1;
      
        for(int i = n - 2;i>=0;i--){
            if(vec[i]<vec[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot==n - 1){
            reverse(vec.begin(),vec.end());
        }
        int RME = n - 1;
        for(int i = n - 1;i>pivot;i--){
            if(vec[i] > vec[pivot]){
                RME = i;
                break;
            }
        }
        swap(vec[pivot],vec[RME]);
        reverse(vec.begin() + pivot + 1,vec.end());
        
    }

int main() {

    vector<vector<int>> testCases = {

        {},                     // 1. Empty vector
        {1},                    // 2. Single element

        {1,2},                  // 3. Already increasing
        {2,1},                  // 4. Already decreasing

        {1,2,3},                // 5. Strictly increasing
        {3,2,1},                // 6. Strictly decreasing

        {1,1,1},                // 7. All elements same
        {1,1,2},                // 8. Duplicates
        {2,1,1},                // 9. Duplicates reversed

        {1,3,2},                // 10. Middle swap needed
        {2,3,1},                // 11. Complex reorder

        {1,5,1},                // 12. Duplicate pivot case
        {2,2,3,3},              // 13. Multiple duplicates

        {0,0,0},                // 14. All zeros
        {0,1,0},                // 15. Zeros mixed

        {-1,-2,-3},             // 16. All negative
        {-3,-1,-2},             // 17. Negative mixed

        {INT_MAX, INT_MIN},     // 18. Extreme values
        {INT_MIN, INT_MAX},     // 19. Extreme reversed

        {1,2,3,4,5},            // 20. Long increasing
        {5,4,3,2,1},            // 21. Long decreasing

        {1,4,3,2},              // 22. Partial decreasing suffix
        {2,4,3,1},              // 23. Multiple swaps required

        {1,2,2,3},              // 24. Duplicate in middle
        {3,2,2,1},              // 25. Duplicate decreasing

        {10,20,30},             // 26. Larger gaps
        {30,20,10},             // 27. Larger gaps reversed
    };

    for (auto& v : testCases) {
        nextPermutation(v);
    }

    for (auto &&i : testCases)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }

        cout << endl;
        
    }
    

    return 0;
}
