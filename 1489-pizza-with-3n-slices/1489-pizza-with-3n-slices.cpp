class Solution {
private:
int solve(vector<int> &slices){
    int size = slices.size();
    vector<vector<int>> dp1(size+2 , vector<int>((size/3)+1 , 0));
    vector<vector<int>> dp2(size+2 , vector<int>((size/3)+1 , 0));
    //for case    0 to k-2
    for(int index = size-2 ; index>=0 ; index--){
        for(int n = 1 ; n<=size/3 ; n++){
            int inc = slices[index]+dp1[index+2][n-1];
            int exc = dp1[index+1][n];
            dp1[index][n]= max(inc,exc);
        }
    }
    //for case   1 to k-1
    for(int index = size-1 ; index>=1; index--){
        for(int n = 1 ; n<=size/3 ; n++){
            int inc = slices[index]+dp2[index+2][n-1];
            int exc = dp2[index+1][n];
            dp2[index][n]= max(inc,exc);
        }
    }
    int ans1 = dp1[0][size/3];
    int ans2 = dp2[1][size/3];
    return max(ans1,ans2);

}
public:

    int maxSizeSlices(vector<int>& slices) {
        // int size = slices.size();
        // int n = size/3;
        // vector<vector<int>> dp1(size,vector<int>(n+1,-1));
        // int case1=solve(slices,1,size-1,n,dp1);
        // vector<vector<int>> dp2(size,vector<int>(n+1,-1));
        // int case2=solve(slices,0,size-2,n,dp2);
        // return max(case1,case2);
        return solve(slices);
    }
};