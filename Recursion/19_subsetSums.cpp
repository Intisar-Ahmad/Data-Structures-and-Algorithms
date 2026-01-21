#include <iostream>
#include <vector>
#include <algorithm>
#include<set>


using namespace std;


void func(vector<int> &arr,int s,int i,vector<int> &ans){
    if(i == arr.size()){
        ans.push_back(s);
        return;
    }

    // exclusion
    func(arr,s,i+1,ans);

    // inclusion
    func(arr,s+arr[i],i+1,ans);

}
// print sum of all subsets of an array in increasing order

void print(vector<int> &arr){
    vector<int> s;
    func(arr,0,0,s);
    sort(s.begin(),s.end());
    for (auto &&i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    

}



int main() {
    vector<int> arr = {3,1,2};
    print(arr);
    return 0;
}