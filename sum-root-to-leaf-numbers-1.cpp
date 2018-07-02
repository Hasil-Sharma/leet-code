// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    vector<int> answer;
    vector<int> temp;
    
    int sumNumbers(TreeNode* root) {
        helper(root);
        int ans = 0;
        for(int i = 0; i < answer.size(); i++){
            ans = ans * 10 + answer[i];
        }
        
        return ans;
    }
    
    void helper(TreeNode* root){
        if(!root) return;

        temp.push_back(root->val);
        
        if (root->left)
            helper(root->left);
        if (root->right)
            helper(root->right);
        else if (!root->left){
            // sum the current with prev;
            int i = temp.size() - 1, j = answer.size() - 1, carry = 0;
            
            while(i >= 0 && j >= 0){
                answer[j] += temp[i] + carry;
                carry = answer[j] / 10;
                answer[j] %= 10;
                i--;
                j--;
            }
            
            while(i >= 0){
                answer.insert(answer.begin(), temp[i] + carry);
                carry = answer[0] / 10;
                answer[0] %= 10;
                i--;
            }
            
            while(j >= 0){
                answer[j] += carry;
                carry = answer[j] / 10;
                answer[j] %= 10;
                j--;
            }
            
            if(carry) answer.insert(answer.begin(), carry);
        }
        
        temp.pop_back();
        
    }
};
