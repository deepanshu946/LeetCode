class Solution {
private:
bool check(int i, vector<int> &nums) {
        if(i==0){
            if(nums[i] != nums[nums.size()-1] && nums[i] != nums[i+1]){
                return false;
            }
            return true;
        }
        if(nums[i] != nums[i - 1] && nums[i] != nums[(i + 1) % nums.size()]) {
            return false;
        }
        return true;
    }
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int changes = 0;
        int ans = 0;
        for(int i=1 ; i<k-1 ; i++){
            if(check(i,colors)){
                changes++;
            }
        }
        // if(changes==0){
        //         ans++;
        //     }
        int right = k-1;
        int left = 0;
        while(true){
           
            if(changes==0){
                ans++;
            }
            left++;
            if(left==colors.size()){
                return ans;
            }
            if(check(left,colors)){
                changes--;
            }
            if(check(right,colors)){
                changes++;
            }
            right = (right+1)%colors.size();

        }
        return ans;
    }
};