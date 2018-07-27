// https://www.lintcode.com/problem/two-sum/description

class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
       int n = numbers.size();
       unordered_map<int, int> um;
       
       for(int i = 0; i < numbers.size(); i++){
           int key = target - numbers[i];
           if (um.count(target - numbers[i])){
               return {um[key], i};
           }
           um[numbers[i]] = i;
       }
    }
};
