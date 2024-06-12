class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one = 0;
        int two = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]==0){
                zero++;
            }
        }
        for(int i=0 ; i<n ; i++){
            if(nums[i]==1){
                one++;
            }
        } 
        for(int i=0 ; i<n ; i++){
            if(nums[i]==2){
                two++;
            }
        }

        int index = 0;
        while(zero != 0){
            nums[index]=0;
            zero--;
            index++;
        }
        while(one != 0){
            nums[index]=1;
            one--;
            index++;
        }
        while(two != 0){
            nums[index]=2;
            two--;
            index++;
        }
    }
};