/*
LeetCode 748 最短补全词
https://leetcode-cn.com/problems/shortest-completing-word/
*/

#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        array<int, 26> cnt{};
        for (char ch : licensePlate){
            if (isalpha(ch)) {
                ++cnt[tolower(ch)-'a'];
            }
        }
        int a = 0;
        string res;
        int bigger = INT_MAX; // 这里定义一定要在循环外，要不然会报错！！！！！
        for (string word : words){
            array<int,26> tmp{}; // ！！！！！！！！！！！这里一定要带上大括号，要不然数组不会被清空
            for (char ch : word){
                ++tmp[ch - 'a'];
            }
            bool ok = true;
            int bigger_num = 0;
            for (int i = 0; i < 26; i++){
                if (tmp[i] < cnt[i]) ok = false;
                else if (tmp[i] > cnt[i]) bigger_num += (tmp[i]-cnt[i]); 
            }
            if (ok){
                if (bigger_num < bigger) {
                    res = word;
                    bigger = bigger_num;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution test;
    string liencePlate = "1s3 456";
    vector<string> words = {"looks", "pest", "stew", "show"};
    auto res = test.shortestCompletingWord(liencePlate,words);
    cout << res << endl;
    return 0;
}