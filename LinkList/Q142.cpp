//142. Linked List Cycle II
//https://leetcode.com/problems/linked-list-cycle-ii/description/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head, *slow=head, *newslow=head;
        if(!head || !head->next) {
            return nullptr;
        }
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                break;
            }
        }
        
        if(slow != fast) {
            return nullptr;
        }
        
        while(newslow != slow) {
            slow = slow->next;
            newslow = newslow->next;
        }
        
        return newslow;
        
    }
};  