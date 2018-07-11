// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define mp(A, B) make_pair(A, B)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> dqueue;
        bool flag = true;
        vvi answer;
        if(root)
        dqueue.push(root);
        
        while(!dqueue.empty()){
            int size = dqueue.size();
            vi temp(size);
            for(int i = 0; i < size; i++){
                root = dqueue.front();
                dqueue.pop();
                
                if (flag) temp[i] = root->val;
                else temp[size - i - 1] = root->val;
                
                if(root->left)
                    dqueue.push(root->left);
                if(root->right)
                    dqueue.push(root->right);
                
            }
            answer.push_back(temp);
            flag = (!flag);
        }
        
        return answer;
    }
};
