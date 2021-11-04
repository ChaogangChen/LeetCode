/*
LeetCode 1 有效的括号
https://leetcode-cn.com/problems/valid-parentheses/
*/
#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> map = {
            {')','('},
            {']','['},
            {'}','{'}
        };
        stack<char> stk;
        for(char c:s){
            if (map.count(c)){
                if (stk.top()!= map[c] || stk.empty()){
                    return false;
                }
                stk.pop();
            }else{
                stk.push(c);
            }
        }
        return stk.empty();
    }
};

int main(){
    Solution test;
    bool res = test.isValid("(((((((((((((((((()");
    cout << "res:" << res << endl;
    return 0;
}