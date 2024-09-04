class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<vector<int>> ans ;
        int index = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(m.find(nums[i]) == m.end()){
                vector<int> temp;
                temp.push_back(i);
                m[nums[i]]=index;
                index++;
                ans.push_back(temp);
            }
            else{
                if(ans[m[nums[i]]].size()<nums[i]){
                    ans[m[nums[i]]].push_back(i);
                }
                else{
                    vector<int> temp2 ;
                    temp2.push_back(i);
                    m[nums[i]]=index;
                    index++;
                    ans.push_back(temp2);
                }

            }
        }
        return ans;
    }
};