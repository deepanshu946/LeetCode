class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if (ranges::count(s, '1') < k) {
            return "";
        }
        int left = 0;
        int right = 0;
        string temp = "";
        string ans =s;
        int len = INT_MAX;
        int count = 0;
        while(right < s.length()){
            if(s[right]=='1'){
                count++;
            }
            while(count > k || s[left]=='0'){
                if(s[left]=='1'){
                    count--;
                }
                left++;
            }
            if(count == k){
                string t = s.substr(left, right - left + 1);
                if (t.length() < ans.length() ||
                    t.length() == ans.length() && t < ans) {
                    ans = move(t);
                }
            }
            
            right++;
        }
        return ans;
    }
};