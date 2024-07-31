class Solution {
private:
int getscore(int i , int j ,vector<vector<int>>& students, vector<vector<int>>& mentors){
    int ans = 0;
    for(int k=0 ; k<students[i].size() ; k++){  
        if(students[i][k]==mentors[j][k]){
            ans++;
    }
}
return ans;
}
unordered_set<int> s;
int solve(int i , vector<vector<int>>& students, vector<vector<int>>& mentors , int m){
    if(i>=m){
        return 0;
    }
    int ans = INT_MIN;
    for(int k=0 ; k<m ; k++){
        if(s.find(k) == s.end() ){
            s.insert(k);
            ans = max(ans , getscore(i,k,students,mentors)+solve(i+1,students,mentors,m));
            s.erase(k);
        }
    }
    return ans;
}
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        return solve(0,students,mentors,m);
    }
};