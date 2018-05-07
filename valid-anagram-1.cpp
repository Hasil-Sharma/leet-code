// https://leetcode.com/problems/valid-anagram/submissions/1

class Solution {
public:
    void getCount(string s, vector<int>& count){
        for(auto c : s){
            count[c - 'a'] += 1;
        }
    }
    
    bool isAnagram(string s, string t) {
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        getCount(s, count1);
        getCount(t, count2);
        bool flag = true;
        for(int i = 0; i < 26 && flag; i++){
            flag = (count1[i] == count2[i]);
        }
        return flag;
    }
};
