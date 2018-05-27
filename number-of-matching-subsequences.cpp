// https://leetcode.com/problems/number-of-matching-subsequences/description/

class Solution {
public:
    unordered_map<char, vector<int>> sTable;
    unordered_map<char, vector<int>> :: iterator itr;
    vector<int> :: iterator itr1;
    int numMatchingSubseq(string S, vector<string>& words) {
        // O(|S|) : Space complexity
        // O(|words|*|word|*log|S|)
        int i = 0, count = 0, last;
        bool flag;
        for(char &c : S) {
            if((itr = sTable.find(c)) != sTable.end())
                itr->second.push_back(i++);
            else sTable[c] = {i++};
        }
        
        for(string& word : words){
            last = -1;
            flag = true;
            for(char& c : word){
                if(
                    (itr = sTable.find(c)) != sTable.end() && 
                    (itr1 = upper_bound(itr->second.begin(), itr->second.end(), last)) != itr->second.end()
                  )
                    last = *itr1;
                else {
                    flag = false;
                    break;
                }
            }
            
            count += flag;
        }
        
        return count;
    }
};
