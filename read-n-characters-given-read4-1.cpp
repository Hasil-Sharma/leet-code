// https://leetcode.com/problems/read-n-characters-given-read4/description/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if (!buf) return 0;
        int ans = 0, temp = 4;
        while(ans < n && temp == 4){
            temp = read4(buf + ans);
            ans += temp;
        }
        return ans > n ? n : ans;
    }
};
