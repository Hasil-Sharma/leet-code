// https://leetcode.com/problems/validate-ip-address/

class Solution {
public:
    string validIPAddress(string IP) {
        
        int n = IP.length(), i = 0;
        
        while(i < n){
            if (IP[i] == ':') return check1(IP) ? "IPv6" : "Neither";
            else if (IP[i] == '.') return check2(IP) ? "IPv4" : "Neither";
            i++;
        }
        
        return "Neither";
    }
    
    bool check2(string IP){
        int count = 0, i = 0, j = 0, n = IP.length();
        
        while(j <= n){
            char c = j < n ? IP[j] : '.';
            if(c != '.'  && !isdigit(c)) return false;
            if (c == '.'){
                count++;
                int len = j - i;
                if (len == 0 || len > 3) return false;
                else if (len != 1 && IP[i] == '0') return false;
                else if (stoi(IP.substr(i, len)) > 255) return false;
                i = j + 1;
            }
            
            j++;
        }
        
        return count == 4;
    }
    
    bool check1(string IP){
        // IPv6
        int count = 0, i = 0, j = 0, n = IP.length();
        unordered_set<char> possible;
        for(char c = '0'; c <= '9'; c++)
            possible.insert(c);
        for(char c = 'a'; c <= 'f'; c++)
            possible.insert(c);
        
        possible.insert(':');
        
        while(j <= n){
            char c = j < n ? tolower(IP[j]) : ':';
            if (!possible.count(c)) return false;
            else if (c == ':'){
                ++count;
                int len = j - i;
                if (len == 0 || len > 4) return false; // case of :: and :adsfc: 
                i = j + 1;
            }
            j++;
        }
        
        return count == 8;
    }
};
