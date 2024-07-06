class Solution {
private:
bool solve(string word , int index , unordered_set<string> &s,vector<int> &dp){
    if(index==word.length()){
        return true;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    bool ans = 0;
    string temp="";
    for(int i=index ; i<word.length() ; i++){
        temp = temp+word[i];
        if(s.find(temp) != s.end()){
            ans = ans || solve(word,i+1,s,dp);
        }
    }
    return dp[index]= ans;

}
public:
    bool wordBreak(string word, vector<string>& wordDict) {
        unordered_set<string> s;
        s.insert(wordDict.begin(),wordDict.end());
        vector<int> dp(word.length()+1 , -1);
        return solve(word,0,s,dp);
    }
};