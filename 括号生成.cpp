/*
LeetCode 22 括号生成
https://leetcode-cn.com/problems/generate-parentheses/
*/
#include <vector>
#include <string>
using namespace std;
//递归牛逼！！！！！！！！！！！！！！！！！
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if(n<=0) return res;
        genRes("",n,n);
        return res;
    }
    void genRes(string s, int left, int right){
        if (left==0 && right ==0){
            res.push_back(s);
            return;
        }
        if (left == right){
            genRes (s+'(',left-1,right);
        } 
        if (left < right){
            if(left == 0) genRes(s+')',left,right-1);
            else if (left > 0){
                genRes(s+'(', left-1, right);
                genRes(s+')', left, right-1);
            }
        }
    }
};