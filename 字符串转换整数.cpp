/*
LeetCode 8 字符串转换整数
https://leetcode-cn.com/problems/string-to-integer-atoi/
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool go = true;
        bool readingDigital = false;
        int flag = 1;
        long res=0;
        for(auto c:s){
            if(go){
                if(c==' ' && !readingDigital){continue;}
                else if(c == '-' && !readingDigital){flag = -1;readingDigital=true;}
                else if(c == '+' && !readingDigital){readingDigital = true;}
                else if(isdigit(c)){res = res*10 + int(c-48);}
                else break;
            }
        }
        return res;
    }
};

int main(){
    Solution test;
    int res = test.myAtoi(" 222");
    cout << res<<endl;
    return 0;
}