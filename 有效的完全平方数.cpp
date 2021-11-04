/*
 * LeetCode 367 有效的完全平方数
 * https://leetcode-cn.com/problems/valid-perfect-square/
 * 
 */
// 使用了奇数和就是平方数的原理，验证这个数是不是奇数的加和也就验证了这个数是否可被开方。
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0){
            num = num - i;
            i += 2;
        }
        return num == 0;
    }
};