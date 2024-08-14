class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> arr(n,vector<int>(n,1)),up,dn,l,r;
        for(auto it:mines) arr[it[0]][it[1]]=0;
        dn=l=r=up=arr;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++) if(arr[i][j]!=0) up[i][j]+=up[i-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++) if(arr[i][j]!=0) dn[i][j]+=dn[i+1][j];
        }
        for(int j=1;j<n;j++){
            for(int i=0;i<n;i++) if(arr[i][j]!=0) r[i][j]+=r[i][j-1];
        }
        for(int j=n-2;j>=0;j--){
            for(int i=0;i<n;i++) if(arr[i][j]!=0) l[i][j]+=l[i][j+1];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) ans=max(ans,min({up[i][j],dn[i][j],l[i][j],r[i][j]}));
        }
        return ans;
    }
};
