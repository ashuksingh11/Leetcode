//https://leetcode.com/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150
//61. Rotate List
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //main trick is to make it circular and travel len-k
        if (!head || !head->next || !k) {
            return head;
        }

        int len=1;
        ListNode* curr = head;
        while(curr->next) {
            len++;
            curr = curr->next;
        }

        //make circular
        curr->next = head;
        // we need to traverse len-k from start
        k = k%len;
        k=len-k;

        while(k) {
            curr = curr->next;
            --k;
        }

        head = curr->next;
        curr->next = nullptr;

        return head;

    }
};