// https://leetcode.com/problems/shopping-offers/description/

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

bool operator>=(const vi& vec, const int val){
    for(int i = 0; i < vec.size(); i++)
        if (vec[i] < 0) return false;
    return true;
}

int operator*(const vi& v1, const vi& v2){
    int ans = 0;
    for(int i = 0; i < v1.size(); i++)
        ans += v1[i] * v2[i];
    return ans;
}

void operator-=(vi& v1, const vi& v2){
    for(int i = 0; i < v1.size(); i++)
        v1[i] -= v2[i];
}

void operator+=(vi& v1, const vi& v2){
    for(int i = 0; i < v1.size(); i++)
        v1[i] += v2[i];
}

class Solution {
public:
    // prev - running cost of buying the things
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int prev = 0) {
        int ans;
        
        // just buy items at cost price
        ans = prev + needs * price;
        
        for(vi& offer: special){
            if (prev + offer.back() > ans)
                continue; 
            // taking current offer
            needs -= offer;
            if (needs >= 0)
                ans = min(ans, shoppingOffers(price, special, needs, prev + offer.back()));
            needs += offer;
        }
        return ans;
    }
};
