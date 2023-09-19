//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150
//Remove Duplicates from Sorted List II

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

class Solution {
public:
// we need to delete all duplicate node 
ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *previous = &dummy, *current = head;
        
        while(current) {
            ListNode *next_node = current->next;
            while(next_node && current->val == next_node->val) {
                ListNode *temp = next_node->next;
                delete next_node;
                next_node = temp;
            }
            
            if(current->next == next_node) {
                previous = current;
            } else {
                previous->next = next_node;
                delete current;
            }
            current =  next_node;
        }
        
        return dummy.next;
    }
};