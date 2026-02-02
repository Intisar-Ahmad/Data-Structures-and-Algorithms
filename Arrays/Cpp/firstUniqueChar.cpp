#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mapToIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    return -1; 
}

    int firstUniqChar(string s) {
        int map[26] = {0};
        int n = s.length();
        for(int i = 0;i<n;i++){
            map[mapToIndex(s[i])]++;
        }

        for(int i = 0;i<n;i++){
            if(map[mapToIndex(s[i])] == 1){
                return i;
            }
        }
        return -1;
    }
};

int main() {
 
    return 0;
}