// https://leetcode.com/problems/next-closest-time/description/

class Solution {
public:
    bool checkValid(string& tt, char c, int idx){
        if (idx == 4) return true;
        else if (idx == 1) return tt[idx-1] < '2' || (c < '4');
        else if (idx == 3) return c < '6' && c >= '0';
        return c >= '0' && c < '3';
    }
    
    string nextClosestTime(string time) {
        vector<char> ans(time.begin(), time.end());
        int n = time.length(), idx = -1;
        char min_char = time[n-1];
        
        for(int i = n - 1; i >= 0 && idx == -1; i--){
            if (time[i] == ':') continue;
            char curr = time[i], temp = time[i];
            
            for(int j = n - 1; j >= 0; j--){
                if (time[j] == ':' || j == i) continue;
                min_char = min(min_char, time[j]);
                temp = time[j] > curr && (temp > time[j] || temp == curr) && checkValid(time, time[j], i) ? time[j] : temp;
            }
            
            ans[i] = temp;
            idx = curr != temp ? i : idx;
        }
        
        for(int i = idx + 1; i < n; i++)
            ans[i] = ans[i] != ':' ? min_char : ':';
        
        return string(ans.begin(), ans.end());
    }
};
