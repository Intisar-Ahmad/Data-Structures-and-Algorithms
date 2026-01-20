#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int> arr,int k,int sum,int i){
    if(i == arr.size()){
        if(sum == k) return 1;
        return 0;
    }
    // inclusion
    int include = func(arr,k,sum+arr[i],i+1);


    int idx = i + 1;
    while(idx < arr.size() && arr[idx] == arr[i]) idx++;
    int exclude = func(arr,k,sum,idx);

    return exclude + include;


}

int main() {
  vector<int> arr = {1, 1, 2}; // must be sorted
   cout << func(arr, 2, 0, 0) << endl;
    return 0;
}