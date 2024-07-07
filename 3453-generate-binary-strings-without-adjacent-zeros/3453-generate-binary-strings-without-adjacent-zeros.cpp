class Solution {
private:
void solve(int n , int prev , vector<string> &ans , string &temp){
    if(temp.size()>n){
        return;
    }
    if(temp.length() == n){
        ans.push_back(temp);
    }
    if(prev==0){
        //call for 1 only
        temp.push_back('1');
        solve(n,1,ans,temp);
        temp.pop_back();
    }
    else{
        temp.push_back('0');
        solve(n,0,ans,temp);
        temp.pop_back();
        temp.push_back('1');
        solve(n,1,ans,temp);
        temp.pop_back();
    }
}

public:
    vector<string> validStrings(int n) {

        vector<string> ans;
        string temp = "";
         solve(n,-1,ans,temp);
         return ans;
    }
};