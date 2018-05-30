// https://leetcode.com/problems/maximum-swap/description/

class Solution {
public:
    int maximumSwap(int num) {
        if (num <= 10) return num;
        int i1 = -1, i2 = -1, rightmax = -1, ans = 0;
        vector<int> digits;
        while(num){
            digits.push_back(num % 10);
            num /= 10;
        }
        
        for(int i = digits.size() - 1; i >= 0 && i1 == -1; i--){
            for(int j = 0; j < i; j++){
                if (digits[i] < digits[j] && rightmax < digits[j]){
                    i2 = j;
                    i1 = i;
                    rightmax = digits[j];
                }
            }
        }
        
        if(i2 != -1) swap(digits[i1], digits[i2]);
        
        for(int i = digits.size() - 1; i >= 0; i--){
            ans = ans * 10 + digits[i];
        }
        return ans;
    }
};
