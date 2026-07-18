class Solution {
private:
// struct pair_hash{
//     size_t operator()(const pair<int,int>& p)const{
//         return hash<int>()(p.first)^(hash<int>()(p.second)<<1);
//     }
// };
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {


        
        int ans1=INT_MAX;
        for(int i=0 ; i<ghosts.size() ; i++){
            int dist = abs(ghosts[i][0]-target[0])+abs(ghosts[i][1]-target[1]);
            ans1= min(ans1 , dist);
        }
        int ans2 = abs(0-target[0])+abs(0-target[1]);
        if(ans2<ans1){
            return true;
        }
        return false;













        // queue<pair<int,int>> q;
        // unordered_set<pair<int,int>,pair_hash> vis;
        // for(int i=0 ; i<ghosts.size() ; i++){
        //     q.push({ghosts[i][0],ghosts[i][1]});
        //     vis.insert({ghosts[i][0],ghosts[i][1]});

        // }
        // int ans = -1;
        // int level=0;
        // while(!q.empty()){
        //     int size = q.size();
        //     for(int i=0 ; i<size ; i++){
        //         pair<int,int> top=q.front();
        //         q.pop();
        //         if(top.first==target[0] && top.second==target[1]){
        //             ans=level;
        //             break;
        //         }
        //         if(top.first>=10000 || top.first<=-10000 || top.second>=10000 ||top.second<=-10000){
        //             continue;
        //         }
        //         if(vis.find({top.first+1,top.second})==vis.end()){
        //             vis.insert({top.first+1,top.second});
        //             q.push({top.first+1,top.second});
        //         }
        //         if(vis.find({top.first-1,top.second})==vis.end()){
        //             vis.insert({top.first-1,top.second});
        //             q.push({top.first-1,top.second});
        //         }
        //         if(vis.find({top.first,top.second+1})==vis.end()){
        //             vis.insert({top.first,top.second+1});
        //             q.push({top.first,top.second+1});
        //         }
        //         if(vis.find({top.first,top.second-1})==vis.end()){
        //             vis.insert({top.first,top.second-1});
        //             q.push({top.first,top.second-1});
        //         }

        //     }
        //     level++;
        //     if(ans!=-1){
        //         break;
        //     }
            
        // }
        // vis.clear();
        // queue<pair<int,int>> q2;
        // q2.push({0,0});
        // vis.insert({0,0});
        // int ans2 = -1;
        // level=0;
        // while(!q2.empty()){
        //     int size = q2.size();
        //     for(int i=0 ; i<size ; i++){
        //         pair<int,int> top=q2.front();
        //         q2.pop();
        //         if(top.first==target[0] && top.second==target[1]){
        //             ans2=level;
        //             break;
        //         }
        //         if(top.first>=10000 || top.first<=-10000 || top.second>=10000 ||top.second<=-10000){
        //             continue;
        //         }
        //         if(vis.find({top.first+1,top.second})==vis.end()){
        //             vis.insert({top.first+1,top.second});
        //             q2.push({top.first+1,top.second});
        //         }
        //         if(vis.find({top.first-1,top.second})==vis.end()){
        //             vis.insert({top.first-1,top.second});
        //             q2.push({top.first-1,top.second});
        //         }
        //         if(vis.find({top.first,top.second+1})==vis.end()){
        //             vis.insert({top.first,top.second+1});
        //             q2.push({top.first,top.second+1});
        //         }
        //         if(vis.find({top.first,top.second-1})==vis.end()){
        //             vis.insert({top.first,top.second-1});
        //             q2.push({top.first,top.second-1});
        //         }

        //     }
        //     level++;
        //     if(ans2!=-1){
        //         break;
        //     }
            
        // }



        // cout<<ans<<endl;
        // cout<<ans2<<endl;
        // if(ans2<ans){
        //     return true;
        // }
        // return false;
    }
};