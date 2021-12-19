/*
LeetCode 400 第N位数字
https://leetcode-cn.com/problems/nth-digit/
*/

class Solution {
public:
    int findNthDigit(int n) {
        long i = 1;
        int j = 1;
        long range = 9;
        long range_0 = 0;
        while(1){
            if (n < range) {
                return (n - range_0 + i - 1) / j + ;
            }
            i *= 10;
            j++;
            range_0 = range;
            range +=  j * i * 9;
            
        }
        if (n < 10) return n;
        else if (n < 9 + 90*2 +1) return ;
        else if (n < 9 + 90*2 + 900*3 + 1);
        else if (n < 9 +)
    }
};