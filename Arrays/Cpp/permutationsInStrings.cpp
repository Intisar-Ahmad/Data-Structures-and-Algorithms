#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 bool isFreqSame(int freq[], int wFreq[]) {
        for(int i = 0; i < 26; i++){
            if(freq[i] != wFreq[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        

        int n = s1.length();
        int n2 = s2.length();

        if(n > n2) return false;

        // build freq for s1
        for(int i = 0; i < n; i++){
            freq[s1[i] - 'a']++;
        }

        // brute force windows
        for(int i = 0; i <= n2 - n; i++){
           int windowFreq[26] = {0};

            int windowIdx = 0, idx = i;

            while(windowIdx < n && idx < n2){
                windowFreq[s2[idx] - 'a']++;
                idx++;
                windowIdx++;
            }

            if(isFreqSame(freq, windowFreq)){
                return true;
            }
        }

        return false;
    }

int main() {
 
    return 0;
}