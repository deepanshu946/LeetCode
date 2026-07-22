class Solution {
private:
void solve(vector<vector<int>> &graph , vector<int> &temp , vector<vector<int>> &ans){
    if(temp.back()==graph.size()-1){
        ans.push_back(temp);
    }
    for(auto i:graph[temp.back()]){
        temp.push_back(i);
        solve(graph,temp,ans);
        temp.pop_back();
    }
}
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = graph.size()-1;

        // unordered_map<int,vector<int>> m;
        // for(int i=0 ; i<graph.size() ; i++){
        //     m[graph[i][0]].push_back(graph[i][1]);
        // }
        temp.push_back(0);
        solve(graph,temp,ans);
        return ans;
    }
};