class Solution {
private:
int solve(string &a , string &b){
    vector<vector<int>> dp(a.length()+1 , vector<int> (b.length()+1 , 0));
    //fill base case
    for(int i=0 ; i<=b.length() ; i++){
        dp[a.length()][i]=b.length()-i;
    }
    for(int i=0 ; i<=a.length() ; i++){
        dp[i][b.length()]=a.length()-i;
    }
    for(int i=a.length()-1 ; i>=0 ; i--){
        for(int j=b.length()-1 ; j>=0 ; j--){
            if(a[i]==b[j]){
                dp[i][j]= dp[i+1][j+1];
            }
            else{
                int ins = 1+dp[i][j+1];
                int del = 1+dp[i+1][j];
                int rep= 1+dp[i+1][j+1];
                dp[i][j]= min(ins,min(del,rep));
            }
        }
    }
    return dp[0][0];
}
public:
    int minDistance(string word1, string word2) {
        return solve(word1,word2);
    }
};



//recursion
// int solve(string &a , string &b , int i , int j){
//     if(i==a.length()){
//         return b.length()-j;
//     }
//     if(j==b.length()){
//         return a.length()-i;
//     }
//     if(a[i]==b[j]){
//         return solve(a,b,i+1,j+1);
//     }
//     else{
//         int ins = 1+solve(a,b,i,j+1);
//         int del = 1+solve(a,b,i+1,j);
//         int rep= 1+solve(a,b,i+1,j+1);
//         return min(ins,min(del,rep));
//     }
// }