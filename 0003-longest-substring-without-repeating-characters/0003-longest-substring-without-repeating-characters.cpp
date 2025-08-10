class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int ans = INT_MIN;
        int left=0;
        int right = 0;
        while(right<s.length()){
            if(m.find(s[right]) != m.end()){
                if(m[s[right]] >= left){
                    left = m[s[right]]+1;
                }

            }
            ans = max(ans , right-left+1);
            m[s[right]]=right;
            right++;
        }
        if(ans==INT_MIN){
            return 0;
        }
        return ans;
    }
};