// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    string convert(string& s){
        vector<int> hash(26, 0);
        
        for(char c : s){
            hash[c - 'a']++;
        }
        
        stringstream ss;
        for(int i = 0; i < 26; i++){
            if (hash[i]){
                ss << string(1,'a' + i) << hash[i];
            }
        }
        return ss.str();
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> um;
        for(string& str : strs){
            um[convert(str)].push_back(str);
        }
        
        for(auto kv : um){
            cout << kv.first << endl;
            ans.push_back(kv.second);
        }
        return ans;
    }
};
