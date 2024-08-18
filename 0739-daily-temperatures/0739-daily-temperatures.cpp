// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int> ans(n);
//         stack<pair<int,int>> s;
//         s.push({0,0});
//         int index = n-1;
//         for(index ; index>=0 ; index--){
//             int val = temperatures[index];
//             while(s.top().first != 0 && s.top().first <= val){
//                 s.pop();
//             }
//             if(s.top().first ==0 ){
//                 ans[index]=0;
//             }
//             else{
//                 ans[index]=s.top().second - index;
//             }
//             s.push(make_pair(val,index));
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> st;
        // st.push(n-1);
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top() - i;
            }
            st.push(i);
        }
     
        return ans;
    }
};