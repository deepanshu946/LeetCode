class Solution {
private:
bool check(vector<int> &temp , int val, int k){
    for(int i=0 ; i<temp.size() ; i++){
        if(abs(temp[i]-val)==k){
            return false;
        }

    }
    return true;
}
int solve(int i , vector<int> &nums , vector<int> &temp , int k){
    if(i>=nums.size()){
        if(temp.size() != 0){
            return 1;

        }
        return 0;
    }
    int ans = 0;
    if(check(temp,nums[i],k)){
        temp.push_back(nums[i]);
        ans+= solve(i+1,nums,temp,k);
        temp.pop_back();
    }
    ans+=solve(i+1,nums,temp,k);
    return ans;




}
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> temp;
        // sort(nums.begin(),nums.end());
        return solve(0,nums,temp,k);

    }
};