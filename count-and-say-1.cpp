// https://www.lintcode.com/problem/count-and-say/description

class Solution {
public:
    /**
     * @param n: the nth
     * @return: the nth sequence
     */
    string countAndSay(int n) {
        // write your code here
        string ans = "1";
        
        while(--n){
            int count = 0;
            stringstream temp;
            char prev = ans[0];
            for(char c : ans){
                if (c == prev) count++;
                else {
                    temp << count;
                    temp << prev;
                    count = 1;
                    prev = c;
                }
            }
            temp << count;
            temp << prev;
            ans = temp.str();
        }
        return ans;
    }
};
