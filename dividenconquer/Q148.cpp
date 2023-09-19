//https://leetcode.com/problems/sort-list/description
//148. Sort List

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(list1 && list2) {
            if(list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }
        if(list1) {
            curr->next = list1;
        }
        else {
            curr->next = list2;
        }

        return dummy.next;
    }

    ListNode* getMid(ListNode* head) {
        ListNode* midprev = nullptr;
        while(head && head->next) {
            midprev = (midprev == nullptr)?head:midprev->next;
            head = head->next->next;
        }

        ListNode* mid = midprev->next;
        midprev->next = nullptr;
        return mid;
    }
};