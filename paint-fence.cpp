// https://www.lintcode.com/problem/paint-fence/description
class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // write your code 
        vector<int> same(n + 1, 0), different(n + 1, 0), total(n + 1, 0);
        different[1] = k;
        total[1] = k;
        
        for(int i = 2; i <= n; i++){
            same[i] = different[i - 1];
            different[i] = total[i - 1] * (k - 1);
            total[i] = same[i] + different[i];
        }
        return total[n];
    }
};
