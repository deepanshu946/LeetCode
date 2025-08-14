class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr=0;
        if(nums.size()==1){
            return nums.size();
        }
        for(int i=0 ; i<nums.size() ; i++ ){
            if(i==nums.size()-1 ){
                nums[curr]=nums[i];
                curr++;
            }
            else if(nums[i] != nums[i+1]){
                nums[curr]=nums[i];
                curr++;
            }
        }
        return curr;
    }
};