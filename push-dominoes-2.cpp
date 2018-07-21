// https://leetcode.com/problems/push-dominoes/description/

#define mp(A, B) make_pair(A, B)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
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
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}

class Solution {
public:

    string pushDominoes(string dominoes) {
        int n = dominoes.size(), rIdx = -1;
        for(int i = 0; i < n; i++){
            if (dominoes[i] == 'R'){
                rIdx = i;
            } else if (i > 0 && dominoes[i] == 'L' && dominoes[i-1] != 'L'){
                // go back and adjust
                for(int j = i - 1; j > rIdx; j--){
                    if (dominoes[j] == 'L') break;
                    else if ((i - j < j - rIdx) || rIdx == -1) dominoes[j] = 'L';
                    else if (i - j == j - rIdx) dominoes[j] = '.';
                }
                rIdx = -1;
            } else if (rIdx != -1){
                dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};
