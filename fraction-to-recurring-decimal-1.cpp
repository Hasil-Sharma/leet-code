// https://leetcode.com/problems/fraction-to-recurring-decimal/description/

class Solution {
public:
    string fractionToDecimal(int num, int den) {
        stringstream ss;
        int sign = 1;
        string ans;
        long numerator = 1l * num;
        long denominator = 1l * den;
        
        if (numerator < 0){
            numerator *= -1;
            sign *= -1;
        }
        if (denominator < 0){
            denominator *= -1;
            sign *= -1;
        }
        if (numerator == 0) sign = 1;
        // printf("%d/%d: ", numerator, denominator);
        ss << numerator / denominator;
        numerator %= denominator;
        unordered_map<int, int> hashMap;
        unordered_map<int, int> :: iterator itr = hashMap.end();
        if (numerator != 0){
            ss << ".";
            numerator *= 10;
            while(numerator != 0){
                itr = hashMap.find(numerator);
                while(numerator < denominator && itr == hashMap.end()){
                    hashMap[numerator] = ss.str().length() + 1;
                    numerator *= 10;
                    ss << "0";
                    if ((itr = hashMap.find(numerator)) != hashMap.end()) 
                        break;
                }
                
                if (itr != hashMap.end() && numerator != 0){
                    ss << ")";
                    ans = ss.str();
                    ans.insert(itr->second - 1, "(");
                    break;
                }
                ss << numerator / denominator;
                hashMap[numerator] = ss.str().length();
                numerator %= denominator;
                numerator *= 10;
                
            }
            if (numerator == 0) ans = ss.str();
        } else {
            ans = ss.str();
        }
        // cout << ans << endl;
        return (sign == -1) ? "-" + ans : ans;
    }
};
