// https://leetcode.com/problems/jewels-and-stones/description/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewelsMap(J.begin(), J.end());
        int ans = 0;
        
        for(char c : S)
            ans += jewelsMap.count(c);
        
        return ans;
    }
};
