//https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
    if(head == nullptr) {
        return head;
    }
    
    Node* curr = head;
    Node* fwd;
    
    while(curr->next) {
        if(curr->data == curr->next->data) {
            fwd = curr->next->next;
            delete curr->next;
            curr->next = fwd;
        }
        else {
            curr = curr->next;
        }
    }
    
    return head;
}