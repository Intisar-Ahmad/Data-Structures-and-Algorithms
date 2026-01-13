#include <bits/stdc++.h>
using namespace std;

// Dutch National Flag sorting function
// Expected to sort array of 0s, 1s and 2s
void dnfSort(vector<int>& arr) {
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid++],arr[low++]);
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else{
            swap(arr[high--],arr[mid]);
        }
        
    }


}

int main() {
    vector<vector<int>> testCases = {
        {2, 0, 2, 1, 1, 0},
        {0, 1, 2, 0, 1, 2},
        {2, 2, 1, 1, 0, 0},
        {1, 0, 2, 1, 0, 2},
        {0, 0, 1, 1, 2, 2}
    };

    for (auto& tc : testCases) {
        dnfSort(tc);
        for (int x : tc) cout << x << " ";
        cout << endl;
    }

    return 0;
}
