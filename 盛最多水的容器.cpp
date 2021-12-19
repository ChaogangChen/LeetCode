/*
LeetCode11 盛最多水的容器
https://leetcode-cn.com/problems/container-with-most-water/
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int b = height.size()-1;
        int a = 0;
        int res = 0;
        while (b>a){
            res = max((b-a) * max(b,a), res);
            if (height[a] <= height[b]) ++a;
            else --b;
        }
        return res;
    }
};
int main(){
    Solution test;
    vector<int> vec = {1,8,6,2,5,4,8,3,7};
    int res = test.maxArea(vec);
    cout << res << endl;
    return 0;
}