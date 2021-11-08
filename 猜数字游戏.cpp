/*
LeetCode 299 猜数字游戏
https://leetcode-cn.com/problems/bulls-and-cows/
*/
# include <string>
# include <map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.empty()) return "0A0B";
        int bull = 0;
        int cow = 0;
        map<char,int> m;
        for(int i = 0;i < secret.length(); i++){
            if (secret[i] == guess[i]) bull ++;
            if (m [secret[i]] < 0){
                cow ++;
                m[secret[i]] ++;
            }
            if (m[guess[i]] > 0) {
                m[guess[i]] --;
                cow ++;
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};