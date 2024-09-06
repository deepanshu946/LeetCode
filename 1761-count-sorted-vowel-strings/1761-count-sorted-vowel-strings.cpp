class Solution {
private:
int solve(int count , int prev , int n ){
    if(count==n){
        return 1;
    }
    int ans = 0;
    for(int i=prev ; i<5 ; i++){
        ans = ans + solve(count+1,i,n);
    }
    return ans;
}
public:
    int countVowelStrings(int n) {
        return solve(0,0,n);
    }
};