//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode * node;
    
    int getSize(ListNode* head){
        int size = 0;
        while(head){
            head = head->next;
            size++;
        }
        return size;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int size = getSize(head);
        TreeNode * ans;
        
        if (size == 0) 
            return NULL;
        
        node = head;
        ans = helper(0, size);
        
        return ans;
    }
    
    TreeNode* helper(int start, int end){
        if (start >= end)
            return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *ans = new TreeNode(0);
        
        ans->left = helper(start, mid);
        ans->val = node->val;
        node = node->next;
        
        ans->right = helper(mid + 1, end);
        
        return ans;
    }
};
