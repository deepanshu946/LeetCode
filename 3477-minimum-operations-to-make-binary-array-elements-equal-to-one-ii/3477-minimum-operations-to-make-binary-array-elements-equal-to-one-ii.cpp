class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flip = 0;
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==0){
                if(flip%2==0){
                    ans++;
                    flip++;
                }
                
            }
            else{
                if(flip%2 != 0){
                    ans++;
                    flip++;
                }
            }
            
                
            
        }
        return ans;
    }
};