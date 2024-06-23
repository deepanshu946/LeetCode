class Solution {
private:
int getindex(vector<int>&nums , int val){
    for(int i=0 ; i<nums.size() ; i++){
        if(nums[i]==val){
            return i;
        }
        if(nums[i]>val){
            return -1;
        }
    }
    return -1;
}
bool solve(vector<int> &stone , int i , int k){
    if(i==stone.size()-1){
        return true;
    }

    int index1 = getindex(stone,stone[i]+k-1);
    int index2 = getindex(stone,stone[i]+k);
    int index3 = getindex(stone,stone[i]+k+1);
    bool minus=0;
    bool same = 0;
    bool plus=0;
    if(index1 != i && index1 != -1){
        minus = solve(stone,index1 , k-1);
    }
    if(index2 != i && index2 != -1){
        same= solve(stone,index2 , k);
    }
    if(index3 != i && index3 != -1){
        plus= solve(stone,index3 , k+1);
    }
    return minus||same||plus;



}
public:
    bool canCross(vector<int>& stones) {
        if(stones[0] != 0 || stones[1]!= 1){
            return 0;
        }

        // return solve(stones,1,1);
        int n = stones.size();
        unordered_map<int,unordered_set<int>> dp;
        for(int i=0 ; i<n ; i++){
            dp[stones[i]]=unordered_set<int>();
        }
        dp[0].insert(0);
        for(int i=0 ; i<n ; i++){
            int stone = stones[i];
            for(int k:dp[stone]){
                for(int step=k-1 ; step<=k+1 ; step++){
                    if(step>0 && dp.find(stone+step) != dp.end()){
                        dp[stone+step].insert(step);
                    }
                }
            }
        }
        if(dp[stones[n-1]].empty()){
            return false;
        }
        return true;
    }
};