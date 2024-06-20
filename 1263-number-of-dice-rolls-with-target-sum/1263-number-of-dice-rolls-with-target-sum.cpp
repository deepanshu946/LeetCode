class Solution {
#define mod 1000000007
private:
int solve(int n , int k , int target){
    // vector<vector<int>> dp(n+1 , vector<int>(target+1,0));
    vector<int> curr(target+1,0);
    vector<int> prev(target+1 , 0);
    prev[0]=1;

    for(int dice = 1 ; dice<=n ; dice++){
        for(int sum = 1 ; sum <=target ; sum++ ){
            int ans=0 ;
            for(int i=1 ; i<=k ; i++){
                if(sum-i>=0){
                    ans = (ans%mod+prev[sum-i]%mod)%mod;
                }
            }
            curr[sum]=ans%mod;
        }
        prev = curr;
    }
    return curr[target];


    

}
public:
    int numRollsToTarget(int n, int k, int target) {
        return solve(n,k,target);
    }
};