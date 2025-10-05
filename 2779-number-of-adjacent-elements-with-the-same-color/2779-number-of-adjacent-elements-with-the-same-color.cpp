class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> temp(n,0);
        unordered_map<int,int> s;
        int pairs = 0;
        vector<int> ans(queries.size(),0);
        for(int i=0 ; i<queries.size() ; i++){
            int ind = queries[i][0];
            int col = queries[i][1];
            if(s.find(ind) == s.end()){
                temp[ind]=col;
                if(ind>0 && temp[ind-1] == temp[ind]){
                    pairs++;
                    s[ind]++;
                    s[ind-1]++;
                }
                if(ind < n-1 && temp[ind+1]==temp[ind]){
                    pairs++;
                    s[ind]++;
                    s[ind+1]++;
                }
            }
            else{
                if(col == temp[ind]){
                    ans[i]=pairs;
                    continue;
                }
                else{
                    s[ind]--;
                    if(ind+1<n && temp[ind+1] == temp[ind]){
                        s[ind+1]--;
                        pairs--;
                    }
                    if(ind-1>=0 && temp[ind-1]==temp[ind]){
                        s[ind-1]++;
                        pairs--;
                    }
                    temp[ind]=col;
                    if(ind>0 && temp[ind-1] == temp[ind]){
                    pairs++;
                    s[ind]++;
                    s[ind-1]++;
                    }
                    if(ind < n-1 && temp[ind+1]==temp[ind]){
                        pairs++;
                        s[ind]++;
                        s[ind+1]++;
                    }
                }
            }
            ans[i]=pairs;
        }
        return ans;
    }
};