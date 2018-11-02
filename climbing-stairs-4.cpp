// https://leetcode.com/problems/climbing-stairs/description/

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
#define ss(v) sort(v.begin(), v.end())
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
class Solution {
public:
    int climbStairs(int n) {
        vvi m = {{1, 1}, {1, 0}}, ans = {{1, 0}, {0, 1}};
        expo(m, ans, n);
        return ans[0][0];
    }
    
    void expo(vvi& m, vvi& ans, int n){
        while(n > 0){
            if (n&1)
                multiply(ans, m);
            n >>= 1;
            multiply(m, m);
        }
    }
    
    void multiply(vvi& m1, vvi& m2){
        int a, b, c, d;
        
        a = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
        b = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
        c = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
        d = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
        
        m1[0][0] = a;
        m1[0][1] = b;
        m1[1][0] = c;
        m1[1][1] = d;
    }
    
    
};
