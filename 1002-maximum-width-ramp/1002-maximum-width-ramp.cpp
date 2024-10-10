class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<pair<int,int>> s;
        int ans = 0;
        for(int i=nums.size()-1 ; i>=0 ; i--){
            pair<int,int> p = {nums[i],i};
            if(s.empty()){
                s.push(p);
            }
            else{
                int ramp = 0;
                vector<pair<int,int>> temp;
                while(!s.empty() && s.top().first >= p.first){
                    temp.push_back(s.top());
                    ramp=max(ramp,s.top().second-p.second);
                    s.pop();

                }
                while(temp.size() != 0){
                    s.push(temp.back());
                    temp.pop_back();
                }
                if(p.first >= s.top().first){
                    s.push(p);
                }
                ans = max(ans , ramp);
            }
        }
        return ans;
    }
};