#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int listNodeLength(ListNode* root){
        int count = 0;
        
        while(root){
            root = root->next;
            count++;
        }
        return count;        
    }
    ListNode* listNodeSplit(ListNode* root, int n){
        if (n == 0) return NULL;
        for(int i = 0; i < n - 1; i++)
            root = root->next;
        return root;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        
        int ll_size, size[k], temp;
        vector<ListNode*> answer;
        ListNode *listNode;
        
        memset(size, 0, k * sizeof(int));
        ll_size = this->listNodeLength(root);
        
        for(int i = 0; i < ll_size; i++) size[i % k]++;
        
        for(int i = 0; i < k; i++){
            
            temp = size[i];
            answer.push_back(root);
            listNode = this->listNodeSplit(root, temp);
            if (listNode){
                root = listNode->next;
                listNode->next = NULL;
            } else root = NULL;
        }
        return answer;
    }
};
