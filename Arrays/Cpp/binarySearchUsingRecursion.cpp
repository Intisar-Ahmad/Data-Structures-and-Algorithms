#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int st, int end, int target)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return binarySearch(arr, 0, mid - 1, target);
        else if (arr[mid] < target)
            return binarySearch(arr, mid + 1, end, target);
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << binarySearch(arr, 0, 5, 3);
    return 0;
}