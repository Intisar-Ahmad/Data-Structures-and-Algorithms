#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void func(vector<int> arr, vector<int> &subSequence, int i, int k)
{
    if (i < arr.size())
    {
        // exclusion
        int idx = i + 1;
        while (idx < arr.size() && arr[idx] == arr[i])
        idx++;


        func(arr, subSequence, idx,k);
        // inclusion
        subSequence.push_back(arr[i]);
        func(arr, subSequence, i+1,k); 
        
        
      
        subSequence.pop_back();
        
        
    }
    else
    {
        int sum = 0;
        for (auto &&el : subSequence)
        {
            sum += el;
        }

        if (sum == k)
        {
            cout << "{ ";
            for (auto &&el : subSequence)
            {
                cout << el << " ";
            }

            cout << "}" << endl;
        }
    }
}

int main()
{
    vector<int> arr = {1,1,2}; // must be sorted
    vector<int> sub;
    func(arr, sub, 0,2);
    return 0;
}