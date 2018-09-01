// https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/description/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    queue<char> left;
    int read(char *buf, int n) {
        int len = 0, temp = 4;
        
        while(left.size()){
            buf[len++] = left.front();
            left.pop();
            if (len == n) return n;
        }
        
        while(len < n && temp == 4){
            temp = read4(buf + len);
            len += temp;
        }
        
        for(int i = n; i < len; i++)
            left.push(buf[i]);
        
        int e = min(n, len);
        
        buf[e] = '\0';
        return e;
    }
};
