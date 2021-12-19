/*
LeetCode 495 提莫攻击
https://leetcode-cn.com/problems/teemo-attacking/
*/
# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 1) return duration;
        int res = duration;
        for (int i = timeSeries.size()-1; i > 0; i--){
            res += timeSeries[i] - timeSeries[i-1] > duration-1 ? duration : timeSeries[i] - timeSeries[i-1];
        }
        return res;
    }
};