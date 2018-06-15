// https://leetcode.com/problems/reverse-vowels-of-a-string/description/

class Solution {
public:
    /**
     * @param s: a string
     * @return: reverse only the vowels of a string
     */
    string reverseVowels(string &s) {
        // write your code here
        int start = 0, end = s.length() - 1, a, b;
        unordered_map<char, int> hashMap = {
            {'a', 0},
            {'e', 0},
            {'i', 0},
            {'o', 0},
            {'u', 0},
            {'A', 0},
            {'E', 0},
            {'I', 0},
            {'O', 0},
            {'U', 0}
        };
        
        while(end  > start){
            
            a = hashMap.count(s[end]);
            b = hashMap.count(s[start]);
            
            if (a && b){
                swap(s[start++], s[end--]);
            }
            if (!a){
                end--;
            } 
            if (!b){
               start++;
            }
        }
        return s;
    }
};
