class Solution {
private:
    void dfs(int t, vector<bool>& sus, vector<bool>& vis, const vector<vector<int>>& al){
        vis[t] = true;
        sus[t] = true;

        for(int x : al[t]){
            if(vis[x]) continue;
            dfs(x, sus, vis, al);
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& a) {
        vector<bool> sus(n);
        bool ok = true;

        vector<vector<int>> al(n);
        
        int m = a.size();
        for(int i = 0; i < m; ++i) al[a[i][0]].push_back(a[i][1]);

        vector<bool> vis(n);
        dfs(k, sus, vis, al);

        vector<int> defRet(n);
        for(int i = 0; i < n; ++i) defRet[i] = i;

        for(int i = 0; i < n; ++i){
            if(sus[i]) continue;

            for(int x : al[i]){
                if(sus[x]) return defRet;
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