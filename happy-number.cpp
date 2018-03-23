// https://leetcode.com/problems/happy-number/description/

class Solution {
public:
    
    int digitSum(int n){
        int ans = 0;
        
        while(n){
            int d = n % 10;
            ans += d*d;
            n /= 10;
        }
        
        return ans;
    }
    
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSum(slow);
            fast = digitSum(fast);
            fast = digitSum(fast);
        } while (slow != fast);
        return (slow == 1) ? true : false;
    }
};
