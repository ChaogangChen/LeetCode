/* 
 * LeetCode 121 买卖股票的最佳时机
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 */
# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy = prices[0];
        int sell = prices[0];
        int bestSell = 0;
        for (int p : prices){
            sell = p > sell ? p : sell;
            bestSell = sell - buy > bestSell ? sell - buy : bestSell;
            if (p < buy) {
                buy = p;
                sell = p;
            }
        }
        return bestSell;
    }
};