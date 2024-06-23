class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(int i=0 ; i<s.length() ; i++){
            char ch = s[i];
            m[ch]++;
        }
        int ans = 0;
        bool check = false;
        for(auto i:m){
            if(i.second % 2 ==0){
                ans = ans + i.second;
            }
            else{
                check = true;
                ans = ans + i.second-1;
            }
        }
        if(check){
            return ans + 1;
        }
        else{
            return ans;
        }
    }
};