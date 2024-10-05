class Solution 
{
private:
#define mod 1000000007
// int solve(int n , int val , vector<int>& group, vector<int>& profit , int curr , int index , int size){
//     if(n<0){
//         return 0;
//     }
//     if(index==size){
//         if(curr>=val){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     int inc = solve(n-group[index],val,group,profit,curr+profit[index],index+1,size);
//     int exc = solve(n,val,group,profit,curr,index+1,size);
//     return inc + exc;

// }
public:
    int profitableSchemes(int n, int val, vector<int>& group, vector<int>& profit) {
        // return solve(n,minProfit,group,profit,0,0,group.size());
        int size = group.size();
        vector<vector<vector<int>>> dp(101,vector<vector<int>>(101,vector<int>(101,0)));
        for(int i=0 ; i<=n ; i++){
            dp[size][i][val]=1;
        }
        for(int index = size-1 ; index>=0 ; index--){
            for(int i=0 ; i<=n ; i++){
                for(int curr=val ; curr>=0 ; curr--){
                    int inc = 0;
                    if(i-group[index] >= 0){
                        int temp = curr+profit[index];
                        if(temp>val){
                            temp=val;
                        }
                        inc = (dp[index+1][i-group[index]][temp])%mod;
                    }
                    int exc = dp[index+1][i][curr] % mod;
                    dp[index][i][curr]= (inc + exc)%mod;
                }
            }
        }
        return dp[0][n][0] % mod;
    }
};