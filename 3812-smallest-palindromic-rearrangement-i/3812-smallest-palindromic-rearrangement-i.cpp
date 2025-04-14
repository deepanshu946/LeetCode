class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> m;
        for(int i=0 ; i<s.length() ; i++){
            m[s[i]]++;
        }
        string ans = "";
        char middle = '-';
        for(auto i : m){
            char ch = i.first;
            int count = i.second;
            // cout<<ch<<" "<<count<<endl;
            if(count % 2 != 0){
                middle = i.first;
            }
            int temp = count/2;
            // cout<<temp<<endl;
            for(int j=1 ; j<=temp ; j++){
                ans.push_back(ch);
            }
        }
        string ans2 = ans;
        reverse(ans2.begin(),ans2.end());
        if(middle != '-'){
            ans.push_back(middle);
        }
        
        ans= ans + ans2;

        return ans;
    }
};