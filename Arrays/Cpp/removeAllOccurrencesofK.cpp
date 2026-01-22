#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

  int removeElement(vector<int>& arr, int val) {
        int i = 0;
        int j = 0;
        int n = arr.size();
        while(i<n && j<n){
            if(arr[j] == val){
                j++;
            }
            else{
                arr[i++] = arr[j++];
            }
        }
        return i;
    }

int main() {
 
    return 0;
}