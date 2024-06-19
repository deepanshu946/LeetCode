class Solution {
private:
int checkopen(string temp){
    int count = 0;
    for(int i=0 ; i<temp.size() ; i++){
        if(temp[i]=='(' ){
            count++;
        }
    }
    return count;
}
int checkclose(string temp){
    int count = 0;
    for(int i=0 ; i<temp.size() ; i++){
        if(temp[i]==')' ){
            count++;
        }
    }
    return count;
}
bool valid(string temp){
    stack<char> s;
    for(int i=0 ; i<temp.size() ; i++){
        if(temp[i]=='('){
            s.push('(');
        }
        else{
            if(s.empty()){
                return false;
            }
            s.pop();
        }
    }
    if(s.size()>0){
        return false;
    }
    return true;
}
void solve(int n,string temp , vector<string> &ans){
    if(checkopen(temp)>n || checkclose(temp)>n){
        return;
    }
    if(checkopen(temp)==n && checkclose(temp)==n && valid(temp)){
        ans.push_back(temp);
        return;
    }
    temp = temp+'(';
    solve(n,temp,ans);
    temp.pop_back();
    temp = temp+')';
    solve(n,temp,ans);
    temp.pop_back();
}
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(n,temp , ans);
        return ans;
    }
};