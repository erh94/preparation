#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using ll = long long;
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:

// Input: s = "rat", t = "car"
// Output: false

 

// Constraints:

//     1 <= s.length, t.length <= 5 * 104
//     s and t consist of lowercase English letters.

 

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

class Solution{
    public:
        bool isAnagram(string s, string t){

            if (s.length() != t.length()){
                return false;
            }

            std::unordered_map<char,int> counts;

            for (int i = 0; i < s.length(); i++){
                counts[s[i]]++;
                counts[t[i]]--;
            }

            for (auto a : counts){
                if (a.second != 0){
                        return false;
                    }
            }

            return true;

        }

};


int main(){
    Solution obj;

    std::string s = "anagram";
    std::string t = "nagaram";

    auto start = std::chrono::system_clock::now();
    // auto result = obj.containsDuplicateUsingSets(input);
    auto result = obj.isAnagram(s,t);
    auto end = std::chrono::system_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

    cout << "Is Anagram : " << result << std::endl;
    printf("Time taken %ld us \n", elapsed);
    return 0;
}