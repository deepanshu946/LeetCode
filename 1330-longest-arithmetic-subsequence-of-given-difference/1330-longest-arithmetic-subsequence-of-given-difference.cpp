class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int,int> m;
        int ans =0;
        for(int i=0 ; i<arr.size() ; i++){
            int val = arr[i]-d;

            if(m.find(val) != m.end()){
                m[arr[i]]=1+m[val];
            }
            else{
                m[arr[i]]=1;
            }
            ans=max(ans,m[arr[i]]);
        }
        return ans;

    }
};