// https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        
        while(x){
            int t = x % 10;
            x = x/ 10;
            if (ans > INT_MAX/10 || (ans == INT_MAX/10 && t > INT_MAX % 10)) return 0;
            if (ans < INT_MIN/10 || (ans == INT_MIN/10 && t < INT_MIN % 10)) return 0;
            cout << t << " " << x << endl;
            ans = ans * 10 + t;
        }
        
        return ans;
    }
};
