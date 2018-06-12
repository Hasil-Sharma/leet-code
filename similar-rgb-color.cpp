// https://www.lintcode.com/problem/similar-rgb-color/description

class Solution {
public:
    /**
     * @param color: the given color
     * @return: a 7 character color that is most similar to the given color
     */
    string similarRGB(string &color) {
        // Write your code here
        vector<string> units = {
            "00", "11", "22", "33", "44", "55", "66", "77", 
            "88", "99", "aa", "bb", "cc", "dd", "ee", "ff"
        };
        
        vector<string> possibleColor;
        string ans;
        int diff = INT_MIN, temp;
        for(int i = 0; i < units.size(); i++)
            for(int j = 0; j < units.size(); j++)
                for(int k = 0; k < units.size(); k++)
                    possibleColor.push_back("#" + units[i] + units[j] + units[k]);
        
        for(string& p : possibleColor){
            temp = findDiff(p, color);
            if (temp > diff){
                ans = p;
                diff = temp;
            }
        }
        return ans;
    }
    
    int findDiff(string & s1, string & s2){
        int v1, v2, total = 0;
        for(int i = 1; i < 7; i+=2){
            stringstream ss1, ss2;
            ss1 << s1[i];
            ss1 << s1[i+1];
            
            ss2 << s2[i];
            ss2 << s2[i+1];
            
            ss1 >> std::hex >> v1;
            ss2 >> std::hex >> v2;
            total -= (v1 - v2)*(v1 - v2);
        }
        return total;
    }
};
