// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    stack<TreeNode*> prev, next;
    
    void init(TreeNode* root){
        moveLeft(root);
        moveRight(root);
    }
    
    void moveLeft(TreeNode* root){
        while(root){
            next.push(root);
            root = root->left;
        }
    }
    
    void moveRight(TreeNode* root){
        while(root){
            prev.push(root);
            root = root->right;
        }
    }
    
    bool hasPrev(){
        return !prev.empty();
    }
    
    bool hasNext(){
        return !next.empty();
    }
    
    int getPrev(){
        auto top = prev.top();
        prev.pop();
        
        moveRight(top->left);
        return top->val;
    }
    
    
    int getNext(){
        auto top = next.top();
        next.pop();
        moveLeft(top->right);
        return top->val;
    }
    
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        init(root);
        int small = getNext(), large = getPrev();
        while(hasNext() && hasPrev()){
            if (small == large) break;
            else if (small + large == k) return true;
            else if (small + large > k) large = getPrev();
            else small = getNext();
        }
        return false;
    }
};
