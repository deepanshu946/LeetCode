class Solution {
public:
    int minMoves(vector<string>& nums) {
        int n = nums.size();
        int nn = nums[0].size();
        unordered_map<char,vector<pair<int,int>>> m;
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=0 ; j<nums[0].size() ; j++){
                if(nums[i][j] != '.' && nums[i][j] != '#'){
                    m[nums[i][j]].push_back({i,j});
                }
            }
        }
        queue<pair<int,int>> q;
        int ans = -1;
        unordered_set<char> s;
        vector<vector<int>> vis(n,vector<int>(nn,0));
        vis[0][0]=1;
        q.push({0,0});
        if(m.find(nums[0][0]) != m.end() && s.find(nums[0][0]) == s.end()){
            s.insert(nums[0][0]);
            for(auto j:m[nums[0][0]]){
                if( make_pair(0,0) != j && !vis[j.first][j.second]){
                    q.push(j);
                    vis[j.first][j.second]=1;
                }
            }
        }
        bool flag = 0;
        while(!q.empty()){
            int si = q.size();
            for(int i=0 ; i<si ; i++){
                pair<int,int> temp = q.front();
                q.pop();
                int row = temp.first;
                int col = temp.second;
                if(row==n-1 && col==nn-1){
                    while(!q.empty()){
                        q.pop();
                    }
                    flag=1;
                    break;
                }
                if(row+1<n && !vis[row+1][col] && nums[row+1][col] != '#'){
                    vis[row+1][col]=1;
                    q.push({row+1,col});
                    if(m.find(nums[row+1][col]) != m.end() && s.find(nums[row+1][col]) == s.end()){
                        s.insert(nums[row+1][col]);
                        for(auto j:m[nums[row+1][col]]){
                            if( make_pair(row+1,col) != j && !vis[j.first][j.second]){
                                q.push(j);
                                vis[j.first][j.second]=1;
                            }
                        }
                    }
                }
                if(col+1<nn && !vis[row][col+1]  && nums[row][col+1] != '#'){
                    vis[row][col+1]=1;
                    // cout<<"here"<<endl;
                    q.push({row,col+1});
                    if(m.find(nums[row][col+1]) != m.end() && s.find(nums[row][col+1]) == s.end()){
                        s.insert(nums[row][col+1]);
                        for(auto j:m[nums[row][col+1]]){
                            if( make_pair(row,col+1) != j && !vis[j.first][j.second]){
                                q.push(j);
                                // cout<<j.first<<" "<<j.second<<endl;
                                vis[j.first][j.second]=1;
                            }
                        }
                    }
                }
                if(row-1>=0 && !vis[row-1][col]  && nums[row-1][col] != '#'){
                    vis[row-1][col]=1;
                    q.push({row-1,col});
                    if(m.find(nums[row-1][col]) != m.end() && s.find(nums[row-1][col]) == s.end()){
                        s.insert(nums[row-1][col]);
                        for(auto j:m[nums[row-1][col]]){
                            if( make_pair(row-1,col) != j && !vis[j.first][j.second]){
                                q.push(j);
                                vis[j.first][j.second]=1;
                            }
                        }
                    }
                }
                if(col-1>=0 && !vis[row][col-1]  && nums[row][col-1] != '#'){
                    vis[row][col-1]=1;
                    q.push({row,col-1});
                    if(m.find(nums[row][col-1]) != m.end() && s.find(nums[row][col-1]) == s.end()){
                        s.insert(nums[row][col-1]);
                        for(auto j:m[nums[row][col-1]]){
                            if( make_pair(row,col-1) != j && !vis[j.first][j.second]){
                                q.push(j);
                                vis[j.first][j.second]=1;
                            }
                        }
                    }
                }
                // if(nums[row][col] != '.' && nums[row][col] != '#'){
                //     if(s.find(nums[row][col]) == s.end()){
                //         s.insert(nums[row][col]);
                //         for(auto j:m[nums[row][col]]){
                //             if( make_pair(row,col) != j && !vis[j.first][j.second]){
                //                 q.push(j);
                //                 vis[j.first][j.second]=1;
                //             }
                //         }
                //     }
                // }
            }
            ans++;
            
            
        }
        if(!flag){
            return -1;
        }
        return ans;
    }
};