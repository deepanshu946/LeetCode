class Solution {
private:
// unordered_map<vector<int>,int> m;
bool present(vector<vector<int>> &ans , vector<int> &temp){
    if(ans.size()==0){
        return false;
    }
    for(int i=0 ; i<ans.size() ; i++){
        if(ans[i]==temp){
            return true;
        }
    }
    return false;
}

void solve(vector<int>& candidates, int target ,int index , vector<vector<int>> &ans , vector<int> &temp){
    if(target<0){
        return;
    }
    if(target==0){
        // if(!present(ans,temp)){
            ans.push_back(temp);
        // }
        return;
    }
    for(int i=index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1] ){
            continue;
        }
        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],i+1,ans,temp);
        temp.pop_back();
    }

}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,ans,temp);

        return ans;

    }
};