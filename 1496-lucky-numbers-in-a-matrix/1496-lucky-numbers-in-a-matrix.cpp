class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> s;
        for(int i=0 ; i<m ; i++){
            int mini=INT_MAX;
            for(int j=0 ;j<n ; j++ ){
                mini=min(mini,matrix[i][j]);
            }
            s.insert(mini);
        }
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            int maxi=INT_MIN;
            for(int j=0 ;j<m ; j++ ){
                maxi=max(maxi,matrix[j][i]);
            }
            if(s.find(maxi) != s.end()){
                ans.push_back(maxi);
            }
        }
        return ans;
    }
};