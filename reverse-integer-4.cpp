// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int ans = 0, t;
        
        while(x){
            t = x % 10;
            x = x/10;
            if (ans > INT_MAX/10 || (ans == INT_MAX/10 && INT_MAX % 10 < t)) return 0;
            if (ans < INT_MIN/10 || (ans == INT_MIN/10 && INT_MIN % 10 > t)) return 0;
            ans = ans*10 + t;
        }
        
        return ans;
    }
};
