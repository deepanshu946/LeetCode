class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int sum = 0;
        int ans = 0;
        for(int i=0 ; i<k ; i++){
            sum = sum + arr[i];
        }
        if(sum/k>=th){
            ans++;
        }
        int left = 1;
        int right = k;
        while(right<arr.size()){
            sum = sum-arr[left-1];
            sum = sum + arr[right];
            left++;
            right++;
            if((sum/k)>=th){
                ans++;
            }
        }
        return ans;
    }
};