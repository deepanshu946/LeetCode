class Solution {
private:
void dfs(int k , vector<int> &sus , vector<int> &vis , unordered_map<int,vector<int>> &m){
    vis[k]=1;
    sus[k]=1;
    for(auto &adj : m[k]){
        if(!vis[adj]){
            dfs(adj,sus,vis,m);
        }
    }
    // vis[k]=0;
}
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& nums) {
        vector<int> sus(n,0);
        vector<int> vis(n,0);
        unordered_map<int,vector<int>> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i][0]].push_back(nums[i][1]);
        }
        dfs(k,sus,vis,m);
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            ans.push_back(i);
        }
        

        for(auto& i:m){
            if(sus[i.first]){
                // cout<<val<<endl;
                continue;
            }
            for(auto j:i.second){
                if(sus[j]){
                    
                    return ans;
                }
            }
        }
        
        vector<int> ret;
        for(int i = 0; i < n; ++i){
            if(sus[i]) continue;
            ret.push_back(i);
        }
        return ret;

    }
};