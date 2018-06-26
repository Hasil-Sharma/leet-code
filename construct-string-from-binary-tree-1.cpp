// https://leetcode.com/problems/construct-string-from-binary-tree/description/

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
    string tree2str(TreeNode* t) {
        stringstream ans;
        if (!t) return ans.str();
        
        helper(t, ans);
        auto answer = ans.str();
        answer.erase(0, 1);
        answer.erase(answer.length() - 1);
        return answer;
    }
    
    void helper(TreeNode* t, stringstream& s){
        if (!t) 
            return;
        s << "(" + to_string(t->val);
        if (t->left) helper(t->left, s);
        else if (t->right)
            s << "()";
        helper(t->right, s);
        s << ")";
    }
};
