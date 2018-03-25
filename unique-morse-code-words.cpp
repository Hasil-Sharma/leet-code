// https://leetcode.com/problems/unique-morse-code-words/description/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map <string, bool> map;
        const char* morseCode [] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto str: words){
            stringstream ss;
            for (char c : str){
                ss << morseCode[c - 'a'];
            }
            map[ss.str()] = true;
        }
        
        
        return map.size();
    }
};
