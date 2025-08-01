class Solution {
private:
int lower_bound(vector<int> &nums , int target){
    int start = 0;
    int end = nums.size()-1;
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(nums[mid]>target){
            end = mid-1;
        }
        else{
            ans = mid;
            start = mid+1;
        }
    }
    return ans;
}
int upper_bound(vector<int> &nums , int target){
    int start = 0;
    int end = nums.size()-1;
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(nums[mid]>=target){
            ans = mid;
            end = mid-1;
        }
        else{
            // ans = mid;
            start = mid+1;
        }
    }
    return ans;
}
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=n-1; i>=0 ; i--){
            if(nums[i]==0){
                nums.pop_back();
            }
            else{
                break;
            }
        }
        reverse(nums.begin(),nums.end());

        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i+1 ; j<nums.size();j++){
                int maxx = lower_bound(nums,nums[i]+nums[j]-1);
                int minn = upper_bound(nums,abs(nums[i]-nums[j])+1);
                if(i>=minn){
                    if(i>=maxx){
                        ans = ans + maxx - minn ;
                    }
                    else{
                        maxx = min(maxx,i);
                        ans = ans + maxx - minn;
                    }
                    
                }
                
                // cout<<maxx<<" "<<minn<<endl;

            }
        }
        return ans;
    }
};