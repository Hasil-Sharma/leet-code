// https://leetcode.com/problems/24-game/

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
template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        gen_sign();
        return gen_perm(nums, 0);
    }
    
private:
    vvc signs;
    vc sign;
    
    void gen_sign(){
        if (sign.size() == 3) {
            signs.push_back(sign);
            return;
        }
        
        vc cand = {'*', '/', '+', '-'};
        
        for(auto cc : cand){
            sign.push_back(cc);
            gen_sign();
            sign.pop_back();
        }
    }
    
    bool gen_perm(vi& nums, int n){
        bool flag = false;
        if (n == nums.size()){
            flag = check(nums);
        }
        
        for(int i = n; i < nums.size() && !flag; i++){
            swap(nums[i], nums[n]);
            flag = gen_perm(nums, n + 1);
            swap(nums[i], nums[n]);
        }
        
        return flag;
    }
    
    bool check(vi& nums){
        bool flag = false;
        
        for(vc& sign : signs){
            flag = flag || evaluate(nums, sign);
        }
        
        return flag;
    }
    
    bool evaluate(vi& nums, vc& sign){
        // there are six ways to evaluate - abcd
        int a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        double ab = eval(a, b, sign[0]), 
            bc = eval(b, c, sign[1]), 
            cd = eval(c, d, sign[2]), 
            abc1 = eval(a, bc, sign[0]), // a bc 
            abc2 = eval(ab, c, sign[1]),  // ab c
            bcd1 = eval(b, cd, sign[1]),  // b cd
            bcd2 = eval(bc, d, sign[2]); // bc d
        
        return  // ab == 24 || bc == 24 || cd == 24 || abc1 == 24 || abc2 == 24 || bcd1 == 24 || bcd2 == 24 ||
                comp(eval(ab, cd, sign[1])) || // ab cd
                comp(eval(eval(ab, c, sign[1]), d, sign[1])) || // (ab c) d
                comp(eval(eval(a, bc, sign[0]), d, sign[1])) || // (a bc) d
                comp(eval(a, eval(bc, d, sign[2]), sign[0])) || // a (bc d)
                comp(eval(a, eval(b, cd, sign[1]), sign[0])); // a (b cd)
    }
    
    double eval(double a, double b, char c){
        if (c == '*') return a*b;
        else if (c == '/') return a/b;
        else if (c == '+') return a + b;
        else return a - b;
    }
    
    bool comp(double val){
        return abs(val - 24.0) < 1e-6;
    }
};
