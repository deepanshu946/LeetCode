class Solution {
private:
void traverse(int i ,unordered_map<int,vector<int>> m, vector<int> &vis){
    vis[i]=1;
    for(auto j : m[i]){
        if(!vis[j]){
            traverse(j,m,vis);
        }
    }
}
public:
    int findCircleNum(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> m;
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=0 ; j<nums[i].size() ; j++){
                if(nums[i][j]){
                    m[i].push_back(j);
                }
                
            }
        }
        int count = 0;
        vector<int> vis(nums.size(),0);
        for(int i=0 ; i<nums.size() ; i++){
            if(!vis[i]){
                count++;
                traverse(i,m,vis);
            }
        }
        return count;
    }
};