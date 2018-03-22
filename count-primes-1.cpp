// https://leetcode.com/problems/count-primes/description/
class Solution {
public:
    int countPrimes(int n) {
        int ans = 0; // handles non-negative numbers 
        if (n == 0) return ans;
        
        bool flag[n];
        for(int i = 0; i < n; i++)
            flag[i] = false;
        
        for(int i = 2; i < n; i++){
            if (flag[i] == false){
                ans++;
                for(int j = 2; i * j < n; j++) 
                    flag[i * j] = true;
            }
        }
        return ans;
    }
};
