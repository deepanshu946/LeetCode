class Solution {
private:
int search(int start , int end , int val, vector<vector<int>> &nums){
    int store = -1;
    while(start<=end){
        int mid = (start+end)/2;
        int temp = nums[mid][0];
        if(temp<=val){
            start=mid+1;
        }
        else{
            store = mid;
            end = mid-1;
        }
    }
    return store;
}
public:
    int maxTwoEvents(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> temp(nums.size(),0);
        temp[n-1]=nums[n-1][2];
        for(int i=n-2 ; i>=0 ; i--){
            temp[i]=max(nums[i][2],temp[i+1]);
        }
        int ans= 0;
        for(int i=0 ; i<nums.size()-1 ; i++){
            int end = nums[i][1];
            int index = search(i+1,n-1,end,nums);
            cout<<index<<endl;
            if(index != -1){
            ans = max(ans , nums[i][2]+temp[index]);

            }
        }
        return max(ans , temp[0]);


    }
};