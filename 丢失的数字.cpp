/*
LeetCode 268 丢失的数字
https://leetcode-cn.com/problems/missing-number/
*/
# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> set;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            set.insert(nums[i]);
        }
        int missing = -1;
        for (int i = 0; i <= n; i++) {
            if (!set.count(i)) {
                missing = i;
                break;
            }
        }
        return missing;
    }
};
