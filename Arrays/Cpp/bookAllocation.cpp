#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Book Allocation Problem

You are given an array A of N integers, where each element represents the number of pages in a book. There are M students.

Your task is to allocate books to students such that:

Each student gets at least one book.

Each book is assigned to exactly one student.

Books must be allocated in contiguous order.

The objective is to minimise the maximum number of pages assigned to any student.

Return the minimum possible value of the maximum pages assigned.

If allocation is not possible, return -1.*/

int sumArray(vector<int> arr)
{
    int n = arr.size();

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

bool isValid(vector<int> arr, int mid, int numberOfStudents)
{
    int size = arr.size();
    int studentCount = 1;
    int sumCount = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] > mid){
            return false;
        }

        if (sumCount + arr[i] <= mid)
        {
            sumCount += arr[i];
        }
        else
        {
            sumCount = arr[i];
            studentCount++;
        }
    }

    if (studentCount > numberOfStudents)
    {
        return false;
    }
    return true;
}

// i know that the name is kinda weird
int minMaxPage(vector<int> arr, int numberOfStudents)
{
    int st = 0;
    int end = sumArray(arr);
    int min = -1;

    if (numberOfStudents > arr.size())
        return -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(arr, mid, numberOfStudents))
        {
            min = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    return min;
}

int main()
{
    vector<int> v1 = {12, 34, 67, 90};
    vector<int> v2 = {15, 30, 45};
    vector<int> v3 = {100, 200, 300, 400};

    cout << minMaxPage(v1, 2) << endl;
    cout << minMaxPage(v2, 4) << endl;
    cout << minMaxPage(v3, 3) << endl;

    return 0;
}