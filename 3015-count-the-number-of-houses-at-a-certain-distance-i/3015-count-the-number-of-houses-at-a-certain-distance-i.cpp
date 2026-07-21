class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n,0);
        x--;
        y--;

        for(int i=0 ; i<n ; i++){
            queue<int> q;
            int level = 0;
            vector<int> vis(n+1,0);
            q.push(i);
            vis[i]=1;
            // cout<<"index"<<endl;
            // cout<<i<<endl;÷
            while(!q.empty()){
                int size = q.size();
                for(int j=0 ; j<size ; j++){
                    int top = q.front();
                    q.pop();
                    if(level>0){
                        // cout<<level<<endl;
                        ans[level-1]++;
                    }
                    if(top+1<n && !vis[top+1]){
                        vis[top+1]=1;
                        q.push(top+1);
                    }
                    if(top-1>=0 && !vis[top-1]){
                        vis[top-1]=1;
                        q.push(top-1);
                    }
                    if(top==x && !vis[y]){
                        vis[y]=1;
                        q.push(y);
                    }
                    if(top==y && !vis[x]){
                        vis[x]=1;
                        q.push(x);
                    }

                }
                level++;
            }

        }
        return ans;

    }
};