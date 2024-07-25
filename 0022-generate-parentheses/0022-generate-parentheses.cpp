class Solution {
private:
void solve(int n,string temp , vector<string> &ans , int open , int close){
    if(close>open || close>n || open>n ){
        return;
    }
    if(open==close && open==n && close==n){
        ans.push_back(temp);
        return;
    }
    temp = temp+'(';
    solve(n,temp,ans,open+1,close);
    temp.pop_back();
    temp = temp+')';
    solve(n,temp,ans,open,close+1);
    temp.pop_back();
}
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(n,temp , ans , 0 , 0);
        return ans;
    }
};