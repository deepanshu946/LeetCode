class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int lowerbound = 0;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]>=0){
                lowerbound = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        cout<<lowerbound<<endl;
        start = 0;
        end = nums.size()-1;
        int upperbound = 0;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]>0){
                upperbound = mid;
                end = mid-1;
            }
            else if(nums[mid]==0){
                upperbound = mid;
                start = mid+1;
            }
            else{
                start = mid+1;
            }
        }
        cout<<upperbound<<endl;
        if(nums[upperbound]==0){
            upperbound++;
        }
        if(lowerbound>(nums.size()-upperbound)){
            return lowerbound;
        }
        return nums.size()-upperbound;

    }
};