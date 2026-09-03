class Solution {
public:
// vector<int> parent;
// vector<int> rank;
// int find(int x){
//     if(x==parent[x]){
//         return x;
//     }
//     return parent[x]=find(parent[x]);
// }
// void Union(int x , int y){
    
//     int x_parent = find(x);
//     int y_parent = find(y);
//     if(x_parent==y_parent){
//         return ;
//     }
//     if(rank[x_parent]>rank[y_parent]){
//         parent[y_parent]=x_parent;
//     }
//     else if(rank[x_parent]<rank[y_parent]){
//         parent[x_parent]=y_parent;
//     }
//     else{
//         parent[x_parent]=y_parent;
//         rank[y_parent]++;
//     }
    
    
    
    
// }
    void dfs(char ch , char &finalch , vector<bool> &vis,unordered_map<char,vector<char>> &m ){
        if(m.find(ch) == m.end()){
            return;
        }
        finalch = min(finalch , ch);
        vis[ch-'a']=1;
        for(auto &i : m[ch]){
            if(!vis[i-'a']){
                dfs(i,finalch,vis,m);
            }
        }
        return;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,vector<char>> m;
        for(int i=0 ; i<s1.length() ; i++){
            m[s1[i]].push_back(s2[i]);
            m[s2[i]].push_back(s1[i]);
        }
        string ans = "";
        for(int i=0 ; i<baseStr.size() ; i++){
            if(m.find(baseStr[i]) != m.end()){
                char finalch = 'z';
                vector<bool> vis(27,0);
                dfs(baseStr[i],finalch,vis,m);
                ans.push_back(finalch);
            }
            else{
                ans.push_back(baseStr[i]);
            }
        }
        return ans;
    }
};