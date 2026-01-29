#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

   vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> neg(n/2,0);
        vector<int> pos(n/2,0);

        int k = 0;
        int j = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] < 0){
                neg[k++] = arr[i];
            }
            else{
                pos[j++] = arr[i];
            }
        }

        k = 0;j=0;
        for(int i = 0;i<n;i++){
            if(i%2){
                arr[i] = neg[k++];
            }else{
            arr[i] = pos[j++];

            }
            
        }

        return arr;

    }

int main() {
 
    return 0;
}