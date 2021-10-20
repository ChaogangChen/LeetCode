#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    }
};

/*
思路1:暴力
start = 0
end = 0
for(int i=0;i<len(s);i++){
    local_start = i
    table = []
    for(int j=i;j<len(s);j++){
        if s[j] is not in table{
            table.append(s[i])
        }else{
            table=[]
            if{j-i > end-start}{start=i,end=j}
        }
    }
}
return s[i:j] 返回从i到j的闭区间
*/