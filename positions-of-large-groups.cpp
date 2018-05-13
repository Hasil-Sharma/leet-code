// https://leetcode.com/problems/positions-of-large-groups/description/
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int sIdx = 0, eIdx, count = 1;
        vector<vector<int>> vvi;
        
        if (S.length() == 0) 
            return vvi;
        
        char chr = S[0];
        
        for(int i = 1; i < S.length(); i++){
            if (S[i] == chr){
                count++;
                eIdx = i;
            } else {
                if (count >= 3) 
                    vvi.push_back({sIdx, eIdx});
                sIdx = i;
                count = 1;
                chr = S[i];
            }
        }
        
        if (count >= 3)
            vvi.push_back({sIdx, eIdx});
        
        return vvi;
    }
};
