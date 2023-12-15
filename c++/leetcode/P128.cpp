#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
#include <cassert>
#include <chrono>

using namespace std;
using ll = long long;

/*

128. Longest Consecutive Sequence
Solved
Medium
Topics
Companies

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



*/


class Solution {
    public :
    int longestConsecutive(vector<int> &nums){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_set<int> st(nums.begin(), nums.end());
        int max_length = 0, max_length_at_i = 0;

        for(auto a : nums){
            if(st.find(a-1) == st.end()){
                // the num can be starting of new sequence
                // find the length of sequence starting from num
                max_length_at_i = 0;
                while(st.count(a++)) max_length_at_i++;
                max_length = max(max_length, max_length_at_i);
            }
        }


        return max_length;
    }
};


int main(){
    Solution obj;

    std::vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    auto start = std::chrono::system_clock::now();
    auto result = obj.longestConsecutive(nums);
    assert(result=9);
    auto end = std::chrono::system_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds> (end-start).count();
    printf("Time taken %ld ns \n", elapsed);
    return 0;
}