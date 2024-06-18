class Solution {
private:
bool check(vector<int> base , vector<int> newbox){
    if(newbox[0]<=base[0] && newbox[1]<=base[1] && newbox[2]<=base[2]){
        return true;
    }
    return false;
}
int solve(vector<vector<int>> &nums, int n){
    vector<int> nextrow(n+1 , 0);
    vector<int> currrow(n+1,0);
    for(int curr = n-1 ; curr>=0 ; curr--){
        for(int prev = curr-1 ; prev>=-1 ; prev--){
            int inc =0;
            int exc=0;
            if(prev == -1 || check(nums[curr],nums[prev])){
                inc = nums[curr][2]+nextrow[curr+1];
            }
            exc = nextrow[prev+1];
            currrow[prev+1]=max(inc,exc);
        }
        nextrow = currrow;
    }
    return nextrow[0];
}
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a : cuboids){
            sort(a.begin(),a.end());
        }
        sort(cuboids.begin() , cuboids.end());
        return solve(cuboids,cuboids.size());
    }
};