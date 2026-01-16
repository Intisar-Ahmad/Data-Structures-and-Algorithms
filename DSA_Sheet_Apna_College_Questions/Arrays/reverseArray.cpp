#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

   void reverseArray(vector<int> &arr) {
        // code here
        int i = 0;
        int j = arr.size() - 1;
        while(i<=j){
            swap(arr[i++],arr[j--]);
        }
    }

int main() {
 
    return 0;
}