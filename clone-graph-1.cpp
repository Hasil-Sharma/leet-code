// https://leetcode.com/problems/clone-graph/description/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<int, UndirectedGraphNode*> pointer;
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        if (pointer.count(node->label)){
            return pointer[node->label];
        }
        UndirectedGraphNode * root = new UndirectedGraphNode(node->label);
        pointer[node->label] = root;
        for(auto child : node->neighbors){
            UndirectedGraphNode* neighbor = cloneGraph(child);
            root->neighbors.push_back(neighbor);
        }
        
        return root;
    }
};
