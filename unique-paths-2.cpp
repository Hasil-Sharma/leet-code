// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans = 0, up[n+1];
        
        for(int i = 0; i <= n; i++)
            up[i] = 1;
        
        for(int i = 2; i <= m; i++){
            for(int j = 2, left = 1; j <= n; j++){
                ans = up[j] + left;
                left = ans;
                up[j] = ans;
            }
        }
        return up[n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
