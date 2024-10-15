class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int m = image.size();
        int n = image[0].size();
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int temp = image[p.first][p.second];
            if(temp != color){
            if(p.first+1<m &&  image[p.first+1][p.second] == temp){
                q.push({p.first+1,p.second});
            }
            if(p.second+1<n && image[p.first][p.second+1] == temp){
                q.push({p.first,p.second+1});
            }
            if(p.first-1>=0 && image[p.first-1][p.second] == temp){
                q.push({p.first-1,p.second});
            }
            if(p.second-1>=0 && image[p.first][p.second-1] == temp){
                q.push({p.first,p.second-1});
            }
            }
            
            image[p.first][p.second]=color;

        }
        return image;
    }
};