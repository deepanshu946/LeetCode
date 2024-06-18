class Solution {

public:
static bool comp(vector<int> &a , vector<int> &b){
    if(a[0] == b[0]){
        return a[1]>b[1];
    }
    return a[0]<b[0];
}
    int maxEnvelopes(vector<vector<int>>& en) {
        int n = en.size();
        sort(en.begin() , en.end() , comp);
        vector<int> ans;
        ans.push_back(en[0][1]);
        for(int i=1;i<n;i++){
            int height=en[i][1];
            if(height > ans.back()){
                ans.push_back(height);
            }
            else{
            int index=lower_bound(ans.begin(),ans.end(),height) - ans.begin() ;
            ans[index]=height;
            }
        }
        return ans.size();

    }
};