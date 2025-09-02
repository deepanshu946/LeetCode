class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int maxi = 0;
        for(int i=0 ; i<nums.size() ; i++){
            maxi = max(maxi , nums[i]);
        }
        vector<pair<int,int>> temp(maxi+1,{1,1});
        for(int i=2 ; i<maxi+1 ; i++){
            int t = i;
            while(t <= maxi){
                temp[t].first++;
                temp[t].second += i;
                t = t+i;
            }


        }
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(temp[nums[i]].first == 4){
                ans = ans + temp[nums[i]].second;
            }
        }
        return ans;

    }
};