class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> s;
        for(int i=0 ; i<nums.size() ; i++){
            // s.push(nums[i]);
            int top = nums[i];
            // s.pop();
            bool flag = 0;
            while(!s.empty() && ((top < 0 &&  s.top()>0 ))){
                if(abs(top)==abs(s.top())){
                    s.pop();
                    flag = 1;
                    break;
                }
                else if(abs(top) > abs(s.top())){
                    s.pop();
                }
                else{
                    top = s.top();
                    s.pop();
                }
            }
            if(!flag)
                s.push(top);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};