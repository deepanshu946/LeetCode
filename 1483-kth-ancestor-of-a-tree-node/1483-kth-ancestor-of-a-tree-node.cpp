class TreeAncestor {
public:
    vector<vector<int>> dp;
    int cols;
    int rows;
    TreeAncestor(int n, vector<int>& parent) {
         rows = n;
         cols = log2(n)+1;
        dp.resize(rows,vector<int>(cols,-1));
        for(int i=0 ; i<n ; i++){
            dp[i][0] = parent[i];
        }
        for(int j=1 ; j<cols ; j++){
            for(int i=0 ; i<n ; i++){
                if(dp[i][j-1] != -1){
                    dp[i][j] = dp[dp[i][j-1]][j-1];
                }
            }
        }

    }
    
    int getKthAncestor(int node, int k) {
        for(int j=0 ; j<cols; j++){
            if(k&(1<<j)){
                node = dp[node][j];
            }
            if(node == -1){
                return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */