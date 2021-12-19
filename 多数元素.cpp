/*
LeetCode 169 多数元素
https://leetcode-cn.com/problems/majority-element/
*/
#include <vector>
using namespace std;
#include <map>


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for (int n : nums){
            m[n]++;
            if (m[n] > nums.size()/2) return n;
        }
        return 0;
    }
};