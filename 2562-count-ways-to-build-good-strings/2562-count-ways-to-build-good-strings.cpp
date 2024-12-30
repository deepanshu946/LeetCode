class Solution {
private:
#define mod 1000000007
 int solve(int low , int high , int zero , int one , int len,unordered_map<int,int> &m){
    if(len > high){
        return 0;
    }
    if(m.find(len) != m.end()){
        return m[len];
    }
    long long ans = 0;
    if(len >= low && len <= high){
        ans++;
    }
    ans = ans + solve(low,high,zero,one,len+zero,m);
    ans = ans + solve(low,high,zero,one,len+one,m);
    return m[len]=ans%mod;


 }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        unordered_map<int,int> m;
        return solve(low,high,zero,one,0,m);
    }
};