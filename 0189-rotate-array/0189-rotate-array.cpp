class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        //using a temp array
        // vector<int> temp(nums.size());
        // for(int i = 0 ; i < nums.size();i++){
        //     temp[(i+k)%nums.size()] = nums[i];

        // }
        // //copy temp into nums.
        // nums = temp;

        int i=nums.size()-k ;
        int j = nums.size()-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
         i = 0;
         j = nums.size()-k-1;
         while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
         }
         reverse(nums.begin(),nums.end());
         

    }
};