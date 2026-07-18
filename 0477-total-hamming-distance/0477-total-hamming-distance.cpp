class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> one(32,0);
        vector<int> zero(32,0);
        int ans = 0;
        int temp = nums[0];
        
        int i=0;
        while(i<32){
            if(temp&(1<<i)){
                one[i]++;
            }
            else{
                zero[i]++;
            }
            i++;
        }
        for(int i=1 ; i<nums.size() ; i++){
            int j=0;
            while(j<32){
                if(nums[i]&(1<<j)){
                    ans = ans + zero[j];
                    one[j]++;
                }
                else{
                    ans = ans + one[j];
                    zero[j]++;
                }
                j++;
            }
        }
        return ans;
    }
};