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
        int c = 4, count = 0;
        
        while(count < n && c == 4)
            count += (c = read4(buf + count));
        
        return count > n ? n : count;
    }
};
