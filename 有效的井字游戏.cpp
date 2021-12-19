/*
LeetCode 794 有效的井字游戏
https://leetcode-cn.com/problems/valid-tic-tac-toe-state/
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x_num = 0;
        int o_num = 0;
        for (string line : board){
            for (char p : line){
                if (p == 'X') x_num ++;
                else if (p == 'O') o_num ++;
            }
        }
        if ((x_num - o_num) != 0 || (x_num - o_num) != 1) return false;
        if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) return false;
        if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) return false;
        if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) return false;
        if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) return false;
        if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) return false;
        if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) return false;
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return false;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return false;
        return true;
    }
};

int main(){
    Solution test;
    vector<string> t = {"XOX","O O","XOX"};
    bool res = test.validTicTacToe(t);
    cout << res << endl;
    return 0;
}