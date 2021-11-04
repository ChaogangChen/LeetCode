/*
LeetCode 301 删除无效括号
https://leetcode-cn.com/problems/remove-invalid-parentheses/
*/
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;


//!!!!!!!!!!!!!!!!!!!这是自己写的一次失败尝试
class SolutionDontWork {
public:
    vector<string> removeInvalidParentheses(string s) {
        int num=0;
        vector<vector<string>> vec;
        string tmp = "";
        for(auto c:s){
            if (c == '(') num ++;
            else if (c ==')') num--;
            vector<string> a;
            tmp = tmp + c;
            if (num<0){/*遍历：在c前面(包含c)取一个')'删除，去除冗余，并将前面这一段得到的放入新的临时表中；num归零*/
                for (auto tmp_c : tmp){
                    if (tmp_c != ')'){//没有出现右括号，给每个vector放一个当前字符
                        for (auto inner_s : a){
                            inner_s = inner_s + tmp_c;
                        }
                    }else{//出现右括号，复制a最后的一个string放到末尾，给除新复制的字符之外的所有字符末尾加右括号
                        if (a.empty()) {num = 0; tmp = ""; break;}
                        else{}
                    }
                }
                num = 0;
                tmp = "";
            }
        }
        //组合所有的临时表，返回合理的数值
    }
};


class Solution {
public:
    bool isValid(string str) {
        int count = 0;

        for (char c : str) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) {
                    return false;
                }
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> currSet;

        currSet.insert(s);
        while (true) {
            for (auto & str : currSet) {
                if (isValid(str))
                    ans.emplace_back(str);
            }
            if (ans.size() > 0) {
                return ans;
            }
            unordered_set<string> nextSet;
            for (auto & str : currSet) {
                for (int i = 0; i < str.size(); i++) {
                    if (i > 0 && str[i] == str[i - 1]) {
                        continue;
                    }
                    if (str[i] == '(' || str[i] == ')') {
                        nextSet.insert(str.substr(0, i) + str.substr(i + 1, str.size()));
                    }
                }
            }
            currSet = nextSet;
        }
    }
};
/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/shan-chu-wu-xiao-de-gua-hao-by-leetcode-9w8au/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int main(){

    return 0;
}
/*
思路：设置一个计数器，‘（’+1，‘）’-1当计数器小于0的时候，可以删除前面的任意一个括号
最后的计数器应该为0
*/

/*
官方思路
背景知识
有效的「括号」：题目输入的字符串由一系列「左括号」和「右括号」组成，但是有一些额外的括号，使得括号不能正确配对。对于括号配对规则如果还不太清楚的读者，可以先完成问题「20. 有效的括号」。

可以一次遍历计算出多余的「左括号」和「右括号」：
根据括号匹配规则和根据求解「22. 括号生成」的经验，我们知道：如果当前遍历到的「左括号」的数目严格小于「右括号」的数目则表达式无效。因此，我们可以遍历一次输入字符串，统计「左括号」和「右括号」出现的次数。

当遍历到「左括号」的时候：
「左括号」数量加 11。
当遍历到「右括号」的时候：
如果此时「左括号」的数量不为 00，因为「右括号」可以与之前遍历到的「左括号」匹配，此时「左括号」出现的次数 -1−1；
如果此时「左括号」的数量为 00，「右括号」数量加 11。
通过这样的计数规则，得到的「左括号」和「右括号」的数量就是各自最少应该删除的数量。

方法一：回溯 + 剪枝
思路与算法

题目让我们删除括号使得剩下的括号匹配，要求我们删除最少的括号数，并且要求得到所有的结果。我们可以使用回溯算法，尝试遍历所有可能的去掉非法括号的方案。

首先我们利用括号匹配的规则求出该字符串 ss 中最少需要去掉的左括号的数目 \textit{lremove}lremove 和右括号的数目 \textit{rremove}rremove，然后我们尝试在原字符串 ss 中去掉 \textit{lremove}lremove 个左括号和 \textit{rremove}rremove 个右括号，然后检测剩余的字符串是否合法匹配，如果合法匹配则我们则认为该字符串为可能的结果，我们利用回溯算法来尝试搜索所有可能的去除括号的方案。

在进行回溯时可以利用以下的剪枝技巧来增加搜索的效率：

充分利用括号左右匹配的特点（性质），因此我们设置变量 \textit{lcount}lcount 和 \textit{rcount}rcount，分别表示在遍历的过程中已经用到的左括号的个数和右括号的个数，当出现 \textit{lcount} < \textit{rcount}lcount<rcount 时，则我们认为当前的字符串已经非法，停止本次搜索。
我们从字符串中每去掉一个括号，则更新 \textit{lremove}lremove 或者 \textit{rremove}rremove，当我们发现剩余未尝试的字符串的长度小于 \textit{lremove} + \textit{rremove}lremove+rremove 时，则停止本次搜索。
当 \textit{lremove}lremove 和 \textit{rremove}rremove 同时为 00 时，则我们检测当前的字符串是否合法匹配，如果合法匹配则我们将其记录下来。
由于记录的字符串可能存在重复，因此需要对重复的结果进行去重，去重的办法有如下两种：

利用哈希表对最终生成的字符串去重。
我们在每次进行搜索时，如果遇到连续相同的括号我们只需要搜索一次即可，比如当前遇到的字符串为 \texttt{"(((())"}"(((())"，去掉前四个左括号中的任意一个，生成的字符串是一样的，均为 \texttt{"((())"}"((())"，因此我们在尝试搜索时，只需去掉一个左括号进行下一轮搜索，不需要将前四个左括号都尝试一遍。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/shan-chu-wu-xiao-de-gua-hao-by-leetcode-9w8au/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/