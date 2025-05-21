class Solution {
public:
    int maxDepth(string s) {
        int ans = INT_MIN;
        int temp = 0;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]=='('){
                temp++;
            }
            if(s[i]==')'){
                temp--;
            }
            ans = max(ans , temp);
        }
        return ans;
    }
};