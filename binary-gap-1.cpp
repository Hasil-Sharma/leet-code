// https://leetcode.com/contest/weekly-contest-93/problems/binary-gap/

class Solution {
public:
    int binaryGap(int N) {
        int ans = 0, i = 0, pos = -1;
        
        while(N){
            int temp = N % 2;
            if (temp == 1) {
                if (pos != -1) ans = max(ans, i - pos);
                
                pos = i;
            }
            N /= 2;
            i++;
        }
        return ans;
    }
};
