/*
LeetCode 13 罗马数字转整数
https://leetcode-cn.com/problems/roman-to-integer
*/
#include <string>
#include <map>
using namespace std;
map<char, int> symbolValues = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int n = s.length();
        for (int i = 0; i < n; i++){
            int value = symbolValues[s[i]];
            if (i < n - 1 && value < symbolValues[s[i + 1]]) {
                res -= value;
            } else {
                res += value;
            }
        }
        return res;
    }
};