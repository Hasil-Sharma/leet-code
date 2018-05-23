// https://leetcode.com/problems/employee-importance/description/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> hashMap;
        stack<Employee*> stk;
        Employee* eTemp;
        int totalImp = 0;
        for(auto &e : employees)
            hashMap[e->id] = e;
        
        stk.push(hashMap[id]);
        while(!stk.empty()){
            eTemp = stk.top();
            stk.pop();
            totalImp += eTemp->importance;
            for(auto &i : eTemp->subordinates)
                stk.push(hashMap[i]);
        }
        
        return totalImp;
    }
};
