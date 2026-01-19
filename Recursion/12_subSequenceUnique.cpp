#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void func(vector<int> arr,vector<int> &subSequence,int i){
  if(i < arr.size()){

        // inclusion
        subSequence.push_back(arr[i]);
        func(arr,subSequence,i+1);

        // exclusion
        subSequence.pop_back();
        int idx = i + 1;
        while(idx < arr.size() && arr[idx] == arr[i]) idx++;
        func(arr,subSequence,idx);

    }else{
        cout << "{ ";
        for (auto &&el:subSequence)
        {
            cout << el << " ";
        }

        cout << "}" << endl;
    }
}

int main() {
  vector<int> arr = {1,1,2}; // must be sorted
    vector<int> sub;
    func(arr,sub,0);
    return 0;
}