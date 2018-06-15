// https://www.lintcode.com/problem/twitch-words/description

class Solution {
public:
    /**
     * @param str: the origin string
     * @return: the start and end of every twitch words
     */
    vector<vector<int>> twitchWords(string &str) {
        // Write your code here
        vector<vector<int>> ans;
        int start = 0, end = 0, count = 0;
        while(end != str.length()){
            if (str[start] == str[end]){
                count++;
                end++;
            } else if (str[start] != str[end]){
                if (count >= 3)
                    ans.push_back({start, end - 1});
                start = end;
                count = 0;
            }
        }
        
        if (count >= 3)
            ans.push_back({start, end - 1});
        
        return ans;
    }
};
