#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        int i = 1;
        int j = 1;
        while(i < n && j < n){
            if(arr[j] == arr[j-1]){
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