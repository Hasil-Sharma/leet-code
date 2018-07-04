// https://leetcode.com/problems/delete-node-in-a-bst/description/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* prev = NULL, *current = root, *successor = NULL, *predecessor = NULL;
        while(current){
            if (current->val == key) break;
            prev = current;
            if (current->val > key) current = current->left;
            else current = current->right;
        }
        
        if(!current || (current->val != key)) 
            return root;
        
        // find the inorder successor
        while(current->right){
            prev = current;
            successor = current->right;
            while(successor->left){
                prev = successor;
                successor = successor->left;
            }
            swap(successor->val, current->val);
            current = successor;
        }
        
        // find the inorder predecessor
        while(current->left){
            prev = current;
            predecessor = current->left;
            while(predecessor->right){
                prev = predecessor;
                predecessor = predecessor->right;
            }
            swap(predecessor->val, current->val);
            current = predecessor;
        }
        
        if(prev == NULL){
            // no pred or succ of the current node thus remove the current node itself
            return NULL;
        } else if (prev->left == current){
            prev->left = NULL;
        } else {
            prev->right = NULL;
        }
        return root;
    }
};
