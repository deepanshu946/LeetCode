class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin() , expected.end());
        int ans =0;
        for(int i=0 ; i<expected.size() ; i++){
            if(expected[i]!=heights[i])
            ans++;
        }
        return ans;
    }
};