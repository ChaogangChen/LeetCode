/*
LeetCode 19 删除链表的倒数第N个结点
https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
*/

/*
 * Definition for singly-linked list.
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//这个解法使用了遍历算出了整个链表的长度，如果使用双指针会让解题更方便
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) return nullptr;
        vector<ListNode*> vec;
        ListNode *tmp = head;
        while(tmp != nullptr){
            vec.push_back(tmp);
            tmp = tmp->next;
        }
        if (n == 1) {vec[vec.size()-2]->next = nullptr;}
        else if(n == vec.size()){return vec[1];}
        else {
            vec[vec.size()-n-1]->next = vec[vec.size()-n+1];
        }
        return head;
    }
};