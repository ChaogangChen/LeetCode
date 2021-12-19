/*
LeetCode 397 整数替换
https://leetcode-cn.com/problems/integer-replacement/
*/
#include <algorithm>
using namespace std;
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n % 2 == 0) return 1+integerReplacement(n/2);
        else return min(integerReplacement(1+n),integerReplacement(n-1))+1;
    }
};