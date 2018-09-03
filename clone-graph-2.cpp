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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        
        unordered_map<int, UndirectedGraphNode*> mp;
        queue<UndirectedGraphNode*> q;
        
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        q.push(node);
        mp[node->label] = newNode;
        
        while(!q.empty()){
            node = q.front();
            q.pop();
            for(auto nn : node->neighbors){
                if (!mp.count(nn->label)){
                    q.push(nn);
                    mp[nn->label] = new UndirectedGraphNode(nn->label);
                }
                mp[node->label]->neighbors.push_back(mp[nn->label]);
            }
        }
        
        return newNode;
    }
};
