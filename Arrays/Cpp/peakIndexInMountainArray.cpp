#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// this function is written under consideration that there may not be atleast 3 elements in the array
int peakIndexInMountainArray(vector<int> &arr)
{
    int st = 0, size = arr.size(), end = size - 1;

    if (size == 1)
    {
        return 0;
    }

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (mid == 0 && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (mid == size - 1 && arr[mid] > arr[mid - 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
        {
            end = mid - 1;
        }
        else if (arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            st = mid + 1;
        }
    }

    return -1;
}
int main()
{
  
    vector<vector<int>> tests = {
        {1, 3, 5, 4, 2},
        {0, 2, 4, 6, 5, 3, 1},
        {2, 5, 9, 12, 11, 7, 3},
        {10, 20, 30, 40, 35, 25, 5},
        {1, 2, 3, 4, 5, 3, 1}
    };

    for (auto &arr : tests) {
        cout << "Peak index: "
             << peakIndexInMountainArray(arr) << endl;
    }

    return 0;
}