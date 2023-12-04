#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <cassert>
#include <stack>
#include <string>

using namespace std;
using ll = long long;

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
*/


class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        for(auto c : s){
            
            if ( (c == '(') || (c == '{') || (c == '[') ){
                st.push(c);
            } else if ( (c == '}') && !st.empty() &&(st.top() == '{') ){
                st.pop();
            } else if ( (c == ']') && !st.empty() && (st.top() == '[') ){
                st.pop();
            } else if ( (c == ')') && !st.empty() && (st.top() == '(') ){
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.empty();
        
    }
};

int main() {
    Solution obj;

    std::string s = "()[]{}";

    auto start = std::chrono::system_clock::now();
    // auto result = std::chrono::system_clock
    auto result = obj.isValid(s);

    assert (result == 1);

    auto end = std::chrono::system_clock::now();

    long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds> (end-start).count();

    printf("Time taken %ld ns \n", elapsed);
    return 0;
}