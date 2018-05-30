// https://leetcode.com/problems/maximum-swap/description/
class Solution {
public:
    int maximumSwap(int num) {
        int i1 = -1, i2 = -1, rightmax = -1, ans = 0, decimal = 1;
        vector<int> digits;
        if (num <= 10) return num;
        
        while(num){
            digits.push_back(num % 10);
            num /= 10;
        }
        
        reverse(digits.begin(), digits.end());
        for(int i = 0; i < digits.size() && i1 == -1; i++){
            for(int j = i; j < digits.size(); j++){
                if (digits[i] < digits[j] && rightmax <= digits[j]){
                    i2 =  j;
                    rightmax = digits[j];
                }
            }
            i1 = (i2 != -1) ? i : i1;
        }
        
        if(i2 != -1) swap(digits[i1], digits[i2]);
        reverse(digits.begin(), digits.end());
        for(int &a : digits){
            ans += a * decimal;
            decimal *= 10;
        }
        return ans;
    }
};
