// https://leetcode.com/problems/palindrome-pairs/description/

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
#define ss(v) sort(v.begin(), v.end())
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef unordered_map<int, vi> umpiv;
typedef set<int> si;
typedef unordered_set<int> usi;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vvi ans;
        unordered_map<string, int> suffix;
        int i, j;
        
        ff(i, 0, words.size()){
            string word = words[i];
            reverse(word.begin(), word.end());
            suffix[word] = i;
        }
        
        ff(i, 0, words.size()){
            if (words[i] != "" && suffix.count("") && isPalin(words[i]))
                ans.push_back({suffix[""], i});
        }
        
        ff(i, 0, words.size()){
            ff(j, 0, words[i].size()){
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if (suffix.count(left) && isPalin(right) && suffix[left] != i) 
                    ans.push_back({i, suffix[left]});
                if (suffix.count(right) && isPalin(left) && suffix[right] != i) 
                    ans.push_back({suffix[right], i});
            }
        }
        
        return ans;
    }
    
    bool isPalin(string& str){
        int i = 0,j = str.length() - 1;
        while(i < j)
            if (str[i++] != str[j--]) return false;
        return true;
    }
};
