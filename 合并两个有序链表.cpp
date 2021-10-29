/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head;
        head->next = l1->val<l2->val ? l1:l2;
        ListNode *ptr = head->next;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while(p1->next != nullptr && p2->next != nullptr){
            if (p1->val <= p2->val){
                ptr -> next = p1;
                ptr = ptr -> next;
                p1 = p1->next;
            }else{
                ptr -> next = p2;
                ptr = ptr -> next;
                p2 = p2->next;
            }
        }
        if(p1 -> next == nullptr){ptr -> next = p2;return head -> next;}
        if(p2 -> next == nullptr){ptr -> next = p1; return head -> next;}
    }
};

class Solution2 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        if (l1 == nullptr){
            return l2;
        }
        if (l2 == nullptr){
            return l1;
        }
        if (l1->val <= l2->val){
            l1 -> next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        if (l1 -> val > l2 -> val){
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
        
    }
};