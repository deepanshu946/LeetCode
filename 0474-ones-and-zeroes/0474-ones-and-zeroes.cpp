class Solution {
private:
int dp[602][200][200];
int solve(int index , unordered_map<int,pair<int,int>> &map ,int ones , int zeros, int m , int n , int size){
    if(zeros>m || ones>n){
        return INT_MIN;
    }
    if(index==-1 ){
        return 0;
    }
    if(dp[index][ones][zeros] !=-1){
        return dp[index][ones][zeros];
    }
    int inc = 1+solve(index-1,map,ones+map[index].first,zeros+map[index].second , m , n , size);
    int exc = solve(index-1,map,ones,zeros,m,n,size);
    return dp[index][ones][zeros]= max(inc,exc);
}
public:

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        unordered_map<int,pair<int,int>> map;
        for(int i=0 ; i<strs.size() ; i++){
            string s = strs[i];
            int ones=0;
            int zeros=0;
            for(int j=0 ; j<s.length() ; j++){
                if(s[j]=='1'){
                    ones++;
                }
                else{
                    zeros++;
                }
            }
            cout<<ones<<" "<<zeros<<endl;
            map[i]={ones,zeros};
        }
        return solve(strs.size()-1,map,0,0,m,n,strs.size());
    }
};