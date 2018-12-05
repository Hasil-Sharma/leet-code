// https://leetcode.com/problems/most-common-word/description/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(auto &c : paragraph) c = isalpha(c) ? tolower(c) : ' ';
        
        stringstream ss(paragraph);
        unordered_set<string> banned_set(banned.begin(), banned.end());        
        unordered_map<string, int> word_count;
        string temp, ans;
        int count = 0;
        
        while(ss >> temp){
            if (banned_set.count(temp)) continue;
            word_count[temp] += 1;
            if (word_count[temp] > count) {
                count = word_count[temp];
                ans = temp;
            }
        }
        
        return ans;
    }
     
};
