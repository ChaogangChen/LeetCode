/*
LeetCode 17 电话号码的字母组合
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
*/
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        /*
        vector<string> res;
        for (char s: digits)依次取出来数字
            i = m[s]; 映射的字母
            curSize = res.size();
            for (char c: m[s])
                for (int i = 0; i < curSize; i++)
                    res.push_back(res[i]+c)
                    res = res(res.begin() + curSize - 1, res.end())
                    
        */
       map<char, string> m = {
           {'2',"abc"},
           {'3',"def"},
           {'4',"ghi"},
           {'5',"jkl"},
           {'6',"mno"},
           {'7',"pqrs"},
           {'8',"tuv"},
           {'9',"wxyz"},
       };
       vector<string> res;
       for (char s: digits){
            string tmp = m[s];
            int curSize = tmp.size();
            for (int i = 0; i < curSize; i++){
                string tt = res.front();
                for (char c : tmp){
                    res.push_back(tt+c);
                }
                res.erase(res.begin());
            }
       }
       vector<string> res_1(res.begin(),res.end());
       return res_1;
    }
};
int main(){
    Solution test;
    auto res = test.letterCombinations("234");
    for(auto s : res){
        cout << s <<endl;
    }
    return 0;
}