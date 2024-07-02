class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> m;
        int n = grid.size();
        for(int i=0 ; i<n ; i++){
            m[grid[i]]++;
        }
        int ans = 0;
        for(int j=0 ; j<n ; j++){
            vector<int> temp;
            for(int i=0 ; i<n ; i++){
                temp.push_back(grid[i][j]);
            }
            if(m.find(temp) != m.end()){
                ans=ans+m[temp];
                // m[temp]--;
            }
        }
        return ans;
    }
};