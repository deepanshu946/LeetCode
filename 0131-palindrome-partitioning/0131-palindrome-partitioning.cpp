class Solution {
    
private:
bool check(string str){
    int i=0 ;
    int j=str.length()-1;
    while(i<=j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(int start ,string s, vector<string> &temp, vector<vector<string>> &ans){
    if(start>=s.length()){
        // string subs = s.substr(start,1);
        // if(subs.size() != 0 && check(subs)){
        //     temp.push_back(subs);
        //     ans.push_back(temp);
        //     temp.pop_back();
        // }
        // if(subs.size()==0){
            ans.push_back(temp);
        // }
        // temp.clear();
        return;
    }
    for(int i=start ; i<s.length() ; i++){
        string subs = s.substr(start,i-start+1);
        if(check(subs)){
            temp.push_back(subs);
            solve(i+1,s,temp,ans);
            temp.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,temp,ans);
        return ans;
    }
};