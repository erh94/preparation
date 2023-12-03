#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#include <cassert>

using namespace std;
using ll = long long;

/*

*/


class Solution {
public:
    bool isPalindrome(string s) {

        // two pointer approach
        // L starts from left, R start from right compare each character, should match till L < R
        // need some pre-processing for special charcters to ignore

        // Base case
        if ((s.size() == 0) || (s.size() == 1)) return true;
        
        int L = 0, R = s.size() - 1;

        while (L < R){

            while((L < R) && !isalnum(s[L])) L++;
            while((L < R) && !isalnum(s[R])) R--;

            if(tolower(s[L])  != tolower(s[R])) return false;

            L++;
            R--;

        }

        return true;
    }
};



int main(){
    Solution obj;

    std::string incorrect = "race a car";
    std::string correct = "A man, a plan, a canal: Panama";

    auto start = std::chrono::system_clock::now();
    auto result = obj.isPalindrome(incorrect);
    assert(result == 0);
    result = obj.isPalindrome(correct);
    assert(result == 1);
    auto end = std::chrono::system_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

    printf("Time taken %ld ns \n", elapsed);
    return 0;
}