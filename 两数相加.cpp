/*
https://leetcode-cn.com/problems/add-two-numbers/
*/


// Definition for singly-linked list.
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
解 1：
i = l1->val
j = l2->val
new ListNode* res_return 这个用于返回链表头
res = res_return
flag = 1 定义一个判断是否结束的标志
tmp = 0 定义一个进位标志
while flag == 1
    if i & j 都有值
        res->val = (i->val + j->val + tmp) % 10
        if i->val + j->val + tmp >= 10
            tmp = 1
        else
            tmp = 0
    elseif !i & j 一个有值
        res->val = (j->val+tmp)%10
        if j->val + tmp >= 10
            tmp = 1
        else
            tmp = 0
    elseif i & !j 一个有值
        res->val = (i->val+tmp)%10
        if i->val + tmp >= 10
            tmp = 1
        else
            tmp = 0
    else 
        res->val = tmp
        flag=0 无值
    if i->next | j->next | tmp
        new ListNode* tmpNode
        res->next = tmpNode
        res = tmpNode
        
    ！！！！
    缺乏迭代模块
    
    if(NULL!=l1)l1=l1->next;
    if(NULL!=l2)l2=l2->next;
    ！！！！

*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res_return = new ListNode ;
        ListNode* res = res_return;
        int flag = 1;
        int tmp = 0;
        while (flag == 1)
        {
            if (NULL != l1 && NULL != l2)
            {
                res->val = (l1->val + l2->val + tmp)%10;
                if(l1->val + l2->val + tmp >= 10) tmp = 1; else tmp = 0;
            }else if (NULL==l1 && NULL!=l2)
            {
                res->val = (l2->val+tmp)%10;
                if (l2->val + tmp >= 10)tmp = 1;else tmp = 0;
            }else if (NULL!=l1 && NULL==l2)
            {
                res->val = (l1->val+tmp)%10;
                if (l1->val + tmp >= 10)tmp = 1;else tmp = 0;
            }else{
                res->val = tmp;
                tmp = 0;
            }
            if(NULL!=l1)l1=l1->next;
            if(NULL!=l2)l2=l2->next;
            if(NULL!=l1 || NULL!=l2 || tmp){
                ListNode* tmpNode = new ListNode;
                res->next = tmpNode;
                res = tmpNode;
            }else{
                flag = 0;
            }
        }
        return res_return;
    }
};