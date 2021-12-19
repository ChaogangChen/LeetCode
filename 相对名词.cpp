/*
LeetCode 506 相对名次
https://leetcode-cn.com/problems/relative-ranks/
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        if (score.size() == 1) return {"Gold Medal"};
        if (score.size() == 2) {
            if (score[0] > score[1]) return {"Gold Medal", "Silver Medal"};
            else return {"Silver Medal", "Gold Medal"};
        }
        if (score.size() > 2) {
            int first = 0;
            int second = 1;
            int third = 2;
            if (score[0] > score[1] && score[1] > score[2]){first = 0; second = 1; third = 2;}
            else if (score[0] > score[2] && score[2] > score[1]){first = 0; second = 2; third = 1;}
            else if (score[1] > score[0] && score[0] > score[2]){first = 1; second = 0; third = 2;}
            else if (score[1] > score[2] && score[2] > score[0]){first = 1; second = 2; third = 0;}
            else if (score[2] > score[0] && score[0] > score[1]){first = 2; second = 0; third = 1;}
            else if (score[2] > score[1] && score[1] > score[0]){first = 2; second = 1; third = 0;}
            for (int i = 3; i < score.size(); i++){
                if (score[i]>first){third = second; second = first; first = score[i];}
                else if (score[i] > second){third = second; second = score[i];}
                else if (score[i] > third) {third = score[i];}
            }
        }
    }
};