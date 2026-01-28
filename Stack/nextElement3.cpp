#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>



using namespace std;

int nextGreaterElement(int n) {
        int digits[11];
        int len = 0;
        long long temp = n;

        while (temp > 0) {
            digits[len++] = temp % 10;
            temp /= 10;
        }

        int pivot = -1;
        for (int i = 1; i < len; i++) {
            if (digits[i] < digits[i - 1]) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) return -1;


        for (int i = 0; i < pivot; i++) {
            if (digits[i] > digits[pivot]) {
                swap(digits[i], digits[pivot]);
                break;
            }
        }

        int start = 0, end = pivot - 1;
        while (start < end) {
            swap(digits[start++], digits[end--]);
        }

        long long result = 0;
        for (int i = len - 1; i >= 0; i--) {
            result = result * 10 + digits[i];
        }
        return (result > INT_MAX) ? -1 : (int)result;
    }

int main() {
 
    return 0;
}