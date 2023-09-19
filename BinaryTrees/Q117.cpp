//117. Populating Next Right Pointers in Each Node II


class Solution {
public:
    Node* connect(Node* root) {
        if(!root) {
            return root;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            Node* prev = nullptr;

            for(int i=0; i<size; i++) {
                Node* temp = q.front();
                q.pop();
                if(prev == nullptr) {
                    prev = temp;
                }
                else {
                    prev->next = temp;
                    prev = temp;
                }

                if(temp->left) {
                    q.push(temp->left);
                }

                if(temp->right) {
                    q.push(temp->right);
                }
            }
        }

        return root;
    }
};