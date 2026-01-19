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
        func(arr,subSequence,i+1);

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
    vector<int> arr = {2,1,3};
    vector<int> sub;
    func(arr,sub,0);
    return 0;
}