/*
LeetCode 6: Z字形变换
https://leetcode-cn.com/problems/zigzag-conversion/
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> arr(min(numRows,int(s.length())));

        int curRow = 0;
        bool goingDown = true;
        /*下面这一段这样写更简单，不用定义i，没有复杂数学运算
        
        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        */
        int i = 0;
        for(char c:s){ //!!!!!!!!!!!!!!!!!!需要学会用这种先进的迭代方法
            arr[curRow]+=c;//!!!!!!!!!!!!!!!!!!这一步赋值不能忘掉
            if(i%(2*numRows-2)-numRows+1<0) {goingDown = true;}else goingDown = false; //!!!!!!!!!!!!!!!这种用算数方法判断很容易出错
            curRow += goingDown?1:-1;
            i=i+1;
        }
    string ans;
    for(string tmp:arr){
        ans = ans+tmp;
    }
    return ans;
    }
};

int main(){
    Solution test;
    string res = test.convert("PAYPALISHIRING",3);
    cout<<res<<endl;
    return 0;
}

/*
思路一：用vector容器，逐个放

*/