class Solution {
private:
int getgcd(int a , int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a=temp;
    }
    return a;
}
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=0;
        int n = nums.size();
        vector<int> prefix(n,0);
        for(int i=0 ; i<nums.size() ; i++){
            maxi = max(nums[i],maxi);
            prefix[i]=getgcd(nums[i],maxi);
        }
        sort(prefix.begin(),prefix.end());
        int i=0;
        int j=n-1;
        long long ans = 0;
        while(i<j){
            ans = ans + getgcd(prefix[i],prefix[j]);
            i++;
            j--;
        }
        return ans;
    }
};