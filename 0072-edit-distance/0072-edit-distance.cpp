class Solution {
private:
int solve(string &a , string &b){
    // vector<vector<int>> dp(a.length()+1 , vector<int> (b.length()+1 , 0));
    vector<int> prev(b.length()+1,0);
    vector<int> curr(b.length()+1,0);

    //fill base case
    for(int i=0 ; i<=b.length() ; i++){
        prev[i]=b.length()-i;
    }
    int k=1;
    curr[b.length()]=k;
    for(int i=a.length()-1 ; i>=0 ; i--){

        for(int j=b.length()-1 ; j>=0 ; j--){
            if(a[i]==b[j]){
                curr[j]= prev[j+1];
            }
            else{
                int ins = 1+curr[j+1];
                int del = 1+prev[j];
                int rep= 1+prev[j+1];
                curr[j]= min(ins,min(del,rep));
            }
        }
        k++;
        prev = curr;
        curr[b.length()]=k;
    }
    return prev[0];
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