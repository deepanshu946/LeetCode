class Solution {
private:
int solve(vector<int>& days, vector<int>& costs,int index , int n){
    vector<int> dp(n+1 , INT_MAX);
    dp[n]=0;
    // if(index>=n){
    //     return 0;
    // }
    // if(dp[index] != -1){
    //     return dp[index];
    // }
    for(int k=n-1 ; k>=0 ; k--){
    int day1 = costs[0]+dp[k+1];
    int i;
    for(i=k ; i<n && days[i]<days[k]+7;i++);
    int day7 = costs[1] + dp[i];
    int j;
    for(j=k ; j<n&&days[j]<days[k]+30 ; j++);
    int day30 = costs[2]+dp[j];
    dp[k]= min(day1,min(day7,day30));
    }
    return dp[0];
}

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n,-1);
        return solve(days,costs,0,n);
    }
};