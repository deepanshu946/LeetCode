#define mod 1000000007
class Solution {
private:
int solve(int w1 , int w2,int i , string word1 , string word2 , string target){
    
    if(i==target.length()){
        if(w1 != 0 && w2 != 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(w1==word1.length() && w2==word2.length()){
        return 0;
    }
    int ans = 0;
    for(int idx = w2 ; idx<word2.length() ; idx++){
        if(target[i]==word2[idx]){
            ans = ans + solve(w1,idx+1,i+1,word1,word2,target);
        }
    }
    for(int idx = w1; idx<word1.length() ; idx++){
        if(target[i]==word1[idx]){
            ans = ans + solve(idx+1,w2,i+1,word1,word2,target);
        }
    }
    return ans;

}
public:
    int interleaveCharacters(string word1, string word2, string target) {
        vector<vector<vector<int>>> dp(word1.length()+1 , vector<vector<int>>(word2.length()+1 , vector<int>(target.length()+1,0)));

        for(int w1=0 ; w1<=word1.length() ; w1++){
            for(int w2=0 ; w2<=word2.length() ; w2++){
                if(w1 != 0 && w2 != 0){
                    dp[w1][w2][target.length()]=1;
                }
            }
        }
        for(int i=target.length()-1 ; i>=0 ; i--){
            for(int w1=word1.length() ; w1>=0 ; w1--){
                for(int w2=word2.length() ; w2>=0 ; w2--){
                    int ans = 0;
                    for(int idx = word2.length()-1 ; idx>=w2 ; idx--){
                        if(target[i]==word2[idx]){
                            ans = (ans + dp[w1][idx+1][i+1] %mod)%mod;
                        }
                    }
                    for(int idx = word1.length()-1; idx>=w1 ; idx--){
                        if(target[i]==word1[idx]){
                            ans = (ans + dp[idx+1][w2][i+1]%mod)%mod;
                        }
                    }
                    
                    dp[w1][w2][i]=ans%mod;

                }
            }
        }
        return dp[0][0][0]%mod;



        // return solve(0,0,0,word1,word2,target);
    }
};