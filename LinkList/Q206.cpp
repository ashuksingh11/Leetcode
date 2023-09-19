//https://leetcode.com/problems/reverse-linked-list/description/
//206. Reverse Linked List

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev=nullptr, *third;

        while(curr) {
            third = curr->next;
            curr->next = prev;
            prev = curr;
            curr = third;
        }

        return prev;
    }
};

//recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};