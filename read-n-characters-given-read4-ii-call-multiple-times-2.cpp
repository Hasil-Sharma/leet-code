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
    
    queue<char> q;
    int read(char *buf, int n) {
        if (!buf) return 0;
        int c = 4, count = 0;
        
        while(count < n && q.size()){
            buf[count++] = q.front();
            q.pop();
        }
        
        while(count < n && c == 4)
            count += (c = read4(buf + count));
        
        if (count > n){
            int i = n;
            while(i < count)
                q.push(buf[i++]);
            count = n;
        }
        
        buf[n+1] = '\0';
        return count;
    }
};
