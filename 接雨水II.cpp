/*
LeetCode 407 接雨水II
https://leetcode-cn.com/problems/trapping-rain-water-ii/
*/
# include <vector>
# include <iostream>
# include <algorithm>
# include <queue>
using namespace std;

/*
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        for(auto singleMap : heightMap){

        }
    }
};
*/
typedef pair<int,int> pii;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {  
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2) {
            return 0;
        }  
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i * n + j});
                    visit[i][j] = true;
                }
            }
        }

        int res = 0;
        int dirs[] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            pii curr = pq.top();
            pq.pop();            
            for (int k = 0; k < 4; ++k) {
                int nx = curr.second / n + dirs[k];
                int ny = curr.second % n + dirs[k + 1];
                if( nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
                    if (heightMap[nx][ny] < curr.first) {
                        res += curr.first - heightMap[nx][ny]; 
                    }
                    visit[nx][ny] = true;
                    pq.push({max(heightMap[nx][ny], curr.first), nx * n + ny});
                }
            }
        }
        
        return res;
    }
};


/* 解题思路
 * 逐层搜索法，逐层搜索每一层可以用来盛水的空间
 * 如果是墙，设为0，如果不是墙设为1
 * 寻找连通区域
 * 如果层内连通区域不和边界接触，计算积水区
 * 
 */
int main(){
    vector<vector<int>> a = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    Solution test;
    int res = test.trapRainWater(a);
    cout << "res: " << res << endl;
    return 0;
}