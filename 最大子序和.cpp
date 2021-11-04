/*
LeetCode 53 最大子序和
https://leetcode-cn.com/problems/maximum-subarray/
*/
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution{
public:
    int maxSubArray(vector<int>& nums){
        if(nums.size()==1) return nums[0];
        vector<int> leftArray(nums.begin(),nums.begin()+floor(nums.size()/2)); 
        int leftMax = maxSubArray(leftArray);
        vector<int> rightArray(nums.begin()+floor(nums.size()/2),nums.end()); 
        int rightMax = maxSubArray(rightArray);
        // 从中间找最大值
        int midMaxLeft = 0;
        int tmp = 0;
        for (int i = floor(nums.size()/2);i>=0;i--){
            tmp = tmp + nums[i];
            if(tmp > midMaxLeft) midMaxLeft = tmp;
        }
        int midMaxRight = 0;
        tmp = 0;
        for (int i = floor(nums.size()/2)+1;i<nums.size();i++){ //!!!!!!!!!!!!!!!注意边界条件的选取
            tmp = tmp + nums[i];
            if (tmp > midMaxRight) midMaxRight = tmp;
        }
        int midMax = midMaxRight + midMaxLeft;
        if (midMax == 0) midMax = nums[floor(nums.size()/2)]>nums[floor(nums.size()/2-1)]?nums[floor(nums.size()/2)]:nums[floor(nums.size()/2)-1];//!!!!!!!小心返回数组溢出
        if (leftMax >= rightMax && leftMax >= midMax) return leftMax; //!!!!!!!!!!!!!!!!!!注意这里不能写或，要写与！！！！！！！！！
        if (rightMax >= midMax) return rightMax;
        else return midMax;
    }
};

//!!!!!!!!!封神的动态规划算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};
/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int main(){
    Solution test;
    vector<int> nums = {-2,-1};
    auto res = test.maxSubArray(nums);
    cout << "res:" << res << endl;
    int midMaxLeft = 0;
    int tmp = 0;
    for (int i = floor(nums.size()/2);i>=0;i--){
        tmp = tmp + nums[i];
        if(tmp > midMaxLeft) midMaxLeft = tmp;
    }
    int midMaxRight = 0;
    tmp = 0;
    for (int i = floor(nums.size()/2)+1;i<nums.size();i++){
        tmp = tmp + nums[i];
        if (tmp > midMaxRight) midMaxRight = tmp;
    }
    int midMax = midMaxRight + midMaxLeft;
    cout <<"midMax"<<midMax<<endl;

    return 0;
}