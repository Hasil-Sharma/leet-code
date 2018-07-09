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
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visited;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        initAdj(root);
        vector<int> answer;
        queue<pair<int, int>> q;
        q.push({target->val, 0});
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            if (visited.count(p.first)) continue;
            if (p.second == K) answer.push_back(p.first);
            else if (p.second == K + 1) break;
            visited.insert(p.first);
            for(int child : adjList[p.first]){
                q.push({child, p.second + 1});
            }
        }
        
        return answer;
    }
    
    void initAdj(TreeNode* root){
        if(!root) return;
        int s = root->val, d;
        if (!adjList.count(s)) adjList[s] = vector<int>();
        
        if (root->left) 
            addEdge(s, root->left->val);
        
        if (root->right)
            addEdge(s, root->right->val);
        
        initAdj(root->left);
        initAdj(root->right);
    }
    
    void addEdge(int s, int d){
        if (!adjList.count(d)) adjList[d] = vector<int>();
        adjList[s].push_back(d);
        adjList[d].push_back(s);
    }
};
