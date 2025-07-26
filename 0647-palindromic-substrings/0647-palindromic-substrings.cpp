class Solution {
public:
    int countSubstrings(string s) {
        int ans = 1;
        for(int i=0 ; i<s.length()-1 ; i++){
            ans++;
            int left = i-1;
            int right = i+1;
            while(left>=0 && right <s.length() && s[left]==s[right]){
                ans++;
                left--;
                right++;
            }
            if(s[i]==s[i+1]){
                ans++;
                left = i-1 ;
                right = i+2;
                while(left>=0 && right<s.length() && s[left]==s[right]){
                ans++;
                left--;
                right++;
                }
            }

        }
        return ans;
        
    }
};