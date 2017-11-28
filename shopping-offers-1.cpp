// https://leetcode.com/problems/shopping-offers/description/
#include <bits/stdc++.h>
using namespace std;

int operator*(vector<int>& a, vector<int>& b){
    int ans = 0;
    for(int i = 0; i < a.size(); i++)
        ans += a[i] * b[i];
    return ans;
}

bool operator<(const vector<int>&a, const int &n){
    for(int i : a)
        if (i < n)
            return true;
    return false;
}

void operator-=(vector<int> &a, vector<int> &b){
    for(int i = 0; i < a.size(); i++)
        a[i] -= b[i];
}

void operator+=(vector<int> &a, vector<int> &b){
    for(int i = 0; i < a.size(); i++)
        a[i] += b[i];
}

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
        if (needs < 0)
            return INT_MAX;
        
        // starting with gauging cost to be composed of uni-item purchase
        int m = cost + needs * price;
        
        // plugin offers and check
        for(auto &offer: special){
            if (cost + offer.back() >= m)
                continue;
            needs -= offer;
            m = min(m, shoppingOffers(price, special, needs, cost + offer.back()));
            needs += offer;
        }
        return m;
    }
};

