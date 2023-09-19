//426. Convert Binary Search Tree to Sorted Doubly Linked List
//https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* first;
    Node* last;

    void helper(Node* node) {
        if(node == nullptr) {
            return;
        }

        helper(node->left);
        if(last) {
            last->right = node;
            node->left = last;
        }
        else {
            first = node;
        }
        last = node;

        helper(node->right);

    }

    Node* treeToDoublyList(Node* root) {
        first = nullptr;
        last = nullptr;

        if(!root) {
            return root;
        }

        helper(root);
        last->right = first;
        first->left = last;

        return first;
    }
};