#define mod 1000000007
class Solution {
private:
int getgcd(int a , int b){

    if(b==0){
        return a;
    }
    while(b!=0){
        int temp = b;
        b=a%b;
        a=temp;
    }
    return a;
}
int solve(int i, int gcd1 , int gcd2, vector<int> &nums){
    
    if(i>= nums.size()){
        if(gcd1!=0 && gcd2!=0 && gcd1==gcd2){
        return 1;
        }
        return 0;
    }
    int newgcd1=getgcd(nums[i],gcd1);
    int take1 = solve(i+1,newgcd1,gcd2,nums);
    
    int newgcd2=getgcd(nums[i],gcd2);
    int take2 = solve(i+1,gcd1,newgcd2,nums);

    int leave = solve(i+1,gcd1,gcd2,nums);
    return take1+take2+leave;
    
}
public:
    int subsequencePairCount(vector<int>& nums) {
        int maxi = 0;
        for(int i=0 ; i<nums.size() ; i++){
            maxi = max(maxi , nums[i]);
        }
        vector<vector<vector<int>>> dp(maxi+1, vector<vector<int>>(maxi+1,vector<int>(nums.size()+1,0)));
        for(int gcd1=1; gcd1<=maxi ; gcd1++ ){
            for(int gcd2 = 1; gcd2<=maxi ; gcd2++){
                if(gcd1!=0 && gcd2!=0 && gcd1==gcd2){
                    dp[gcd1][gcd2][nums.size()]=1;
                }
            }
        }
        for(int i=nums.size()-1 ; i>=0 ; i--){
        for(int gcd1 = 0 ; gcd1<=maxi ; gcd1++){
            for(int gcd2 = 0 ; gcd2<=maxi ; gcd2++){
                    int newgcd1=getgcd(nums[i],gcd1);
                    int take1 = dp[newgcd1][gcd2][i+1] % mod;
                    
                    int newgcd2=getgcd(nums[i],gcd2);
                    int take2 = dp[gcd1][newgcd2][i+1] %mod;

                    int leave = dp[gcd1][gcd2][i+1] %mod;
                    dp[gcd1][gcd2][i] = ((take1+take2)%mod+leave)%mod;
                }
            }
        }
        return dp[0][0][0];



        // return solve(0,0,0,nums);
    }
};