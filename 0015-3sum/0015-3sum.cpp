class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> s;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        if(nums[0]== 0 && nums[nums.size()-1]==0){
            ans.push_back({0,0,0});
            return ans;
        }
        for(int k=1 ; k<nums.size()-1 ; k++){
            int i=0;
            int j=nums.size()-1;
            while(i<j){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin() , temp.end());
                    if(s.count(temp) ==0){
                        s.insert(temp);
                        ans.push_back(temp);
                    }
                    if(i+1 == k){
                        i=i+2;
                    }
                    else{
                        i++;
                    }
                    if(j-1 == k){
                        j=j-2;
                    }
                    else{
                        j--;
                    }
                }
                else if(sum<0){
                    if(i+1 == k){
                        i=i+2;
                    }
                    else{
                        i++;
                    }
                }
                else{
                    if(j-1 == k){
                        j=j-2;
                    }
                    else{
                        j--;
                    }
                }
            }

        }
        return ans;
    }
};