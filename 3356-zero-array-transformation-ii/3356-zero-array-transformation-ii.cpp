class Solution {

private:

bool check(int mid , vector<int> &nums,vector<vector<int>>& queries){
    vector<int> temp(nums.size(),0);
    for(int i=0 ; i<mid+1 ; i++){
        temp[queries[i][0]] -= queries[i][2];
        if(queries[i][1] < nums.size()-1){
            temp[queries[i][1]+1] += queries[i][2];
        }
    }
    for(int i=1 ; i<temp.size() ; i++){
        temp[i]=temp[i]+temp[i-1];
    }
    for(int i=0 ; i<nums.size() ; i++){
        if(nums[i]!=0){
            if(temp[i]<0 && abs(temp[i])>=nums[i] ){

            }
            else{
                return false;
            }
        }
    }
    return true;
}


int solve(int start , int end, vector<int> &nums,vector<vector<int>>& queries){
    int ans = -2;
    while(start<=end){
        int mid = (start+end)/2;

        bool flag = check(mid,nums,queries);
        // cout<<flag<<endl;
        if(flag==1){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans+1;
}
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(sum>0){
                break;
            }
            sum = sum + nums[i];
        }
        if(sum==0){
            return 0;
        }
        
        // cout<<store.size()<<endl;
        return solve(0,queries.size()-1  , nums, queries);
    }
};