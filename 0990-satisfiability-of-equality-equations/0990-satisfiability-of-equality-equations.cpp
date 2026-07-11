class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int x , int y){
        
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent==y_parent){
            return ;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
        
        
        
        
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.assign(26,0);
        for(int i=0 ; i<26 ; i++){
            parent[i]=i;
        }
        for(int i=0 ; i<equations.size() ; i++){
            int first = equations[i][0]-'a';
            int second = equations[i][3]-'a';
            if(equations[i][1]=='='){
                Union(first,second);
            }
            


        }
        for(int i=0 ; i<equations.size() ; i++){
            int first = equations[i][0]-'a';
            int second = equations[i][3]-'a';
            if(equations[i][1]=='!'){
                if(find(first)==find(second)){
                    return false;
                }
            }
            


        }
        
        return true;
    }
};