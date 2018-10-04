// https://leetcode.com/problems/clone-graph/discuss/

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
        if (!node) return NULL;
        unordered_map<int, UndirectedGraphNode*> ump;
        UndirectedGraphNode* root;
        queue<UndirectedGraphNode*> qq;
        
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        ump[node->label] = newNode;
        qq.push(node);
        
        while(!qq.empty()){
            node = qq.front();
            qq.pop();
            if (!ump.count(node->label)) {
                ump[node->label] = new UndirectedGraphNode(node->label);
            }
            
            for(auto child: node->neighbors){
                if (!ump.count(child->label)){
                    ump[child->label] =  new UndirectedGraphNode(child->label);
                    qq.push(child);
                }
                ump[node->label]->neighbors.push_back(ump[child->label]);
            }
        }
        
        return newNode;
    }
};
