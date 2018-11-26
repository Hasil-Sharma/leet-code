// https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), start = 0, len = 0, end = 0, tlen;
        
        while(end <= n){
            if (end < n && chars[start] == chars[end]) end++;
            else {
                tlen = end - start;
                chars[len] = chars[start];
                len += 1 + helper(chars, tlen, len + 1);
                start = end;
                end++;
            }
        }
        
        return len;
    }
    
    int helper(vector<char>& chars, int tlen, int start){
        int i = start, ans = 0;
        if (tlen == 1) return 0;
        while(tlen){
            chars[i++] = '0' + (tlen % 10);
            tlen /= 10;
        }
        
        ans = i - start;
        i--;
        while(start < i){
            swap(chars[start], chars[i]);
            start++; i--;
        }
        
        return ans;
    }
};
