// https://leetcode.com/problems/path-sum-iii/description/
class Solution {
public:
    void helper(TreeNode* root, vector<int>& sum_vector, int &answer, int sum){
        if (root == NULL) return;
        else if (!(root->left || root->right)) {
            answer += (root->val == sum) ? 1 : 0;
            sum_vector.push_back(root->val); // leaf nodes
            return;
        }
        
        int index = sum_vector.size() - 1; // after this index we need to increment
        helper(root->left, sum_vector, answer, sum);
        helper(root->right, sum_vector, answer, sum);
        
        for(int i = index + 1; i < sum_vector.size(); i++){
            sum_vector[i] += root->val;
            answer += (sum_vector[i] == sum) ? 1 : 0;
        }
        
        sum_vector.push_back(root->val);
        answer = answer + ((sum_vector.back() == sum) ? 1 : 0);
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        int answer = 0;
        vector<int> sum_vector;
        helper(root, sum_vector, answer, sum);

        return answer;
    }
};
