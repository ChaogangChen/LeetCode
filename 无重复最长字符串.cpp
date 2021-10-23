#include <iostream>
#include <string>
using namespace std;

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

