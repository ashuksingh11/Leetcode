//24. Swap Nodes in Pairs
//https://leetcode.com/problems/swap-nodes-in-pairs/description/

//recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* firstnode = head;
        ListNode* secondnode = head->next;
        
        //swap
        firstnode->next = swapPairs(secondnode->next);
        secondnode->next = firstnode;
        
        //new head will be secondnode
        return secondnode;
    }
};