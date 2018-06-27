// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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
    
    struct RecBlock {
        int start;
        int end;
        TreeNode** node;
        RecBlock(int x, int y, TreeNode** z) : start(x), end(y), node(z) {}
    };
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        if (nums.size() == 0) return root;
        
        stack<RecBlock*> stk;
        RecBlock* rec = new RecBlock(0, nums.size() - 1, &root);
        stk.push(rec);
        
        while(!stk.empty()){
            rec = stk.top();
            stk.pop();
            if (rec->start > rec->end)
                continue;
            
            int mid = rec->start + (rec->end - rec->start) / 2;
            TreeNode* temp = new TreeNode(nums[mid]);
            *(rec->node) = temp;
            stk.push(new RecBlock(rec->start, mid - 1, &temp->left));
            stk.push(new RecBlock(mid + 1, rec->end, &temp->right));
        }
        
        return root;
    }
};
