#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using ll = long long;
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: true

// Example 2:

// Input: nums = [1,2,3,4]
// Output: false

// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

// Constraints:

//     1 <= nums.length <= 105
//     -109 <= nums[i] <= 109

class Solution {
    private:
        // vector<int> nums;
    public:
        bool containsDuplicate(vector<int>&nums){

            std::set<int> nums_set{std::begin(nums), std::end(nums)};

            // for( auto const v : nums_set ) { cout << v << " "; }
            // cout << nums_set.size() <<std::endl;
            // for( auto const v : nums ) { cout << v << " "; }
            // cout << nums.size() <<std::endl;

            if (nums_set.size() == nums.size()) {
                return  false;
            }
            return true;
        }

        bool containsDuplicateUsingSort(vector<int>&nums){
            std::sort(std::begin(nums), std::end(nums));

            for(int i = 0; i < nums.size() -1 ; i++){
                if (nums[i] == nums[i+1]){
                    return true;
                }
            }

            return false;
        }
};

int main(){
    Solution obj;

    // vector<int> input = {1,1,1,3,3,4,3,2,4,2};
    vector<int> input = {1,2,3,4};

    auto start = std::chrono::system_clock::now();
    // auto result = obj.containsDuplicateUsingSets(input);
    auto result = obj.containsDuplicateUsingSort(input);
    auto end = std::chrono::system_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

    cout << "Contains Duplicate : " << result << std::endl;
    printf("Time taken %ld us \n", elapsed);
    return 0;
}