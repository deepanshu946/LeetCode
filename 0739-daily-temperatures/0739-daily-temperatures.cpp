class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<pair<int,int>> s;
        s.push({0,0});
        int index = n-1;
        for(index ; index>=0 ; index--){
            int val = temperatures[index];
            while(s.top().first != 0 && s.top().first <= val){
                s.pop();
            }
            if(s.top().first ==0 ){
                ans[index]=0;
            }
            else{
                ans[index]=s.top().second - index;
            }
            s.push(make_pair(val,index));
        }
        return ans;
    }
};