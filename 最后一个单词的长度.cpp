/*
LeetCode 58 最后一个单词的长度
https://leetcode-cn.com/problems/length-of-last-word/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.length() - 1; //!!!!!!!!!!!!!!!!!!!!!这里一定要记得减一，起始条件不能错
        while (s[index] == ' ') {index --;}
        int length = 0;
        while (index >= 0 && s[index] != ' '){ //!!!!!!!!!!!!!!!!!!!!!!!!!这里中间一定要用与，不能用或！！！！！！！！！！！！！！！注意判断的顺序不能混乱
            index --;
            length ++;
        }
        return length;
    }
};