class Solution { 
private:
int solve(vector<int> &s , int n){
    // vector<vector<int>> dp(n+1,vector<int>(n+2,0));
    vector<int> nexttime(n+1,0);
    vector<int> currtime(n+1,0);
    vector<int> currindex(n+2,0);
    vector<int> nextindex(n+2,0);

    
    for(int index = n-1 ; index>=0 ; index--){
        for(int time = n ; time>=1 ; time--){
            int inc = s[index]*(time) + nextindex[time+1];
            int exc = nextindex[time];
            currindex[time]=max(inc,exc);
        }
        nextindex=currindex;
    }
    return nextindex[1];
}
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin() , satisfaction.end());
        return solve(satisfaction,n);
    }
};