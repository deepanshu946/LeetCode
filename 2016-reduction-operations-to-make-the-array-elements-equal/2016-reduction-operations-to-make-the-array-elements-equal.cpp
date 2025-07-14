class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }
        vector<int> temp;
        for(auto i:m){
            temp.push_back(i.first);
        }
        sort(temp.begin(),temp.end());
        int ans = 0;
        for(int i=temp.size()-1 ; i>=1 ; i--){
            ans = ans + (i*m[temp[i]]);
        }
        return ans;

    }
};