// https://leetcode.com/problems/word-ladder/description/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, int> str2int;
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> dist;
        
        int i = 0;
        for(auto str : wordList)
            str2int[str] = i++;
        
        if (str2int.count(endWord) == 0) return 0;
        
        for(auto s1: wordList){
            for(auto s2: wordList){
                if (getDiff(s1, s2) == 1){
                    adjList[str2int[s1]].push_back(str2int[s2]);
                }
            }
        }
        
        int s = str2int[beginWord], d = str2int[endWord];
        
        queue<int> qq;
        qq.push(s);
        dist[s] = 1;
        
        while(!qq.empty()){
            auto top = qq.front();
            qq.pop();
            
            if (top == d) return dist[d];
            
            for(auto c : adjList[top]){
                if (dist.count(c)) continue;
                dist[c] = dist[top] + 1;
                qq.push(c);
            }
        }
        
        return 0;
    }
    
    int getDiff(string& s1, string& s2){
        int count = 0;
        
        for(int i = 0; i < s1.length(); i++)
            count += (s1[i] != s2[i]);
        
        return count == 1;
    }

};
