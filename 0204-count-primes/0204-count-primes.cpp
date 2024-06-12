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
               for (int j = 2 * i; j < n; j += i) {
                    notprime[j] = true;
                }
            }
        }
        return ans;
    }
};