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
        int n = dominoes.size();
        vi distL(n, -1), distR(n, -1);
        bool flag = false;;
        
        for(int i = 0; i < n; i++){
            if (dominoes[i] == 'L'){
                flag = false;
            } else if (dominoes[i] == 'R') {
                flag = true;
            } else if (flag)
                distR[i] = i != 0 ? distR[i-1] + 1 : 0;
        }

        flag = false;
        for(int i = n - 1; i >= 0; i--){
            if (dominoes[i] == 'R'){
                flag = false;
            } else if (dominoes[i] == 'L'){
                flag = true;
            } else if (flag)
                distL[i] = i < n - 1 ? distL[i+1] + 1 : 0;
        }

        for(int i = 0; i < n; i++){
            if (distL[i] == -1 && distR[i] == -1) 
                continue;
            else if (distR[i] != -1 && distL[i] != -1){
                if (distL[i] > distR[i]) dominoes[i] = 'R';
                else if (distL[i] < distR[i]) dominoes[i] = 'L';
            } else if (distR[i] != -1) dominoes[i] = 'R';
            else if (distL[i] != -1) dominoes[i] = 'L';

        }
        return dominoes;
    }
};
