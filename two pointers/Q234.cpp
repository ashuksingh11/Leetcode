///https://leetcode.com/problems/palindrome-linked-list/description/
//234. Palindrome Linked List

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head, *fast=head;

        if(head == NULL || head->next == NULL){
            return (head);
        }

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse next half in case we odd number of node then move slow one ptr ahead
        if(fast != nullptr && fast->next == nullptr) {
            slow = slow->next;
        }

        //reverse
        ListNode* prev =nullptr;
        ListNode* next = slow;
        while(slow != nullptr && slow->next != nullptr) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        //move ahead slow if there was 2 nodes to reverse
        if(slow != NULL){
            slow->next = prev;
        }        

        //4_) Compare the start half and end half if found any inequality then return false otherwise return true.
        fast = head;
        while(slow && fast){
            if(slow->val != fast->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }

        return true;        
    }
};