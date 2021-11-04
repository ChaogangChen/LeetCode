#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

//解法一：暴力算法，复杂度n^2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)return 0;//!!!!!!!!!!!!!!!!!!!!!!!用于判定空字符串
        int flag = 0;
        int start = 0;
        int end = 0;
        for(int i=0;i<s.length();i++){
            
            string table = "";
            for(int j=i;j<s.length();j++){
                if(table.find(s[j])==string::npos){
                    table=table+s[j];

                }else{
                    table = "";
                    if(j-i > end-start){start = i; end=j;}
                    //cout<<"第"<<i<<"次，start="<<start<<"end="<<end<<endl;
                    flag = 1;
                    break;//！！！！！！！！！！！！！这里的break起到退出函数的作用
                }
            }
        }
        string table=""; //！！！！！！！！！！！这里避免了变量局部作用于造成的bug
        //!!!!!!!!!!!!!!!!!下面这一段用于识别出现在末尾的连续字符串
        for(int i=s.length();i>=0;i--){
            if(table.find(s[i])==string::npos){
                    table=table+s[i];
            }else{
                break;
            }
        }
        if(table.length()-1>end-start) return table.length()-1;
        if(flag)return (end-start);
        else return s.length();
    }
};

//解法2，窗口算法，复杂度O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxSize = 0;
        unordered_set<char> lookup;
        for(int i=0; i<s.length(); i++){
            while(lookup.find(s[i]) != lookup.end()){ //当find没找到元素的时候返回end，找到的时候返回元素的位置
                lookup.erase(s[left]); //!!!!!!!!!!!!!!!这里需要删掉最左边的元素才能实现移动窗口的目的，如果错删成s[i]会造成执行bug
                left = left+1;
            }
            maxSize = max(maxSize,i-left+1);
            lookup.insert(s[i]);
        }
        return maxSize;
    }
};

int main(){
    Solution a;
    int res = a.lengthOfLongestSubstring("cdd");
    cout << res<<endl;
    return 0;
}

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
思路二：递归 ！！！！！！！！可行性有待商榷
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

/*
思路三：滑动窗口，这种算法的时间复杂度为O(n)
创建初始窗口
start = 0
end = 0
while(end<=s.length()){
    if 不重复s[end] in s[start:end+1]：
        扩列 end = end+1
        continue
    else if 重复s[end] not in s[start:end+1]:
        移动队列 start = start+1;end = end+1
        continue
    end = end+1;
}
!!!!!!!!!!!!!!!!
答案中的另一种循环
left = 0;
maxSize = 0;
tmp = [];
for(int i =0;i<s.length();i++){
    while s[i] in tmp:
        from tmp delete s[i]
        left ++
    tmp = tmp+s[i]
    maxSize = max(maxSize,i-left+1)
return maxSize
}

！！！！！！！！！

return end-start
*/