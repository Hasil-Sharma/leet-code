// https://www.lintcode.com/problem/find-anagram-mappings/description

class Solution {
public:
    /**
     * @param A: lists A
     * @param B: lists B
     * @return: the index mapping
     */
    vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
        // Write your code here
        unordered_map<int, stack<int>> hashMap;
        vector<int> ans;
        for(int i = 0; i < B.size(); i++){
            if (!hashMap.count(B[i]))
                hashMap[B[i]] = stack<int>();
            hashMap[B[i]].push(i);
        }

        for(int &a : A){
            ans.push_back(hashMap[a].top());
            hashMap[a].pop();
        }
        return ans;
    }
};
