/*
LeetCode 384 打乱数组
https://leetcode-cn.com/problems/shuffle-an-array/
*/
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->original = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    //shuffle1这种算法很慢
    vector<int> shuffle1() {
        /*
        一个空vector，一个复制出来的栈，栈里面出来的元素放到vector任意位置
        */
        vector<int> s;
        list<int> l(nums.begin(),nums.end());
        while(!l.empty()){
            int tmp = rand()%l.size();
            auto it = l.begin();
            advance(it,tmp);
            s.push_back(*it);
            l.erase(it);
        }
        copy(s.begin(),s.end(),nums.begin());
        return nums;
    }
    vector<int> shuffle(){

        for (int i = 0; i < nums.size(); ++i) {
            int j = i + rand() % (nums.size() - i);
            swap(nums[i], nums[j]);}
    }
private:
    vector<int> nums;
    vector<int> original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */