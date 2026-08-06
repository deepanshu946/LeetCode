class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> temp(33,0);
        for(int i=0 ; i<nums.size() ; i++){
            int val = nums[i];
            int count = 0;
            while(val != 0){
                int bit = val%2;
                val=val/2;
                if(bit){
                    temp[count]++;
                }
                count++;
            }
        }
        int ans = 0;
        int i = 0;
        while(k != 0){
            int b = k%2;
            k= k/2;
            if(b){
                if(temp[i]%2==0){
                    ans++;
                }
            }
            else{
                if(temp[i]%2!=0){
                    ans++;
                }
            }
            i++;
        }
        for(int j=i ; j<=32 ; j++){
            if(temp[j]%2 == 1){
                ans++;
            }
        }
        return ans;
    }
};