/*
LeetCode 5.最大回文字符串
https://leetcode-cn.com/problems/longest-palindromic-substring/
*/
#include <unordered_set>
#include <iostream>
#include <string>
using namespace std;
// 思路一
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 0;
        string answer="";
        if(s!="")answer = s[0];
        for(int i=1; i<s.length();i++){
            int j = 1;
            while( i-j>=0 && i+j<s.length()){
                if (s[i-j]!=s[i+j]) break; //!!!!!!!!!!!!!!!!!!!!!!!!!如果把s[i-j]!=s[i+j]写到while里，会报数组溢出的错误
                if(j*2+1>answer.length()){
                    answer = s.substr(i-j,2*j+1);
                }   
                j++;
            }  
            int k = 1;
            while(i-k>=0 && i+k-1<s.length()){
                if (s[i-k]!=s[i+k-1]) break;
                if(k*2>answer.length()){
                    answer = s.substr(i-k,2*k);//!!!!!!!!!!!!!!!!!!!!substr的用法是从a开始的位置，截取b个字符！！！！别用错!!!!
                }   
                k++;
            }
        }   
        return answer;
    }
};

int main(){
    Solution test;
    string answer = test.longestPalindrome("ac");
    cout << answer<<endl;
    return 0;
}


/*
思路一：暴力求解 复杂度O（n）
找出字符串中所有符合ABA形式的字符串，然后拓展字符串的边界
*/