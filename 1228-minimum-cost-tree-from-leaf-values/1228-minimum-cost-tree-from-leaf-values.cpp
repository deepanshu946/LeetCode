class Solution {
private:
int solve(vector<int> &arr , map<pair<int,int>,int> m){
    vector<vector<int>> dp(arr.size()+1 , vector<int> (arr.size()+1 , 0));
    // if(left==right ){
    //     return 0;
    // }
    for(int left = arr.size()-1 ; left>=0 ; left--){
        for(int right = 0 ; right<arr.size(); right++){
            if(left==right){
                continue;
            }
            int ans = INT_MAX;
            for(int k=left ; k<right ; k++){
                ans = min(ans , m[{left,k}]*m[{k+1,right}] + dp[left][k]+dp[k+1][right]);
            }
            dp[left][right]=ans;
        }
    }
    return dp[0][arr.size()-1];
}
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int,int> , int> m;
        for(int i=0 ; i<n ; i++){
            m[{i,i}]=arr[i];
            for(int j=i+1 ; j<n ; j++){
                m[{i,j}]=max(arr[j],m[{i,j-1}]);
            }
        }
        return solve(arr,m);
    }
};