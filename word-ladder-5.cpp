// https://leetcode.com/problems/word-ladder/description/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        queue<string> qq;
        if (wordDict.count(endWord) == 0) return 0;
        int dist = 2;
        addNextWords(beginWord, wordDict, qq);
        
        while(!qq.empty()){
            int size = qq.size();
            while(size--){
                auto top = qq.front();
                qq.pop();
                if (top == endWord) return dist;
                addNextWords(top, wordDict, qq);
            }
            
            dist++;
        }
        
        return 0;
    }
    
    
    void addNextWords(string str, unordered_set<string>& wordDict, queue<string>& qq){
        wordDict.erase(str);
        // cout << str << ": ";
        for(int i = 0; i < str.length(); i++){
            char ll = str[i];
            for(int j = 0; j < 26; j++){
                str[i] = 'a' + j;
                // cout << "Check: " << str << endl;
                if (wordDict.count(str)){
                    qq.push(str);
                    wordDict.erase(str);
                    // cout << str << ", ";
                }
            }
            str[i] = ll;
        }
        // cout << endl;
    }
};
