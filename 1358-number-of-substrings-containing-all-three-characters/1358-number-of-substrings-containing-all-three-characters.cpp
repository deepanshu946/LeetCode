class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> m;
        int left = 0;
        int right = 0;
        int ans= 0;
        while(right<s.length()){
            m[s[right]]++;
            while(m.size()==3){
                ans = ans+(s.length()-right);
                m[s[left]]--;
                if(m[s[left]]==0){
                    m.erase(s[left]);
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};