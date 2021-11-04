/*
LeetCode 70 爬楼梯
https://leetcode-cn.com/problems/climbing-stairs/
*/
# include <iostream>
using namespace std;

// 递归解法
class Solution {
public:
    int nums = 0;
    int climbStairs(int n) {
        if (n == 1) {nums = nums + 1; return nums;}
        if (n == 0) return nums;
        if (n == 2) return 2;
        if (n > 2) {nums = climbStairs(n-1) + climbStairs(n-2); return nums;}
    }
};

// 动态规划解法
class Solution1 {
public:
    int climbStairs(int n){
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a = 1;
        int b = 2;
        int res = 0;
        for (int i = 0; i < n - 2; i++){
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};

int main(){
    Solution1 test;
    int res = test.climbStairs(6);
    cout << "res:" << res << endl;
    return 0;
}