/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,int> imp;
        for(int i=0 ; i<employees.size() ; i++){
            imp[employees[i]->id]=employees[i]->importance;
        }
        unordered_map<int,vector<int>> sub;
        for(int i=0 ; i<employees.size() ; i++){
            sub[employees[i]->id]=employees[i]->subordinates;
        }
        queue<int> q;
        q.push(id);
        int ans = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans = ans + imp[top];
            vector<int> temp = sub[top];
            for(int i=0 ; i<temp.size() ; i++){
                q.push(temp[i]);
            }
        }
        return ans;
    }
};