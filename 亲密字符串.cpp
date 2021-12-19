/*
LeetCode 859 亲密字符串
https://leetcode-cn.com/problems/buddy-strings/
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;
        if (s == goal){
            unordered_map<char,int> m;
            for (char tmp : s){
                m[tmp] ++;
                if (m[tmp] > 1) return true;
            }
            return false;
        }
        int first = -1;
        int second = -1;
        for (int i = 0; i < s.length(); i++){
            if (s[i]!=goal[i]){
                if (first == -1){ first = i;}
                else if (second == -1) {second = i;} //判断语句一定要用两个等号
                else return false;
            }
        }
        if (second == -1) return false;
        return s[first]==goal[second] && s[second]==goal[first];
    }
};