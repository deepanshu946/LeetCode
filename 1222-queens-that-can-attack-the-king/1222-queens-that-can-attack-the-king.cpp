class Solution {
private:
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {

        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
bool check(vector<int> queen , unordered_set<pair<int,int>,pair_hash> &s , vector<int> king){
    for(int i=queen[0]-1 ; i>=0 ; i--){
        if(s.find({i,queen[1]}) != s.end()){
            break;
        }
        if(king[1]==queen[1] && king[0]==i){
            return true;
        }
    }
    for(int i=queen[0]+1 ; i<8 ; i++){
        if(s.find({i,queen[1]}) != s.end()){
            break;
        }
        if(king[1]==queen[1] && king[0]==i){
            return true;
        }
    }
    for(int i=queen[1]+1 ; i<8 ; i++){
        if(s.find({queen[0],i}) != s.end()){
            break;
        }
        if(king[0]==queen[0] && king[1]==i){
            return true;
        }
    }
    for(int i=queen[1]-1 ; i>=0 ; i--){
        if(s.find({queen[0],i}) != s.end()){
            break;
        }
        if(king[0]==queen[0] && king[1]==i){
            return true;
        }
    }
    for(int i=queen[0]-1, j = queen[1]-1 ; i>=0,j>=0 ; i--,j--){
        if(s.find({i,j}) != s.end()){
            break;
        }
        if(king[0]==i && king[1]==j){
            return true;
        }
    }
    for(int i=queen[0]-1, j = queen[1]+1 ; i>=0,j<8 ; i--,j++){
        if(s.find({i,j}) != s.end()){
            break;
        }
        if(king[0]==i && king[1]==j){
            return true;
        }
    }
    for(int i=queen[0]+1, j = queen[1]+1 ; i<8,j<8 ; i++,j++){
        if(s.find({i,j}) != s.end()){
            break;
        }
        if(king[0]==i && king[1]==j){
            return true;
        }
    }
    for(int i=queen[0]+1, j = queen[1]-1 ; i<8,j>=0 ; i++,j--){
        if(s.find({i,j}) != s.end()){
            break;
        }
        if(king[0]==i && king[1]==j){
            return true;
        }
    }
    return false;

}
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_set<pair<int,int> , pair_hash> s;
        for(int i=0 ; i<queens.size() ; i++){
            s.insert({queens[i][0],queens[i][1]});
        }
        vector<vector<int>> ans;
        for(int i=0 ; i<queens.size() ; i++){
            if(check(queens[i],s,king)){
                ans.push_back(queens[i]);
            }
        }
        return ans;
        
    }
};