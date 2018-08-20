// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/

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
    Node* treeToDoublyList(Node* root) {
        stack<Node*> stk;
        Node *head = NULL, *prev = NULL;
        if (!root) return NULL;
        
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            stk.pop();
            
            if (!head) head = root;
            if (prev){
                root->left = prev;
                prev->right = root;
            }
            prev = root;
            root = root->right;
        }
        
        root = head;
        prev->right = root;
        root->left = prev;
        
        return head;
    }
};
