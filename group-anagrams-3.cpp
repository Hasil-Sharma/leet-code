// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    
    string norm(string str){
        vector<char> vv(26, 0);
        stringstream ss;
        for(char c : str)
            vv[c - 'a']++;
        
        for(int i = 0; i < 26; i++){
            ss << string(1, 'a' + i);
            ss << to_string(vv[i]);
        }
        return ss.str();
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> ump;
        
        for(string str: strs){
            ump[norm(str)].push_back(str);
        }
        
        for(auto kv : ump){
            ans.push_back(kv.second);
        }
        
        return ans;
    }
};
