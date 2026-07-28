class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        unordered_set<int> s;
        long long sum = 0;
        for(int i=0 ; i<nums.size() ; i++){
            sum+=nums[i];
            pq.push({nums[i],i});
        }
        vector<long long> ans;
        for(int i=0 ; i<queries.size() ; i++){
            int ind = queries[i][0];
            int k = queries[i][1];
            if(s.find(ind)==s.end()){
                s.insert(ind);
                sum = sum - nums[ind];
            }
            int count = 0;
            while(!pq.empty() && count < k){
                pair<int,int> top = pq.top();
                cout<<top.first<<" "<<top.second<<endl;
                pq.pop();
                if(s.find(top.second) == s.end()){
                    s.insert(top.second);
                    count++;
                    sum = sum - top.first;
                }
            }
            ans.push_back(sum);

        }
        return ans;

    }
};