// https://www.lintcode.com/problem/sentence-similarity/description

class Solution {
public:

    bool hasCommon(unordered_set<int> s1, unordered_set<int> s2){
        int flag = false;
        
        for(const int &i : s1){
            if (s2.find(i) != s1.end())
                flag = true;
        }
        
        return flag;
    }
    
    /**
     * @param words1: a list of string
     * @param words2: a list of string
     * @param pairs: a list of string pairs
     * @return: return a boolean, denote whether two sentences are similar or not
     */
    bool isSentenceSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        // write your code here
        unordered_map<string, unordered_set<int>> pairMap;
        bool ans = true;
        // consider the case of a->b, b->c
        // given this logic a: {1}, b : {1, 2}, c : 2 
        for(int i = 0; i < pairs.size(); i++){
            for(int j = 0; j < pairs[i].size(); j++){
                pairMap[pairs[i][j]].insert(i);
            }
        }
        
        if (words1.size() != words2.size())
            return false;
            
        for(int i = 0; i < words1.size() && ans; i++){
            if (words1[i] == words2[i])
                continue;
            auto itr1 = pairMap.find(words1[i]);
            auto itr2 = pairMap.find(words2[i]);
            
            if (itr1 != pairMap.end() && itr2 != pairMap.end() && hasCommon(itr1->second, itr2->second)){
                // check if common elements are present
                continue;
            } else ans = false;
            
        }
        return ans;
    }
};
