#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>

using namespace std;
using ll = long long;

/* 
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int max_profit = 0;

        // n2 bruteforce solution 

        // two pointer problem
        int L = 0, R = 0;

        for(R = 0; R < prices.size(); R++) {

            if(prices[R] < prices[L]) {
                // update L if R is less than L
                L = R;
            } else if ((prices[R] - prices[L]) > max_profit) {
                // if R > L, then possibility of max_profit update
                max_profit = prices[R] - prices[L];
            } else {
                continue;
            }
        }
        
        return max_profit;
        
    }
};

int main(){
    Solution obj;

    vector<int> prices = {7,1,5,3,6,4};

    auto start = std::chrono::system_clock::now();
    int output = obj.maxProfit(prices);
    auto end = std::chrono::system_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

    cout << "Max Profit : " << output;
    printf("\nTime take %ld ns \n", elapsed);
    return 0;
}