// https://leetcode.com/problems/ugly-number/description/

class Solution {
public:
    void reduce(int &num, int factor){
        while(num % factor == 0 && num != 1 && num != 0)
            num /= factor;
    }
    bool isUgly(int num) {
        vector<int> factors = {2, 3, 5};
        for(int& factor: factors)
            reduce(num, factor);
        
        return num == 1;
    }
};
