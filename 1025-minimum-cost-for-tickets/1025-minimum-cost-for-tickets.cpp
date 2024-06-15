class Solution {
private:
int solve(vector<int>& days, vector<int>& costs,int index , int n,vector<int> &dp){
    //tc of emmoization is O(1) because we can store a max of 365+1 element in a dp array 
    if(index>=n){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int day1 = costs[0]+solve(days,costs,index+1,n,dp);
    int i;
    for(i=index ; i<n && days[i]<days[index]+7;i++);
    int day7 = costs[1] + solve(days,costs,i,n,dp);
    int j;
    for(j=index ; j<n&&days[j]<days[index]+30 ; j++);
    int day30 = costs[2]+solve(days,costs,j,n,dp);
    dp[index]= min(day1,min(day7,day30));
    return dp[index];
}

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(366,-1);
        return solve(days,costs,0,n,dp);
    }
};