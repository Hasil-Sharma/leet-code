// https://leetcode.com/problems/employee-importance/description/

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> hashMap;
        stack<int> stk;
        int ans = 0;
        for(auto emp : employees)
            hashMap[emp->id] = emp;
        
        stk.push(id);
        
        while(!stk.empty()){
            id = stk.top();
            stk.pop();
            ans += hashMap[id]->importance;
            for(int sub : hashMap[id]->subordinates)
                stk.push(sub);
        }
        
        return ans;
    }
};
