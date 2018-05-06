// https://leetcode.com/problems/keyboard-row/description/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string a[3] = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };
        
        unordered_map<char, int> hash_map;
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < a[i].length(); j++)
                hash_map[a[i][j]] = i;
        }
            
        vector<string> answer;
        
        for(auto word: words){
            int start = hash_map[tolower(word[0])];
            bool flag = true;
            for(auto chr : word){
                if (start != hash_map[tolower(chr)]){
                    flag = false;
                    break;
                }
            }
            
            if (flag) {
                answer.push_back(word);
            }
        }
        
        return answer;
    }
};
