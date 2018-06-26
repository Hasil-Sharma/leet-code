// https://leetcode.com/problems/construct-string-from-binary-tree/submissions/1

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
        
        stack<TreeNode*> stk;
        unordered_map<TreeNode*, int> visited;
        

        ans << t->val;
        
        if (t->right) stk.push(t->right);
        if (t->left) stk.push(t->left);
        else if (t->right)
            ans << "()";
        
        while(!stk.empty()){
            t = stk.top();
            if (visited.count(t)){
                stk.pop();
                ans << ")";
            } else {
                ans << "(" ;
                ans << t->val;
                if (t->right) stk.push(t->right);
                
                if (t->left) stk.push(t->left);
                else if (t->right) ans << "()";
                    
                visited[t] = 1;
            }
        }
        
        string answer = ans.str();
        return answer;
    }
    
};
