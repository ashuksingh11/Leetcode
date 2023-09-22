//https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
           // Your code here
           Node* fast = head;
           Node* slow = head;
           while(n>0 && fast) {
               fast = fast->next;
               --n;
           }
           
           if(n>0) {
               return -1;
           }
           
           while(fast) {
               slow = slow->next;
               fast = fast->next;
           }
           
           return slow->data;
    }
};