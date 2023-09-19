//https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150
//2. Add Two Numbers
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode();
        ListNode* tail = dummyhead;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry!=0) {
            int d1 = (l1!=nullptr)?l1->val : 0;
            int d2 = (l2!=nullptr)?l2->val : 0;

            int sum = d1+d2+carry;
            int digit = sum%10;
            carry = sum/10;

            ListNode* newnode = new ListNode(digit);
            tail->next = newnode;
            tail = tail->next;

            l1 = (l1!=nullptr)?l1->next : 0;
            l2 = (l2!=nullptr)?l2->next : 0;
        }

        ListNode* result = dummyhead->next;
        delete dummyhead;
        return result;
    }
};