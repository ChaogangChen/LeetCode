/*
LeetCode 46 全排列
https://leetcode-cn.com/problems/permutations/
*/
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        queue<int> tt;
        for (int n : nums) {
            tt.push(n);
        }
        gen(tt, {});
        return res;
    }
    void gen(queue<int> nums, vector<int>tmp){
        if (nums.size() == 0) {this->res.emplace_back(tmp);return;} // push_back()换成emplace_back()能解加快速度
        for(int i = 0; i < nums.size(); i++){
            int t = nums.front();
            nums.pop();
            tmp.emplace_back(t);
            gen(nums,tmp);
            tmp.pop_back();
            nums.push(t);
        }
    }
private:
    vector<vector<int>> res;
};