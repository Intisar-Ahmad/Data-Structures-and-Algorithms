#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
{
    int st = 0;
    int end = s.size() - 1;
    while (st <= end)
    {
        if (!isalnum(static_cast<unsigned char>(s[st])))
        {
            st++;
            continue;
        }
        if (!isalnum(static_cast<unsigned char>(s[end])))
        {
            end--;
            continue;
        }

        if (tolower(static_cast<unsigned char>(s[st])) != tolower(static_cast<unsigned char>(s[end])))
        {
            return false;
        }
        st++;
        end--;
    }

    return true;
}

    void func(vector<vector<string>> &ans,int idx,string s,int n,vector<string> part){
        if(idx == n){
            ans.push_back(part);
            return;
        }

        for(int i = idx;i<n;i++){
            string sub = s.substr(idx,i-idx+1);
            if(isPalindrome(sub)){
                part.push_back(sub);
                func(ans,i+1,s,n,part);
                part.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n  = s.length();
        vector<string> part;
        func(ans,0,s,n,part);

        return ans;
    }
};

int main() {
 
    return 0;
}