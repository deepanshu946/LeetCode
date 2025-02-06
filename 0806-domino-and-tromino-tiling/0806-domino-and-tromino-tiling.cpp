class Solution {
public:
    #define mod 1000000007
    int numTilings(int n) {
        vector<int> temp(n+10,0);
        
        temp[1]=1;
        temp[2]=2;
        temp[3]=5;
        if(n<=3){
            return temp[n];
        }
        for(int i=4 ; i<=n; i++){
            temp[i]=(((2*temp[i-1])%mod)+temp[i-3])%mod;
        }
        return temp[n] % mod;
    }
};