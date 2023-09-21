//https://www.geeksforgeeks.org/find-length-of-loop-in-linked-list/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node* fast=head;
    Node* slow=head;
    int count = 0;
    
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow) {
            count =1;
            Node* temp = slow;
            while(temp->next != slow) {
                count++;
                temp = temp->next;
            }
            break;
        }
    }