#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#include <cassert>

using namespace std;
using ll = long long;

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

 

Constraints:

    1 <= prices.length <= 3 * 104
    0 <= prices[i] <= 104


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