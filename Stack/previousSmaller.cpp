#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>


using namespace std;

void func(vector<int> arr){
    int n = arr.size();
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if(s.size() > 0 && arr[s.top()] >= arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(arr[s.top()]);
        }

        s.push(i);
    }
    
    for (auto &&el : ans)
    {
        cout << el << " ";
    }
    cout << endl;


}

int main() {
    vector<int> arr = {3,1,0,8,6};
    func(arr);
    return 0;
}