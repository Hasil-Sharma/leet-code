// // https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *prev, *head;
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        
        head = prev = NULL;
        helper(root);
        
        head->left = prev;
        prev->right = head;
        
        return head;
    }
    
    void helper(Node* root){
        if (!root) return;
        helper(root->left);
        
        if (prev) {
            prev->right = root;
            root->left = prev;
        } else {
            head = prev = root;
        }
        prev = root;
        helper(root->right);
    }
};
