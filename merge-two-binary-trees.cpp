// https://leetcode.com/problems/merge-two-binary-trees/description/

class Solution {
public:

    void helper(TreeNode* t1, TreeNode* t2, TreeNode** tanswer){
        if (!(t1 || t2)) 
            return;
        *tanswer = new TreeNode((t1 ? t1->val : 0) + (t2 ? t2->val : 0));
        helper((t1 ? t1->left : NULL), (t2 ? t2->left : NULL), &((*tanswer)->left));
        helper((t1 ? t1->right : NULL), (t2 ? t2->right : NULL), &((*tanswer)->right));
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* tanswer = NULL;
        helper(t1, t2, &tanswer);
        return tanswer;
    }
};
