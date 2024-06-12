class Solution {
private:
bool checkprime(int n){
    for(int i=2 ; i<=n/2 ; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> notprime(n,0);
        for(int i=2 ; i<n ; i++){
            if(notprime[i]==0){
                ans++;
                int temp =1;
                for(int j=i*temp ; j<n ; temp++){
                    notprime[j]=1;
                    j=i*temp;
                }
            }
        }
        return ans;
    }
};