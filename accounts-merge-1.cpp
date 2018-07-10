// https://leetcode.com/problems/accounts-merge/description/

class Solution {
public:

    typedef pair<int, int> pii;
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    typedef vector<pair<int, int>> vpii;
    typedef vector<bool> vb;
    typedef vector<vector<bool>> vvb;
    typedef vector<string> vs;
    typedef vector<vector<string>> vvs;
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        vvs answer;
        set<string> emails;
        vb merged(accounts.size(), false);
        
        // sorting all the email to get ordinal indexes
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                emails.insert(accounts[i][j]);
            }
        } // O(|S|log|account[i]|) time and O(|S|) space
        
        unordered_map<string, int> emailToInt; // saves on comparsion
        unordered_map<int, string> intToEmail;
        int idx = 0;
        
        // converting emails to int and backmapping to recover emails
        for(auto email : emails){
            emailToInt[email] = idx;
            intToEmail[idx++] = email;
        } // 
        
        // converting accounts as ordered set of emails
        vector<set<int>> accountWithEmailIndex(accounts.size(), set<int>());
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                accountWithEmailIndex[i].insert(emailToInt[accounts[i][j]]);
            }
        }
        
        // iterating over all the emails and finding mapping of email to all accounts that it links
        unordered_map<int, vector<int>> edges;
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                int emailIdx = emailToInt[accounts[i][j]];
                if (!edges.count(emailIdx)) edges[emailIdx] = vi();
                edges[emailIdx].push_back(i);
            }
        }
        
        // generating account linkage from the edges, all the accounts linked with one email address are connected
        unordered_map<int, unordered_set<int>> adjList; 
        // us to handle the case of duplicate edge (two accounts can have more then one common)
        // stores how all the accounts are connected
        for(auto keyVal : edges){
            vi nodes = keyVal.second;
            for(int i = 1; i < nodes.size(); i++){
                int u = nodes[i-1], v = nodes[i];
                if(!adjList.count(u)) adjList[u] = unordered_set<int>();
                adjList[u].insert(v);
                if (!adjList.count(v)) adjList[v] = unordered_set<int>();
                adjList[v].insert(u);
                // to handle case when back dependency is made later
            }
        }
        
        // looping over all the accounts and merging
        for(int i = 0; i < accounts.size(); i++){
            if (merged[i]) continue; // skip the already merged accounts
            auto init = set<int>(accountWithEmailIndex[i].begin(), accountWithEmailIndex[i].end());
            string name = accounts[i][0];
            stack<int> stk;
            stk.push(i);
            
            while(!stk.empty()){
                int p = stk.top();
                stk.pop();
                if(merged[p]) continue;
                merged[p] = true;
                for(int child : adjList[p]){
                    init.insert(accountWithEmailIndex[child].begin(), accountWithEmailIndex[child].end());
                    stk.push(child);
                }
            }
            
            vs temp;
            temp.push_back(name);
            for(int i : init){
                temp.push_back(intToEmail[i]);
            }
            answer.push_back(temp);
        }
        return answer;
    }
};
