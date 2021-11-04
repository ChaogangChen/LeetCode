/*
LeetCode 573 分糖果
https://leetcode-cn.com/problems/distribute-candies/
*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> set;
        for (auto candy : candyType){
            if (set.find(candy) != set.end()) set.insert(candy);
        }
        return set.size() > candyType.size() / 2 ? candyType.size() / 2 : set.size();
    }
};

