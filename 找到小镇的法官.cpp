/*
LeetCode 997 找到小镇的法官
https://leetcode-cn.com/problemset/all/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1);
        vector<int> outdegree(n+1);
        for (auto& edge : trust){
            int x = edge[0]; int y = edge[1];
            ++outdegree[x];
            ++indegree[y];
        }
        for (int i = 1; i <= n; ++i){
            if (indegree[i] == n - 1 && outdegree[i] == 0){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution test;
    vector<vector<int>> trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
    int res = test.findJudge(4, trust);
    cout << res << endl;
    return 0;
}