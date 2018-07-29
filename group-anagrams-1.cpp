// https://leetcode.com/problems/group-anagrams/description/

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef set<int> si;
typedef unordered_set<int> usi;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}
class Solution {
public:
    int getKey(string& str, vi& primes){
        int n = 1;
        for(char c : str)
            n = n * (primes[c - 'a']);
        return n;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 
                     47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        unordered_map<int, vs> um;
        vvs ans;
        
        for(string& str: strs){
            int key = getKey(str, primes);
            um[key].push_back(str);
        }
        
        for(auto kv: um){
            ans.push_back(kv.second);
        }
        return ans;
    }
};
