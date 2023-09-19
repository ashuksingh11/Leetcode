//https://leetcode.com/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-interview-150
//141. Linked List Cycle

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast=head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if(slow==fast) {
                return true;
            }
        }

        return false;
    }
};