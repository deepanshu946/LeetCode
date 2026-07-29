class Solution {
private:
    // int solve(vector<int> &temp , int index , int count , int value , unordered_set<int> &ans ,  unordered_map<string,int> &dp){
    //     if(count==3){
    //         return value;
    //     }
    //     if(index>=temp.size()){
    //         return -1;
    //     }
    //     string key = to_string(index) + "," + to_string(count) + "," +to_string(value);
    //     if(dp.find(key) != dp.end()){
    //         return dp[key];
    //     }
    //     int inc = solve(temp,index+1,count+1,value^temp[index],ans,dp);
    //     if(inc != -1){
    //         ans.insert(inc);
    //     }
    //     int exc = solve(temp,index+1,count,value,ans,dp);
    //     if(exc != -1){
    //         ans.insert(exc);
    //     }
    //     return -1;

    // }
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> temp(s.begin(),s.end());
        unordered_set<int> ans;
        unordered_set<int> finl;
        for(int i=0 ; i<temp.size() ; i++){
            finl.insert(temp[i]);
        }
        // unordered_map<string,int> dp;
        // solve(temp,0,0,0,ans,dp);
        vector<vector<bool>> dp(4, vector<bool>(2048, false));
        dp[0][0] = true;

        for (int i=0 ; i<temp.size() ; i++ ) {
            for (int k = 0; k <3; k++) {
                for (int x = 0; x < 2048; x++) {
                    if (dp[k][x]) {
                        dp[k+1][x^temp[i]] = true;
                    }
                }
            }
        }
        
        // for (int x : nums) finl.insert(x);
        // for (int x : ans) finl.insert(x);
        for(int i=0 ; i<2048 ; i++){
            if(dp[3][i]){
                finl.insert(i);
            }
        }
        return finl.size();
    }
};