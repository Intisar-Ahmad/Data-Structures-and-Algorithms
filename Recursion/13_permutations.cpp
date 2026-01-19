#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void func(vector<int> &arr,int idx){
    if(idx >= arr.size()){
        for (auto &&i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (int i = idx; i < arr.size(); i++)
    {
        swap(arr[idx],arr[i]);

        func(arr,idx+1);

        swap(arr[idx],arr[i]);
    }
    

}

int main() {
 vector<int> arr = {1,2,3}; // must be sorted
    func(arr,0);
    return 0;
}