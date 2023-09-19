//116. Populating Next Right Pointers in Each Node
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) {
            return root;
        }

        // Start with the root node. There are no next pointers
        // that need to be set up on the first level
        Node* leftmost = root;

        // Once we reach the final level, we are done
        while(leftmost->left != nullptr) {

            // Iterate the "linked list" starting from the head
            // node and using the next pointers, establish the 
            // corresponding links for the next level
            Node* head = leftmost;

            while(head != nullptr) {
                //connection 1
                head->left->next = head->right;

                //connection 2 
                if(head->next != nullptr) {
                    head->right->next = head->next->left;
                }

                //progress along list (node on same level)
                head = head->next;
            }

            //go to next level
            leftmost = leftmost->left;
        }

        return root;
        
    }
};
