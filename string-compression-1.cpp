// https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& chars) {
        int sidx = 0, count = 0, len = 0, n = chars.size();
        
        for(int i = 0; i <= n; i++){
            if (i < n && chars[sidx] == chars[i]) count++;
            else {
                chars[len++] = chars[sidx];
                if (count > 1){
                    string cs = to_string(count);
                    for(char c : cs)
                        chars[len++] = c;
                }
                
                sidx = i;
                count = 1;
            }
        }
        
        return len;
    }
};
