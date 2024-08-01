class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        //window size will be 2k+1;
        int n = nums.size();
        vector<int> ans(n,-1);
        int index = k;
        long long sum = 0;
        if(n<(2*k)+1){
            return ans;
        }
        for(int i=0 ; i<=(2*k) ; i++){
            sum = sum+nums[i];
        }
        ans[index]=sum/((2*k)+1);
        index++;
        int right = (2*k)+1;
        int left = 0;
        while(right<n){
            sum = sum - nums[left];
            sum = sum + nums[right];
            cout<<sum<<endl;
            left++;
            right++;
            ans[index]=sum/((2*k)+1);
            index++;
        }
        return ans;

    }
};