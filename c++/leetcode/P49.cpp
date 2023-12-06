#include <bits/stdc++.h>
#include <algorithm>
#include <cassert>
#include <chrono>

using namespace std;
using  ll = long long;

/*

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

 

Constraints:

    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.




*/

class Solution {

    public :
    
    vector<vector<string>> groupAnagrams(vector<string> &strs){
        vector<vector<string>> ans;

        int N = strs.size();
        vector<string> sorted_strs(N);
        // sort string inside vector
        for(int i = 0; i < N; i++){
            sorted_strs[i] = strs[i];
            sort(sorted_strs[i].begin(), sorted_strs[i].end());
        }

        // map m 
        unordered_map<string, vector<string>> m;

        for(int i = 0; i < N; i++){
            if (m.count(sorted_strs[i])) {
                // already existing
                m[sorted_strs[i]].push_back(strs[i]);
            } else {
                // new entry
                m[sorted_strs[i]] = {strs[i]};
            }
        }


        // create final ans
        for (auto a : m){
            ans.push_back(a.second);
        }

        return ans;

    }
};


int main(){

    vector<string> test_case = {"eat","tea","tan","ate","nat","bat"};

    Solution obj;

    vector<vector<string>> test_ans = {{"bat"},{"nat","tan"},{"ate","eat","tea"}};

    auto start = chrono::system_clock::now();

    auto ans = obj.groupAnagrams(test_case);

    auto end = chrono::system_clock::now();

    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    
    printf("Time taken %ld ns \n", elapsed);

    std::cout << "{";
    for(auto a : test_ans){
        std::cout << "{";
        for(auto b : a){
            std::cout << "\""<< b <<"\" ";
        }
        std::cout<<"}";
    }
    std::cout<<"}";

    return 0;



}