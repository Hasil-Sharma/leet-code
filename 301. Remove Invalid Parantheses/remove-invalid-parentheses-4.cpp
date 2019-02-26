class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        unordered_set<string> seen;
        bool found = false;
        
        q.push(s);
        seen.insert(s);
        
        while(!q.empty() && !found){
            string front = q.front();
            q.pop();
            if (isvalid(front)){
                found = true;
                ans.push_back(front);
            } else {
                for(int i = 0; i < front.length(); i++){
                    if (i > 0 && front[i] == front[i-1]) continue;
                    else if (front[i] != '(' && front[i] != ')') continue;
                    string temp = (i > 0 ? front.substr(0, i) : "") + (i + 1 < front.length() ? front.substr(i+1) : "");
                    if (seen.count(temp)) continue;
                    seen.insert(temp);
                    q.push(temp);
                }
            }
        }
        
        while(!q.empty()){
            string front = q.front();
            q.pop();
            if (isvalid(front)) ans.push_back(front);
        }
        
        return ans;
    }
    
    bool isvalid(string& front){
        int cc = 0;
        for(char c : front){
            if (c != '(' && c != ')') continue;
            if (cc < 0) break;
            cc += (c == '(' ? 1 : -1);
        }
        
        return cc == 0;
    }
};
