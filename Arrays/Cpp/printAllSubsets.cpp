#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void print(vector<int> arr,vector<int> ans,int i){
    if(i == arr.size()){
        cout << "{ ";
        for (auto &&el : ans)
        {
            cout << el << " ";
        }

        cout << "}" << endl;
        return;
    }

    // inclusion
    ans.push_back(arr[i]);
    print(arr,ans,i+1);


    // exclusion
    ans.pop_back();
    print(arr,ans,i+1);

}

int main() {
   vector<int>  arr = {1,2,3};
    vector<int> ans;
    print(arr,ans,0);
    return 0;
}