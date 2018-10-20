// https://leetcode.com/problems/compare-version-numbers/description/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, m1 = version1.length(), m2 = version2.length();
        int num1 = 0, num2 = 0;
        
        while(i < m1 || j < m2){
            while(i < m1 && version1[i] != '.'){
                num1 = num1*10 + version1[i] - '0';
                i++;
            }
            
            while(j < m2 && version2[j] != '.'){
                num2 = num2*10 + version2[j] - '0';
                j++;
            }
            
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
            num1 = num2 = 0;
            i++; j++;
        }
        
        return 0;
    }
};
