#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int n){
    if(n >= 1){
        cout << n << endl;
        print(n-1);
    }
}

int main() {
    print(5);
    return 0;
}