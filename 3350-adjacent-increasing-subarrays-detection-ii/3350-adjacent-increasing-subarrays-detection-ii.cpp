class Solution {
private:
bool checkmid(vector<int> &maxlenleft, vector<int> &maxlenright , int n , int mid){
    for(int i=mid-1 ; i<n-mid ; i++){
        if(maxlenleft[i]>=mid && maxlenright[i+1]>=mid){
            return true;
        }
    }
    return false;
}
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        //log(n) on k -> limits of k will be 0->maxLengthofincsub
        int n = nums.size();
        vector<int> maxlenleft(n,0);
        maxlenleft[0]=1;
        int maxi = 1;

        for(int i=1 ; i<n ; i++){
            if(nums[i]>nums[i-1]){
                maxlenleft[i]=1+maxlenleft[i-1];
                
            }
            else{
                maxlenleft[i]=1;
            }
            maxi = max(maxi,maxlenleft[i]);
        }
        vector<int> maxlenright(n,0);
        maxlenright[n-1]=1;
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                maxlenright[i]=1+maxlenright[i+1];
            }
            else{
                maxlenright[i]=1;
            }
        }
        int store = 0;
        int start= 0;
        int end = maxi;
        while(start<=end){
            int mid = (start+end)/2;
            if(checkmid(maxlenleft,maxlenright,n,mid)){
                store = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return store;


    }
};