/*
LeetCode 318 最大单词长度乘积
https://leetcode-cn.com/problems/maximum-product-of-word-lengths/
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


//这种方法超出时间限制了
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxSize = 0;
        for(int i = 0 ; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                map<char,int> m;
                map<char,int> n;
                int flag = 0;
                for(auto a : words[i]) m[a] = 1;
                for(auto b : words[j]){
                    n[b] ++;
                    if (n[b] > 1) continue;
                    m[b] ++;
                    if (m[b] > 1) {flag = 1;break;}
                }
                if (flag==1) continue;
                if (words[i].size()*words[j].size() > maxSize){
                    cout << words[i] << endl << words[j] << endl;
                }
                maxSize = words[i].size()*words[j].size() > maxSize ? words[i].size()*words[j].size(): maxSize;
                
            }
        }
        return maxSize;
    }
};

//下面这种是官方的解法，使用位运算完成整个算法题
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int length = words.size();
        vector<int> masks(length);
        for (int i = 0; i < length; i++) {
            string word = words[i];
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                masks[i] |= 1 << (word[j] - 'a');
            }
        }
        int maxProd = 0;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }
};


int main(){
    Solution test;
    vector<string> aaa = {"eae","ea","aaf","bda","fcf","dc","ac","ce","cefde","dabae"};
    auto res = test.maxProduct(aaa);
    printf("res:%d",res);
    return 0;
}