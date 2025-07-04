class Solution {
private:
static bool comp(string &s1 , string &s2){
    return s1.size()<s2.size();
}
bool compare(string &s1, string &s2){
    if(s1.size() - s2.size() != 1){
        return false;
    }
    int diff = 0;
    int p=0;
    int q=0;
    while(p<s1.length()){
        if(q>=s2.length() || s1[p] != s2[q]){
            p++;
            diff++;
        }
        else{
            p++;
            q++;

        }
        if(diff>1){
            break;
        }
    }
    if(diff>1){
        return false;
    }
    else if(diff==1){
       return true;
    }
    return false;
}
int solve(vector<string> &nums , int n){
    // vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
    vector<int> nextrow(n+1 , 0);
    vector<int> currrow(n+1,0);
    // if(curr==n){
    //     return 0;
    // }
    // if(dp[curr][prev+1] !=-1){
    //     return dp[curr][prev+1];
    // }
    for(int curr = n-1 ; curr>=0 ; curr--){
        for(int prev = n-1 ; prev>=-1 ; prev--){
            int inc =0;
            int exc=0;
            if(prev == -1 || compare(nums[curr],nums[prev])){
                inc = 1+nextrow[curr+1];
            }
            exc = nextrow[prev+1];
            currrow[prev+1]=max(inc,exc);
            // return dp[curr][prev];
        }
        nextrow = currrow;
    }
    return nextrow[0];
}
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
         return solve(words,words.size());
    }
};