// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> S(26, 0), P(26, 0), ans;
        int m = s.length(), n = p.length();
        
        for(char c : p)
            P[c-'a']++;
        int j = 0;
        for(; j < n; j++)
            S[s[j] - 'a']++;
        int i = 0;
        while(j < m){
            if (cmp(S, P))
                ans.push_back(i);
            S[s[i++] - 'a']--;
            S[s[j++] - 'a']++;
        }
        
        if (cmp(S, P))
                ans.push_back(i);
        
        return ans;
    }
    
    bool cmp(vector<int>& v1, vector<int>& v2){
        int n = v1.size();
        for(int i = 0; i < n; i++)
            if (v1[i] != v2[i])
                return false;
        return true;
    }
};
