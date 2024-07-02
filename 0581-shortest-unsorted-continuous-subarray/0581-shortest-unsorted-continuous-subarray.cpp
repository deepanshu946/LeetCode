class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextsmall(n,INT_MAX);
        int mini=INT_MAX;
        for(int i=n-1; i>=0 ; i--){
            if(nums[i]>mini){
                nextsmall[i]=1;
            }
            mini = min(mini,nums[i]);
        }
        vector<int> prevgreater(n,INT_MAX);
        int maxi  = INT_MIN;
        for(int i=0 ; i<n;i++){
            if(nums[i]<maxi){
                prevgreater[i]=1;
            }
            maxi = max(maxi,nums[i]);
        }
        pair<int,int> ans1(-1,-1);
        pair<int,int> ans2(-1,-1);
        for(int i=0 ; i<n ; i++){
            if(nextsmall[i] != INT_MAX){
                if(ans1.first == -1){
                    ans1.first = i;
                }
                ans1.second = i;
            }
            if(prevgreater[i] !=INT_MAX){
                if(ans2.first == -1){
                    ans2.first=i;
                }
                ans2.second = i;
            }

        }
        if(ans1.first ==-1 ){
            return 0;
        }
        return max(ans1.second,ans2.second )-min(ans1.first,ans2.first)+1;
    }
};