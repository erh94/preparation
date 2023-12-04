#include <bits/stdc++.h>
#include <algorithm>
#include <cassert>
#include <chrono>


using namespace std;

using ll = long long;


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int max_profit = 0 ;

        int l = 0;
        int r = 0;

        for(int r = 0; r < prices.size(); r++){
            if (prices[r] > prices[l]){
                max_profit += (prices[r] - prices[l]);
            }
            l = r;
        }


        // for(int i = 0; i < prices.size() - 1; i++) {
        //     if(prices[i+1] - prices[i] > 0) {
        //         max_profit += (prices[i+1] - prices[i]);
        //     }
        // }
        

        return max_profit;
    }
};

int main(){
    Solution obj;

    vector<int> prices = {7,1,5,3,6,4};

    auto start = std::chrono::system_clock::now();
    auto result = obj.maxProfit(prices);

    assert(result == 7);
    auto end = std::chrono::system_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds> (end - start).count();

    printf("Time taken %ld ns \n", elapsed);

    return 0;

}