class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = 0;
        int sum = 0;
        vector<bool> mark(n,0);
        for(int i=0 ; i<n ; i++){
            if(mark[nums[i]-1] != 0){
                dup = nums[i];
                // break;
            }
            sum = sum + nums[i];
            mark[nums[i]-1]=1;
        }
        int temp = ((n)*(n+1))/2;
        int diff = temp-sum;
        return {dup,dup+diff};
        

    }
};