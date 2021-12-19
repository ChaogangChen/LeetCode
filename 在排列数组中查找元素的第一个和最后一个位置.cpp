/*
LeetCode 34 在排列数组中查找元素的第一个和最后一个位置
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        while(l <= r){
            mid = l + ((r - l) / 2);
            if (nums[mid] > target){
                r = mid - 1;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else if(nums[mid] == target){
                l = mid;
                r = mid;
                while (nums[l] == target) l--;
                while (nums[r] == target) r++;
                return {l + 1, r - 1};
            }
        }
        return {-1,-1};
    }
};
