/*
LeetCode 786 第K个最小的素数分数
https://leetcode-cn.com/problems/k-th-smallest-prime-fraction/
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // 整体思路：逐个插入排序，最后返回第k个
        int n = arr.size();
        vector<pair<int,int>> frac;
        for (int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                frac.emplace_back(arr[i],arr[j]);
            }
        }
        sort(frac.begin(),frac.end(),[&](const auto& x,const auto& y){
            return x.first * y.second < x.second * y.first;
        }); // 这步使用了sort的一种高级方式
        return {frac[k - 1].first, frac[k - 1].second};
    }
};

int main(){
    Solution test;
    vector<int> arr = {1,2,3,5};
    auto res = test.kthSmallestPrimeFraction(arr, 2);
    for (auto num : res){
        cout << num << endl;
    }
    return 0;
}