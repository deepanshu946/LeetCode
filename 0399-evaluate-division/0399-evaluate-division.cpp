class Solution {
private:
void dfs(string src , string dest , unordered_map<string,vector<pair<string,double>>> m ,unordered_set<string> &vis , double &ans , double prod){
    if(m.find(src) == m.end()){
        return;
    }
    if(src==dest){
        ans = prod;
        return;
    }
    vis.insert(src);
    for(auto &i:m[src]){
        if(vis.find(i.first)==vis.end()){
            dfs(i.first,dest,m,vis,ans,prod*i.second);
        }
    }

}
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> m;
        int n = values.size();
        for(int i=0 ; i<equations.size() ; i++){
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        vector<double> output;
        for(int i=0 ; i<queries.size() ; i++){
            // vector<bool> vis(n,0);
            unordered_set<string> vis;
            string src = queries[i][0];
            string dest = queries[i][1];
            double ans = -1.0;
            double prod = 1.0;
            dfs(src,dest,m,vis,ans,prod);
            output.push_back(ans);
        }
        return output;
    }
};