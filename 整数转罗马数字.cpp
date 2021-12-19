/*
LeetCode 12 整数转罗马数字
https://leetcode-cn.com/problems/integer-to-roman/
*/
#include <string>
using namespace std;
// 题解提供了两种方式，分别是模拟法和硬编码数字
// 模拟法
namespace s1{
    const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        for (const auto [value, sym] : valueSymbols){
            while (value <= num) {
                num -= value;
                res  = res + sym;
            }
        }
        return res;
    }
};
};

// 硬编码数字
namespace s2{
    const string thousands[] = {"", "M", "MM", "MMM"};
    const string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    class Solution {
        public:
        string intToRoman (int num){
            return thousands[num / 1000] + hundreds[num /100 % 10] + tens[num / 10 % 10] + ones[num % 10];
        }
    };

};

int main(){
    s2::Solution test;
    string res = test.intToRoman(12);
    printf("结果是%s\n",res.c_str());
    return 0;
}

// class Solution {
// public:
//     string intToRoman(int num) {
//         string res = "";
//         string symbol = "IVXLCDM ";
//         int one = 0;
//         int five = 1;
//         while (num > 0){
//             int cur = num % 10;
//             num = num / 10;
//             if (cur == 1) res = symbol[one] + res;
//             else if (cur == 2) res = symbol[one] + symbol[one] + res;
//             else if (cur == 2) res = symbol[one] + symbol[one] + symbol[one] + res;
//             one += 2;
//         }
//     }
// };

