class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> temp = nums;
        int ans = 0;
        int n = nums.size();
        for(int i=0 ; i<n-2 ; i++){
            if(temp[i]==0){
                ans++;
                temp[i]=1;
                if(temp[i+1]==0){
                    temp[i+1]=1;
                }
                else{
                    temp[i+1]=0;
                }
                 if(temp[i+2]==0){
                    temp[i+2]=1;
                }
                else{
                    temp[i+2]=0;
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            if(temp[i]==0){
                return -1;
            }
        }
        return ans;
    }
};