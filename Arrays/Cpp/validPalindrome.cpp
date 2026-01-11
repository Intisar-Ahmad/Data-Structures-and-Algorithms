#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int main()
{
    string s = "A man, a plan, a canal: Panama";

    cout << isPalindrome(s);
    return 0;
}