class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        // priority_queue<pair<int,int>> pq;
        unordered_map<int,int> m;
        for(int i=0 ; i<k ; i++){
            m[nums[i]]++;
        }
        vector<int> ans;
        int start = 0;
        while(start<=nums.size()-k){
            int count = 0;
            bool check = 0;
            for(int i=-50 ; i<0 ; i++){
                if(m.find(i) != m.end()){
                    count = count+m[i];
                }
                if(count>=x){
                    ans.push_back(i);
                    check=1;
                    break;
                }
            }
            if(!check){
                ans.push_back(0);
            }
            m[nums[start]]--;
            if(m[nums[start]]==0){
                m.erase(nums[start]);
            }
            if(start+k < nums.size()){
                m[nums[start+k]]++;

            }
            start++;
        }
        return ans;

    }
};