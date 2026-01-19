#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(string s,int idx){
    if(idx == s.length()){
        cout << s << endl;
        return;
    }


    for(int i = idx;i<s.length();i++){
        swap(s[idx],s[i]);
        print(s,idx+1);
        swap(s[idx],s[i]);
    }
}

int main() {
    string s = "bhino";
    print(s,0);
    return 0;
}