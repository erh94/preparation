#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>

using namespace std;
using ll = long long;

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

 

// Constraints:

//     2 <= nums.length <= 104
//     -109 <= nums[i] <= 109
//     -109 <= target <= 109
//     Only one valid answer exists.

class Solution
{
private:
    /* data */
public:
    vector<int>twosum(vector<int>& nums, int target){

        vector<int> res;
        std::unordered_map<int,int> map;

        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            auto sub = target - nums[i];
                if (map.find(sub) != map.end()){
                    if(i != map[sub]) {
                        res.push_back(i);
                        res.push_back(map[sub]);
                        break;
                    }
                }
        }

        return res;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {3,2,4};
    int target = 6;

    auto start = std::chrono::system_clock::now();
    vector<int> output = obj.twosum(nums, target);
    auto end = std::chrono::system_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

    cout << "Output ";
    for(auto a : output) cout << a << " ";
    printf("\nTime take %ld us \n", elapsed);
    return 0;
}