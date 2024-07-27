class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // vector<int> prefix(n,0);
        // vector<int> suffix(n,0);
        // prefix[0]=nums[0];
        // suffix[n-1]=nums[n-1];
        long long ans = INT_MIN;
        long long prefix=1;
        for(int i=0 ; i<n ; i++){
            // prefix[i]=prefix[i-1]*nums[i];
            prefix=prefix*nums[i];
            ans = max(ans,prefix);
            if(prefix==0 || prefix>INT_MAX || prefix<INT_MIN){
                prefix=1;
            }

        }
        long long suffix=1;
        for(int i=n-1 ; i>=0 ; i--){
            // suffix[i]=suffix[i+1]*nums[i];
            suffix=suffix*nums[i];
            ans = max(ans,suffix);
            if(suffix==0 || suffix>INT_MAX || suffix<INT_MIN){
                suffix=1;
            }
        }
        return ans;
    }

};