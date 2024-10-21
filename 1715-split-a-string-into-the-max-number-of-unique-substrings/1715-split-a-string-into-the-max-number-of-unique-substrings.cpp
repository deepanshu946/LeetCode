class Solution {
private:
int max(int a , int b){
    if(a>b){
        return a;
    }
    return b;
}

void solve(int i , string s , unordered_set<string> &m , int &ans){
    if(i>=s.length()){
        ans=max(ans,m.size());
        return;
    }
    string temp = "";
    for(int j=i ; j<s.length() ; j++){
        temp.push_back(s[j]);
        if(m.count(temp) == 0){
            m.insert(temp);
            solve(j+1,s,m,ans);
            m.erase(temp);
        }
    }

}
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> m;
        int ans = 0;
        solve(0,s,m,ans);
        return ans;
        
    }
};