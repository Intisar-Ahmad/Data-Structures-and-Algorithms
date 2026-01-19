#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(string s,int i,int j){
    if(i <= j){
        if(isalnum(s[i])){
            if(isalnum(s[j])){
                if(tolower(s[i]) != tolower(s[j])) return false;
                return isValid(s,i+1,j-1);
            }
            else{
                return isValid(s,i,j-1);
            }
        }else{
            return isValid(s,i+1,j);
        }
    }
    return true;
}

int main() {
    string s = "race a car";
    int j = s.length() - 1;
    cout << isValid(s,0,j);
    return 0;
}