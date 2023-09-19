//https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150
//92. Reverse Linked List II

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

class Solution {
public:
    // 1->2->3->4->5 L=2,R=4
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left==right) {
            return head;
        }

        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;

        ListNode *dummytemp = dummyhead, *curr=nullptr, *prev=nullptr, *fwd=nullptr, *start=nullptr;

        // dummytemp traverse till just before start (i.e. 1)
        for(int i=0; i<left-1;i++) {
            dummytemp = dummytemp->next;
        }

        // save start and point curr to start i.e. 2 , start->2, dummytemp->1
        start = curr = dummytemp->next;

        //normal list reversal traverse till curr,fwd point to next elemeent
        // at end reversal i.e. 5 (since 2,3,4 need to be reversed)
        for(int i=left; i<=right; i++) {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }

        //at end we have list like 1->2->null (4->3->2) 5->null 
        // prev->4 , c,f->5 , now 1->4  and 2->5 needs to be done
        start->next = curr;
        dummytemp->next = prev;

        ListNode* res = dummyhead->next;
        delete dummyhead;
        return res;

    }
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head) {
            return nullptr;
        }

        ListNode* curr = head, *prev = nullptr;
        while(left > 1) {
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }

        // two pointers that will fix final connections
        ListNode *con = prev, *tail = curr;
        
        //reverse iteratively
        ListNode* third = nullptr;
        while(right > 0) {
            third = curr->next;
            curr->next = prev;
            prev = curr;
            curr = third;
            right--;
        }

        //make final connections
        if(con) {
            con->next = prev;
        }
        else {
            head = prev;
        }

        tail->next = curr;

        return head;

    }
};





//========another solution
//https://leetcode.com/problems/reverse-linked-list-ii/solutions/2311084/java-c-tried-to-explain-every-step/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0); // created dummy node
        dummy->next = head;
        ListNode *prev = dummy; // intialising prev pointer on dummy node
        
        for(int i = 0; i < left - 1; i++)
            prev = prev->next; // adjusting the prev pointer on it's actual index
        
        ListNode *curr = prev->next; // curr pointer will be just after prev
        // reversing
        for(int i = 0; i < right - left; i++){
            ListNode *forw = curr->next; // forw pointer will be after curr
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }
        return dummy->next;
    }
};