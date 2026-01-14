#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

   string removeOccurrences(string s, string part) {
        string res;
        int m = part.size();

        for(char c : s) {
            res.push_back(c);

            if(res.size() >= m &&
               res.substr(res.size() - m) == part) {
                res.erase(res.size() - m);
            }
        }
        return res;
    }

int main() {
 
    return 0;
}