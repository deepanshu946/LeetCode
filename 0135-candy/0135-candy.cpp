class Solution {
public:
    int candy(vector<int>& nums) {
        int ans = nums.size();
        int temp = 0;
        vector<int> store(nums.size(),1);
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i]>nums[i-1]){
                temp++;
                ans = ans + temp;
                store[i]+=temp;
            }
            else{
                temp=0;
            }
        }
        cout<<ans<<endl;
        temp=0;
        for(int i=nums.size()-2 ; i>=0 ; i--){
            
            if(i-1>=0 && nums[i]>nums[i+1] && nums[i]>nums[i-1]){
                if(store[i]<=temp+1){
                    ans = ans + temp-store[i]+2;
                }
            }
            else if(nums[i]>nums[i+1]){
                temp++;
                ans = ans+temp;
            }
            else{
                temp=0;
            }
        }
        return ans;
    }
};