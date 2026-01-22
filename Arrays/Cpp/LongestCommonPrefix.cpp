#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


   string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        int limit = min((int)prefix.length(), (int)strs[i].length());
        int j = 0;
        
        while (j < limit && strs[i][j] == prefix[j]) {
            j++;
        }
        prefix.erase(j);

        if (prefix.empty()) return "";
    }

    return prefix;
}
int main() {
 
    return 0;
}