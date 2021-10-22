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

/*
思路二：递归
int find(string s, int start=0, int end=len(s)-1){
基态 
if start==end: 
    return [s_start,s_end,s_len]
左分支
mid = start + (end-start)>>1
res = find(s,start,mid)
右分支
res = find(s,mid+1,end)
跨中间分支
res = find_cross(x,mid)
}
int find_cross(string s, int start, int end){
    mid = start + (end-start)>>1
}
*/
