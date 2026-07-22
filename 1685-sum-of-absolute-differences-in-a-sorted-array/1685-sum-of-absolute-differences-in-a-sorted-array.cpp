class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n,0);
        suffix[n-1]=nums[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            suffix[i]=suffix[i+1] + nums[i];
            cout<<suffix[i]<<endl;
        }
        int prevsum = 0;
        vector<int> ans(n,0);
        for(int i=0 ; i<n ; i++){
            int prevans = 0;
            if(i!=0){
                prevans = (i*nums[i])-(prevsum);
            }
            prevsum += nums[i];
            int lastsum = 0;
            if(i!=n-1){
                lastsum =(suffix[i+1])- ((n-i-1)*nums[i]);
            }
            ans[i]=prevans+lastsum;

        }
        return ans;

    }
};