class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_set<int> vis;
        queue<int> pq;
        pq.push(x);
        vis.insert(x);
        int level = 0;
        while(!pq.empty()){
            int size = pq.size();
            for(int i=0 ; i<size ; i++){
                int top = pq.front();
                pq.pop();
                if(top==y){
                    return level;
                }
                if(top%11==0 && vis.find(top/11)==vis.end()){
                    vis.insert(top/11);
                    pq.push(top/11);
                }
                if(top%5==0 && vis.find(top/5)==vis.end()){
                    vis.insert(top/5);
                    pq.push(top/5);
                }
                if(top+1<1e4 && vis.find(top+1)==vis.end()){
                    vis.insert(top+1);
                    pq.push(top+1);
                }
                if(top-1>=0 && vis.find(top-1)==vis.end()){
                    vis.insert(top-1);
                    pq.push(top-1);
                }
            }
            level++;
        }
        return -1;
        
    }
};