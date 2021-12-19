/*
LeetCode 160 相交链表
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
*/
#include <iostream>
#include <unordered_set>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 哈希表遍历法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> setA;
        while (headA != nullptr){
            setA.insert(headA);
            headA = headA -> next;
        }
        while (headB != nullptr)
        {
            if (setA.find(headB) == setA.end()){headB = headB->next;}
            else return headB;
        }
        return nullptr;
    }
};

// 双指针法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};
