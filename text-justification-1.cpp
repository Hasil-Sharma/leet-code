// https://leetcode.com/problems/text-justification/description/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0, j = 0, wordCount = 0, n = words.size(), spaces, numslots;
        
        while (j < n){
            while(j < n && wordCount + words[j].length() + j - i <= maxWidth)
                wordCount += words[j++].length();
            
            // j th word has caused the overflow and will not fit current line
            // maxwidth - all the characters in the string
            spaces = maxWidth - wordCount;
            numslots = j - i - 1;
            // have to divide spaces evenly
            stringstream ss;
            ss << words[i++];
            
            if (numslots == 0) ss << string(spaces, ' ');
            else if (j < n){
                int numSpace = spaces / numslots , extraSpace = spaces % numslots;
                while(i < j){
                    ss << string(numSpace + (extraSpace > 0), ' ') << words[i++];
                    extraSpace--;
                }
            } else {
                // for last line
                int cc = 0;
                while(i < j) ++cc && (ss << string(1, ' ') << words[i++]);
                
                (spaces - cc > 0) && (ss << string(spaces - cc, ' '));
                
            }
            
            // cout << ss.str() << endl;
            ans.push_back(ss.str());
            wordCount = 0;
        }
        
        return ans;
        
    }
};
