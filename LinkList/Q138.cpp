//https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-interview-150
//138. Copy List with Random Pointer

// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

// trick is to use map which stores orig node addr (key) and copy node addr (value)
// use this map to copy next and random pointers

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

       
        Node* curr = head;

        while(curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};