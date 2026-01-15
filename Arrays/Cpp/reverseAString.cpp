#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string reverseWords(string s)
{
    string ans = "";
    int n = s.length();
    bool isContiguous = true;

    for (int i = 0; i < n; i++)
    {
        string word = "";
        if (isspace(s[i]))
            continue;

        while (!isspace(s[i]) && i < n)
        {
            word += s[i++];
        }
        ans = " " +  word  + ans;
    }

    ans.erase(ans.begin(),ans.begin()+1);
    return ans;
}

int main()
{
    vector<string> tests = {
        "the sky is blue",
        "  hello world  ",
        "a good   example",
        "C++ is awesome",
        "   practice makes perfect   "};

    for (string s : tests)
    {
        cout << "Input  : \"" << s << "\"" << endl;
        cout << "Output : \"" << reverseWords(s) << "\"" << endl;
        cout << endl;
    }

    return 0;
}