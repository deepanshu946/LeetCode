class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int mx = mat.size();
        int n = mat[0].size();

        vector<int> temp(mx+n,0);
        unordered_map<int,pair<int,int>> m;
        for(int i=0 ; i<mat.size() ; i++){
            for(int j=0 ; j<mat[0].size() ; j++){
                m[mat[i][j]]={i,j};
            }
        }
        for(int i=0 ; i<arr.size() ; i++){
            int row = m[arr[i]].first;
            int col = m[arr[i]].second;
            temp[row]++;
            temp[mat.size()+col]++;
            if(temp[row]==mat[0].size()){
                return i;
            }
            if(temp[mat.size()+col]==mat.size()){
                return i;
            }

        }
        return 0;
        
    }
};