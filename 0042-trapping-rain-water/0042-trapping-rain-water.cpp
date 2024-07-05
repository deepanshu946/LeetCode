class Solution {
private:
void nextgr(vector<int> nums , vector<int> &next , int n){
    int maxi = INT_MIN;
    for(int i=n-1 ; i>=0 ; i--){
        maxi = max(maxi,nums[i]);
        next[i]=maxi;
    }
}
void prevgr(vector<int> nums , vector<int> &prev , int n){
    int maxi = INT_MIN;
    for(int i=0 ; i<n ; i++){
        maxi = max(maxi,nums[i]);
        prev[i]=maxi;
    }
}
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n);
        nextgr(nums,next,n);
        vector<int> prev(n);
        prevgr(nums , prev,n);
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            cout<<next[i]<<" ";
        }
        cout<<endl;
                for(int i=0 ; i<n ; i++){
            cout<<prev[i]<<" ";
        }
        for(int i=1 ; i<n-1 ; i++){
            ans = ans + (min(next[i],prev[i])-nums[i]);
        }
        return ans;
    }

};