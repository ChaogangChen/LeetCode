/*
 * LeetCode 136 只出现一次的数字
 * https://leetcode-cn.com/problems/single-number/
 */ 
# include <iostream>
# include <vector>
using namespace std;
// 官方的异或运算，绝了！不使用外的空间
// 异或运算符合交换律、结合律、组合律，自己和自己异或的结果就是0，最后剩下的就是只出现一次的数
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};
