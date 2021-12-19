/*
LeetCode 391 完美矩形
https://leetcode-cn.com/problems/perfect-rectangle/
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> mp;
        for (auto &item : rectangles) {
            mp[{item[0], item[1]}]++;
            mp[{item[0], item[3]}]--;
            mp[{item[2], item[3]}]++;
            mp[{item[2], item[1]}]--;
        }
        int cnt = 0, ans;
        for (auto &item : mp)
            if (item.second)
                cnt++, ans = item.second;
        return cnt == 4 && abs(ans) == 1;
    }
};

/*
 * 思路：计算所有矩形覆盖的面积，以及极限点的面积，两者相等就说明是完美矩形
 *
 * 
 * 
 */