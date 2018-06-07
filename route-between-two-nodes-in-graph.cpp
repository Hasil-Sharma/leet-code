// https://lintcode.com/problem/route-between-two-nodes-in-graph/description

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        unordered_map<DirectedGraphNode*, bool> visited;
        queue<DirectedGraphNode*> q;
        DirectedGraphNode* front;
        q.push(s);
        
        while(!q.empty()){
            front = q.front();
            q.pop();
            if (visited[front]) continue;
            else {
                visited[front] = true;
                for(DirectedGraphNode* node : front->neighbors)
                    q.push(node);
            }
        }
        
        return visited[t];
    }
};
