// https://leetcode.com/problems/group-anagrams/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int primes[27] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> hash_map;
        vector<vector<string>> ans;
        
        for(string str: strs){
            int key = 1;
            for(char c: str)
                key *= primes[c - 'a'];
            hash_map[key].push_back(str);
        }
        
        for(auto& itr : hash_map)
            ans.push_back(itr.second);
        
        return ans;
    }
};

