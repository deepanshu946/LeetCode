class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int ans = n*2;
        int i = 0;
        while(i<nums.size()){
            int val = nums[i][0];
            vector<int> temp(11,0);
            while(i<nums.size()&& nums[i][0]==val){
                temp[nums[i][1]]++;
                i++;
            }
            if(temp[2] || temp[3] || temp[4] || temp[5]){
                ans--;
                if(temp[6] || temp[7] || temp[8] || temp[9]){
                    ans--;
                    if(!temp[4] && !temp[5] && !temp[6] && !temp[7]){
                        ans++;
                    }
                }
            }
            else if(temp[6] || temp[7] || temp[8] || temp[9]){
                ans--;
            }
            
        }
        return ans;

    }
};