class Solution {
private:
void solve(int n , int k , vector<int> &temp , vector<vector<int>> &ans , int start){
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }
    for(int i=start ; i<=n ; i++){
        temp.push_back(i);
        solve(n,k,temp,ans,i+1);
        temp.pop_back();
    }
}
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
         solve(n , k , temp , ans , 1);
         return ans;
    }
};