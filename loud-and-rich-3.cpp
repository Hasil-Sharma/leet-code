// https://leetcode.com/problems/loud-and-rich/description/

class Solution {
public:
    typedef vector<vector<int>> vvi;
    typedef vector<int> vi;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int N = quiet.size();
        vi answer(N, -1);
        vvi adjList(N, vector<int>());
        
        for(vi edge : richer)
            adjList[edge[1]].push_back(edge[0]);
            
        
        stack<int> stk;
        
        for(int p = 0; p < N; p++){
            if (answer[p] == -1){
                stk.push(p);
                
                while(!stk.empty()){
                    int n = stk.top();
                    if (answer[n] == -1){
                        answer[n] = n;
                        for(int child : adjList[n])
                            stk.push(child);
                        
                    } else{
                        stk.pop();
                        for(int child : adjList[n])
                            answer[n] = quiet[answer[n]] > quiet[answer[child]] ? answer[child] : answer[n];
                    }
                    
                }
            }
        }
        
        return answer;
    }
};
