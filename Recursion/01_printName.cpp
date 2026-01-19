#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printName(string s,int n){
    if(n < 1){
        return;
    }
    cout << s << endl;
    printName(s,n-1);
}

int main() {
    string name = "bhino";
    printName(name,5);
    return 0;
}