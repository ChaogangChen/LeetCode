/*
LeetCode 1218 最长定差子序列
https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/
*/
# include <vector>
# include <unordered_map>
# include <algorithm>
# include <iostream>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0;
        unordered_map<int, int> dp;
        for (int v : arr){
            dp[v] = dp[v-difference] + 1;
            res = max(res, dp[v]);
        }
        return res;
    }
};

int main(){
    Solution test;
    vector<int> arr = {1,2,3,4};
    int res = test.longestSubsequence(arr, 1);
    cout << "res" << res << endl;
    return 0;
}