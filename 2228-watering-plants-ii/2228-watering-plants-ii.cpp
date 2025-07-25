class Solution {
public:
    int minimumRefill(vector<int>& nums, int capacityA, int capacityB) {
        int tempa = capacityA;
        int tempb = capacityB;
        int i=0;
        int count=0;
        int j = nums.size()-1;
        while(i<j){
            if(nums[i]>tempa){
                count++;
                tempa = capacityA - nums[i];
            }
            else{
                tempa -= nums[i];
            }
            if(nums[j]>tempb){
                count++;
                tempb = capacityB-nums[j];
            }
            else{
                tempb -= nums[j];
            }
            i++;
            j--;
        }
        if(i==j){
            if(tempa > tempb){
                if(nums[i]>tempa){
                    count++;
                }
            }
            else{
                if(nums[i]>tempb){
                    count++;
                }
            }
            

        }
        return count;
    }
};