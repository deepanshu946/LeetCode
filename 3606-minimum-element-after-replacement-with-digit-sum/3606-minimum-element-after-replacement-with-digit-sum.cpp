class Solution {
private:
int getsum(int n){
    int ans = 0;
    while(n!= 0){
        ans = ans + n%10;
        n=n/10;
    }
    return ans;
}
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i=0 ; i<nums.size() ; i++){
            mini = min(mini , getsum(nums[i]));
        }
       return mini; 
    }
};