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
    stack<TreeNode*> fwd, bkw;
    
    bool hasNext(){
        return fwd.size() != 0;
    }
    
    void initFwd(TreeNode* root){
        while(root){
            fwd.push(root);
            root = root->left;
        }
    }
    
    TreeNode* getNext(){
        if (!hasNext()) return NULL;
        TreeNode* top = fwd.top();
        fwd.pop();
        initFwd(top->right);
        return top;
    }
    
    bool hasPrev(){
        return bkw.size() != 0;
    }
    
    void initBkw(TreeNode* root){
        while(root){
            bkw.push(root);
            root = root->right;
        }
    }
    
    TreeNode* getPrev(){
        if (!hasPrev()) return NULL;
        TreeNode* top = bkw.top();
        bkw.pop();
        initBkw(top->left);
        return top;
    }
    
    bool findTarget(TreeNode* root, int k) {
        fwd = stack<TreeNode*>();
        bkw = stack<TreeNode*>();
        initFwd(root);
        initBkw(root);
        
        auto prev = getPrev(), next = getNext();
        while(prev && next && (prev->val > next->val)){
            int s =  prev->val + next->val;
            if (s == k) return true;
            else if (s > k) prev = getPrev();
            else next = getNext();
        }
        return false;
    }
};
