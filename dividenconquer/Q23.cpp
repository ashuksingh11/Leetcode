//https://leetcode.com/problems/merge-k-sorted-lists/description
//23. Merge k Sorted Lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0) {
            return nullptr;
        }

        return mergeHelper(lists, 0, lists.size()-1);
    }

    ListNode* mergeHelper(vector<ListNode*>& lists, int left, int right) {
        if(left >= right) {
            return lists[left];
        }

        int mid = left + (right-left)/2;
        ListNode* l1 = mergeHelper(lists, left, mid);
        ListNode* l2 = mergeHelper(lists, mid+1, right);

        return mergeList(l1,l2);
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = l1?l1:l2;
        return dummy.next;
    }
};