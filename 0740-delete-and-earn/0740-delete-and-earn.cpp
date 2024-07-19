class Solution {

private:
int dp[20001];
int solve(int index , vector<int> &nums , map<int,int> &m , int prev){
    if(index>=nums.size()){
        return 0;
    }
    if(prev>=0 && dp[index]!= -1){
        return dp[index];
    }
    int inc = 0;
    int exc = 0;
    //include
    if(prev==nums[index]-1){
        if(nums[index+1] == nums[index]+1 ){
            inc = inc -( (nums[index]-1)*m[nums[index]-1])+ (nums[index] * m[nums[index]])+ solve(index+2 , nums , m , nums[index]);
        }
        else{
            inc = inc -( (nums[index]-1)*m[nums[index]-1])+(nums[index] * m[nums[index]]) + solve(index+1, nums , m , nums[index]);
        }
            
    }
    else{
        if(index+1 < nums.size() && nums[index+1]==nums[index]+1){
            inc = inc+(nums[index] * m[nums[index]]) + solve(index+2,nums,m,nums[index]);
        }
        else{
            inc = inc+(nums[index] * m[nums[index]]) + solve(index+1,nums,m,nums[index]);
        }
    }
    //exclude
    exc = exc + solve(index+1 , nums,m,prev );

    return dp[index]= max(inc,exc);



}
public:
    int deleteAndEarn(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        map<int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }

        vector<int> temp;
        for(auto i:m){
            temp.push_back(i.first);
        }
        if(temp.size()==1){
            return temp[0]*m[temp[0]];
        }
        return solve(0,temp,m,0);

    }
};