class Solution {
private:
void solve(vector<string> &ans , string temp , vector<string>& words , string s , string str){
    if(temp.length()>s.length() || s.contains(temp) == 0){
        return;
    }
    if(temp == s){
        str.pop_back();
        ans.push_back(str);
        return;
    }
    for(int i=0 ; i<words.size() ; i++){
        solve(ans , temp+words[i] , words ,s , str+words[i]+' ');
    }

}
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans ;
        solve(ans , "" , wordDict , s , "");
        return ans;
    }
};