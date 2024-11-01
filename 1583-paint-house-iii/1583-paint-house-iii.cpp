class Solution {
private:
int solve(int index , int count ,int prev,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target , vector<vector<vector<int>>> &dp){
    if(index>=houses.size()){
        if(count==target){
            return 0;
        }
        else{
            return 1e9;
        }
    }
    if(count>target){
        return 1e9;
    }
    if(dp[index][count][prev] != -1){
        return dp[index][count][prev];
    }
    int ans=1e9;
    if(houses[index] != 0){
        if( prev==houses[index]){
            ans = solve(index+1,count , houses[index],houses,cost,m,n,target,dp);
        }
        else{
            ans = solve(index+1,count+1,houses[index],houses,cost,m,n,target,dp);
            
        }
    }
    else{
        for(int j=0 ; j<n ; j++){
            if(prev==j+1){
                ans = min(ans , cost[index][j] + solve(index+1,count , j+1,houses,cost,m,n,target,dp));
            }
            else{
                ans = min(ans , cost[index][j] + solve(index+1,count+1 , j+1,houses,cost,m,n,target,dp));
            }
            
        }

    }
    return dp[index][count][prev]= ans;
}
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(target+1,vector<int>(n+1,-1)));
        int ans = solve(0,0,0,houses,cost,m,n,target,dp);

        if(ans ==1e9){
            return -1;
        }
        return ans;
    }

};