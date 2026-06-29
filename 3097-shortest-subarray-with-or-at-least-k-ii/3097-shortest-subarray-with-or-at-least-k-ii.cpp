class Solution {
private:
vector<int> getbit(int num){
    vector<int> bits(32,0);
    int j=0;
    while(num != 0){
        int rem = num%2;
        num = num/2;
        if(rem==1){
            bits[j]=1;
        }
        j++;
    }
    return bits;
}
int bittoint(vector<int> &bit){
    long long power = 1;
    int num = 0;
    for(int i=0 ; i<32 ; i++){
        if(bit[i] != 0){
            num += power;
        }
        power = power*2;
    }
    return num;
}
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = INT_MAX;
        vector<int> windowbit(32,0);
        while(right<nums.size()){
            vector<int> bit = getbit(nums[right]);
            for(int i=0 ;i<32 ; i++){
                windowbit[i]+=bit[i];
            }
            int num = bittoint(windowbit);
            while(left<=right && num>=k){
                ans= min(ans , right-left+1);
                vector<int> temp = getbit(nums[left]);
                for(int i=0 ;i<32 ; i++){
                windowbit[i]-=temp[i];
                }
                left++;
                num = bittoint(windowbit);
            }
            right++;
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};