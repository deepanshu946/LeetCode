class Solution {
public:
    int numRabbits(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }
        int ans = 0;
        for(auto i:m){
            int temp = i.first+1;
            if(i.second <= temp){
                ans = ans+temp;
            }
            else if(i.second%temp != 0){
                ans = ans+(temp*(i.second/temp))+temp;
            }
            else{
                ans = ans +( temp*(i.second/temp));
            }
        }
        return ans;
    }
};