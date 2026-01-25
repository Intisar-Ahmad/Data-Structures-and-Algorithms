#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// a leader is an element that is greater than all of the elements to its right

void printLeaders(vector<int> arr){
    int n = arr.size();
    int LL = n - 1;
    vector<int> list;
    list.push_back(arr[LL]);
    for (int i = n-2; i >= 0; i--)
    {
        if(arr[i] > arr[LL]){
            LL = i;
            list.push_back(arr[LL]);
        }
    }

    for (auto &&i : list)
    {
        cout << i << " ";
    }
    
    cout << endl;
    
}

int main() {
    vector<int> vec = {10, 22, 12, 3, 0, 6};

    printLeaders(vec);
    return 0;
}