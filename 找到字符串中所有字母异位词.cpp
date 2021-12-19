/*
LeetCode 438 找到字符串中所有字母异位词
https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        if (sLen < pLen) return vector<int>();
        for (int i = 0; i < pLen; i++){
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if(sCount == pCount){
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i){
            --sCount[s[i]-'a'];
            ++sCount[s[i + pLen] - 'a'];

            if (sCount == pCount){
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};