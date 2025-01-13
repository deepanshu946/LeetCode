class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> m;
        for(int i=0 ; i<s.length() ; i++){
            m[s[i]]++;
        }
        int ans = 0;
        for(auto i:m){
            if(i.second%2==0){
                ans=ans+2;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};