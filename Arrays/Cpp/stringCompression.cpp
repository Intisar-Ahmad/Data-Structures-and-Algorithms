#include <vector>
#include <iostream>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    char currChar = chars[0];
    int currCount = 1;
    int i = 1;
    for (int j = 1; j < n; j++)
    {
        if(chars[j] == currChar){
            currCount++;
        }
        else{
            if(currCount <= 1){
                currCount = 1;
            }
            else{
                string count = to_string(currCount);
                for (auto &&ch : count)
                {
                    chars[i++] = ch;
                }

            }
            currChar = chars[j];
            currCount = 1;
            chars[i++] = currChar;
        }
    }

    if(currCount > 1){
        string count = to_string(currCount);
        for (auto &&ch : count)
        {
            chars[i++] = ch;
        }
    }
    // for (auto &&ch : chars)
    // {
    //     cout << ch << " ";
    // }
    // cout << endl;
    
    return i;
    
}

int main() {
    vector<vector<char>> samples = {
        {'a','a','b','b','c','c','c'},
        {'a'},
        {'a','b','c'},
        {'a','a','a','a','b','b','a','a'},
        {'x','x','x','y','z','z','z','z'},
        {'m','m','m','m','m','m','n','n','o'}
    };

    for(int i = 0; i < samples.size(); i++) {
        vector<char> chars = samples[i];
        int newLength = compress(chars);
        
        cout << "Sample " << i+1 << ":\n";
        cout << "Compressed length: " << newLength << "\n";
        cout << "Compressed chars: ";
        for(int j = 0; j < newLength; j++) {
            cout << chars[j] << " ";
        }
        cout << "\n\n";
    }

    return 0;
}