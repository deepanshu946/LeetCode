class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<pair<int,int>> temp;
        for(int i=0 ; i<nums.size() ; i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        vector<bool> vis(n,0);
        for(int i=0 ; i<n ; i++){
            pair<int,int> curr = temp[i];
            if(!vis[curr.second]){
                ans = ans + curr.first;
                if(curr.second-1 >=0 ){
                    vis[curr.second-1]=1;
                }
                if(curr.second + 1 < n){
                    vis[curr.second+1]=1;
                }
            }
        }
        return ans;
    }
};