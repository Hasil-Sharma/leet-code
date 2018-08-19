// https://leetcode.com/problems/goat-latin/description/

class Solution {
public:
    string toGoatLatin(string S) {
        bool flag = false;
        string token;
        stringstream ss(S), ans;
        string aux = "a";
        while(ss >> token){
            if (flag) ans << " ";
            if (!isVowel(token[0]))
                token = token.substr(1) + string(1, token[0]);
            ans << token << "ma" << aux;
            aux = aux + "a";
            flag = true;
        }
        return ans.str();
    }
    
    bool isVowel(char c ){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};
