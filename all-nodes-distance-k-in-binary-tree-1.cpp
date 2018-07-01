// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

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
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> answer;
        queue <TreeNode*> q;
        
        findPath(root, target, q);
        
        int i = 0;
        TreeNode *lastNode = q.front();
        unordered_map<TreeNode*, int> nodeDist;
        while(!q.empty()){
            if (K - i < 0) break;
            nodeDist.clear();
            auto top = q.front();
            q.pop();
            if (top == lastNode) 
                distFromNode(top, 0, nodeDist);
            else if (top->left == lastNode) {
                auto temp = top->left;
                top->left = NULL;
                distFromNode(top, 0, nodeDist);
                top->left = temp;
            }
            else if (top->right == lastNode) {
                auto temp = top->right;
                top->right = NULL;
                distFromNode(top, 0, nodeDist);
                top->right = temp;
            }
            
            for(auto itr = nodeDist.begin(); itr != nodeDist.end(); itr++){
                if (itr->second == K - i){
                    answer.push_back(itr->first->val);
                }
            }
            
            lastNode = top;
            i++;
            
        }
        return answer;
        
    }
    
    void distFromNode(TreeNode* root, int dist, unordered_map<TreeNode*, int> &nodeDist){
        if (!root) return;
        nodeDist[root] = dist;
        distFromNode(root->left, dist + 1, nodeDist);
        distFromNode(root->right, dist + 1, nodeDist);
    }
    
    bool findPath(TreeNode* root, TreeNode* target, queue<TreeNode*>& q){
        if(!root) return false;
        else if (root == target) {
            q.push(root);
            return true;
        }
        bool b1 = findPath(root->right, target, q);
        bool b2 = findPath(root->left, target, q);
        if (b1 || b2) q.push(root);
        return (b1 || b2);
    }
};
