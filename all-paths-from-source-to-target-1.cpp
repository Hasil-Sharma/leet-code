// https://leetcode.com/problems/all-paths-from-source-to-target/description/

class Solution {
    
    typedef vector<vector<int>> vvi;
    typedef vector<int> vi;
    
public:
    void helper(vvi& graph, int curr_node, int last_node, vi& temp_path, vvi& answer){
        if (curr_node == last_node) answer.push_back(temp_path);
        else {
            for(int node: graph[curr_node]){
                temp_path.push_back(node);
                helper(graph, node, last_node, temp_path, answer);
                temp_path.pop_back();
            }
        }
    } 
    vvi allPathsSourceTarget(vvi& graph) {
        vvi answer;
        vi temp_path;
        int num_nodes = graph.size();
        
        temp_path.push_back(0);
        helper(graph, 0, num_nodes - 1, temp_path, answer);
        temp_path.pop_back();
        
        return answer;
    }
};
