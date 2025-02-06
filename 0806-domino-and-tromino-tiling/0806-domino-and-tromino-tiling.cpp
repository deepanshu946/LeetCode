class Solution {
public:
    #define mod 1000000007
    int numTilings(int n) {
        vector<int> temp(n+10,0);
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(n==3){
            return 5;
        }
        int prev1=1;
        int prev2=2;
        int prev3=5;
        for(int i=4 ; i<=n; i++){
            int temp=(((2*prev3)%mod)+prev1)%mod;
            prev1=prev2;
            prev2=prev3;
            prev3=temp;
        }
        return prev3 % mod;
    }
};