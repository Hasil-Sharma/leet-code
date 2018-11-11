// https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, m1 = version1.length(), m2 = version2.length(), temp1 = 0, temp2 = 0;
        
        while(i < m1 || j < m2){
            extract(version1, i, temp1);
            extract(version2, j, temp2);
            if (temp1 != temp2)
                return temp1 > temp2 ? 1 : -1;
            temp1 = temp2 = 0;
        }
        
        return 0;
    }
    
    void extract(string& version, int& idx, int& val){
        while(idx < version.length() && version[idx] != '.')
            val = val * 10 + version[idx++] - '0';
        idx++;
    }
};
