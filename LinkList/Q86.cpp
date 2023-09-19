//https://leetcode.com/problems/partition-list/description/?envType=study-plan-v2&envId=top-interview-150
//86. Partition List


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // main intuition is to have before and after list 
        // which will have elements lesser or more than 
        // val x and then later join them

        ListNode before_dummy(0);
        ListNode *before = &before_dummy;
        ListNode after_dummy(0);
        ListNode *after = &after_dummy;

        while(head) {

            if(head->val < x) {
                before->next = head;
                before = before->next;
            }
            else {
                after->next = head;
                after = after->next;
            }

            head = head->next;
        }

        after->next = nullptr;

        before->next = after_dummy.next;

        return before_dummy.next;
    }
};