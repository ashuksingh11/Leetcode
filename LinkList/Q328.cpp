//328. Odd Even Linked List
//https://leetcode.com/problems/odd-even-linked-list/description/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) {
            return nullptr;
        }

        ListNode* odd = head, *even=head->next, *evenHead = even;

        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};