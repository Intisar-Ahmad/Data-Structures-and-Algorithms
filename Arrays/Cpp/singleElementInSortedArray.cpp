#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        
        
        int st = 0;
        int end = n - 1;

        if(n == 1) return arr[0];
        while(st <= end){
            int mid = st + (end - st)/2;

            if(mid == 0 && arr[mid] != arr[mid+1]) return arr[mid];
            if(mid == n -1 && arr[mid] != arr[mid - 1]) return arr[mid];


            if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
                return arr[mid];
            }
           
           
            if(arr[mid] == arr[mid-1]){
                if(mid%2){
                   st = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
            else if(arr[mid] == arr[mid+1]){
                if(mid%2){
                    end = mid - 1;
                }
                else{
                   st = mid + 1;
                }
            }
        }

    return -1;

    }
int main()
{
    vector<int> arr = {1,1,2,3,3};

    cout << singleNonDuplicate(arr);
    return 0;
}