/*
LeetCode 9 回文数
https://leetcode-cn.com/problems/palindrome-number/
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        vector<int> vec;
        int num = 0;
        int rem = x;
        while (x>0){
            num = num * 10 + rem%10;
            vec.push_back(x%10);
            num++;
            x = x/10;
        }
        for (int i = 0; i < vec.size()/2;i++){
            if (vec[i]!=vec[vec.size()-i-1]) return false;
        }
        return true;
    }
};