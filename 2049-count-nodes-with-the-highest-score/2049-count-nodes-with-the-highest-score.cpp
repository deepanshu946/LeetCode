class Solution {
private:
int solve(int curr ,unordered_map<int,vector<int>> &m , vector<int> &sizes , int n){
    if(m.find(curr)==m.end()){
        sizes[curr]=1;
        return 1;
    }
    int ans =0;
    for(int i=0 ; i<m[curr].size() ; i++){
        int node = m[curr][i];
        ans += solve(node , m , sizes ,n);
    }
    sizes[curr]=1+ans;
    return sizes[curr];
}

public:
    int countHighestScoreNodes(vector<int>& parents) {
        unordered_map<int,vector<int>> m;
        for(int i=0 ; i<parents.size() ; i++){
            if(parents[i] != -1){
                m[parents[i]].push_back(i);
            }
        }
        vector<int> sizes(parents.size(),0);

        solve(0,m,sizes,parents.size());
        // for(int i=0 ; i<sizes.size() ; i++){
        //     cout<<sizes[i]<<" ";
        // }
        int ans = 0;
        long long maxi = 0;
        // return 0;
        long long temp=1;
        unordered_map<long long,int> count;
        for(int i=0 ; i<sizes.size() ; i++){
            if(parents[i] != -1){
                temp = temp* (sizes[0]-sizes[i]);
            }
            for(int j=0 ; j<m[i].size() ; j++){
                temp = temp * sizes[m[i][j]];
            }
            // cout<<temp<<endl;
            maxi = max(maxi,temp);
            count[temp]++;
            temp=1;
        }
        
        return count[maxi];



    }
};