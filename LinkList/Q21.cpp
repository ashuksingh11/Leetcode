//https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150
//21. Merge Two Sorted Lists

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newhead = nullptr;
        ListNode* curr = nullptr;

        if(!l1) {
            return l2;
        }
        if(!l2) {
            return l1;
        }

        if(l1->val < l2->val){
            newhead = l1;
            l1 = l1->next;
        }
        else {
            newhead = l2;
            l2 = l2->next;
        }
        curr = newhead;

        while(l1 != nullptr && l2!= nullptr) {
            int v1 = l1->val;
            int v2 = l2->val;

            if(v1 < v2) {
                curr->next = l1;
                l1=l1->next;
            }
            else {
                curr->next = l2;
                l2=l2->next;
            }

            curr  =curr->next;

        }

        if(!l1) {
            curr->next = l2;
        }
        else {
            curr->next = l1;
        }

        return newhead;
    }
};


//recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        }
        else if(list2 == nullptr) {
            return list1;
        } 
        else if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};