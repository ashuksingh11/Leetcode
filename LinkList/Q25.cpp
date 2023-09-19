//25. Reverse Nodes in k-Group
//https://leetcode.com/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode* reverseList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(k>0) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* ktail = nullptr;

        ListNode* newhead = nullptr;

        while(curr != nullptr) {

            int count = 0;
            curr = head;

            while(count < k && curr) {
                curr = curr->next;
                count++;
            }

            if(count == k) {

                ListNode* revhead = reverseList(head, k);

                if(newhead == nullptr) {
                    newhead = revhead;
                }

                if(ktail) {
                    ktail->next = revhead;
                }

                ktail = head;
                head = curr;
            }
        }

        if(ktail) {
            ktail->next = head;
        }

        return newhead == nullptr ? head:newhead;
    }
};