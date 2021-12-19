/*
LeetCode 519 随机翻转矩阵
https://leetcode-cn.com/problems/random-flip-matrix/
*/
// 核心就是生成不重复的随机数
#include <iostream>
#include <unordered_map>
#include <time.h>
using namespace std;

class Solution {
public:
    Solution(int m,int n){
        this->m = m;
        this->n = n;
        this->total = m*n;
        srand(time(nullptr));
    }

    vector<int> flip() {
        //随机生成一个随机数
        int x = rand() % total;
        vector<int> ans;
        //限制随机数可以生成的位置
        total --;
        //记录当前位置
        // 查找位置 x 对应的映射
        if (map.count(x)) { // 判断x的位置是否已经被占用了，map中没有就是没被占用，可直接使用x的值计算点的位置
            ans = {map[x] / n, map[x] % n};
        } else {
            ans = {x / n, x % n};
        }
        // 将位置 x 对应的映射设置为位置 total 对应的映射
        if (map.count(total)) {//total位置可能在之前已经被反转过了，这里存储的是之前一次翻转的位置
            map[x] = map[total];// 如果已经生成过一次x，借用map返回一个没被占用的位置
        } else {
            map[x] = total;// 如果没生成过x，直接用x返回一个位置
        }
        return ans;
    }
    
    void reset() {
        this->total = m*n;
        map.clear();//!!!!!!!!!!!!!!!!!!!记得哈希表需要清零
    }
private:
    int m;
    int n;
    int total;
    // 这个哈希表只起到辅助作用，并不能记录已经生成过的点
    unordered_map<int,int> map;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */