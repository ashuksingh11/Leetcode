//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-interview-150
//19. Remove Nth Node From End of List
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head, *slow=head;

        for(int i=0; i<n; i++) {
            fast = fast->next;
        }

        // if we reach end of list that means n-th node from last 
        // is first head node
        ListNode* temp;
        if(fast == nullptr) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // since we want to reach one node earlier than node to delete
        // just check fast.next is null or not
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        //delete
        temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};