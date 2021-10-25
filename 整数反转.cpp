/*
LeetCode 7 整数反转
https://leetcode-cn.com/problems/reverse-integer/
*/
#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long n=0;
        while(x){
            n = n*10+x%10; //!!!!!!!!!!负数对10取余就相当于正数取余加负号
            x/=10;
        }
        return n>INT_MAX || n<INT_MIN?0:n;
    }
};