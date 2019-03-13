// https://leetcode.com/problems/print-binary-tree/description/

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
    vector<vector<string>> printTree(TreeNode* root) {
        int m = getHeight(root), n = (1 << m) - 1;
        vector<vector<string>> answer(m , vector<string>(n , ""));
        unordered_map<int, int> nodeSeenAtLevel;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        

        while(nodeSeenAtLevel[m] <= (1 << (m - 1))){
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int h = front.second;
            
            if (!node) {
                nodeSeenAtLevel[h] = nodeSeenAtLevel[h] + 1;
                q.push({NULL, h + 1});
                q.push({NULL, h + 1});
                continue;
            }
            
            int startIndex = (1 << (m - h - 1)) - 1;
            int spaceToLeave = h == 0 ? 0 : (1 << (m - h)) - 1;
            int insertAtIndex = startIndex + spaceToLeave * nodeSeenAtLevel[h] + nodeSeenAtLevel[h];
            nodeSeenAtLevel[h] = nodeSeenAtLevel[h] + 1;
            answer[h][insertAtIndex] = to_string(node->val);
            q.push({node->left, h + 1});
            q.push({node->right, h + 1});
        }
        
        return answer;
    }
    
    int getHeight(TreeNode* root){
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};
