// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

class Solution {
public:
    void makeMap (unordered_map<int, int>& m, vector<int>& v){
        for(int &i : v)
            m[i]++;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashMap1, hashMap2;
        unordered_map<int, int>:: iterator mapItr;
        vector<int> ans;
        int count;
        
        makeMap(hashMap1, nums1);
        makeMap(hashMap2, nums2);
        
        for(auto &itr : hashMap1){
            if((mapItr = hashMap2.find(itr.first)) != hashMap2.end()){
                count = min(itr.second, mapItr->second);
                while(count--)
                    ans.push_back(itr.first);
            }
        }
        
        return ans;
    }
};
