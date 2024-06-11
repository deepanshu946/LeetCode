class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for(int i=s.length()-1 ; i>= 0 ; i--){
            if(s[i] == ' ' && temp.length() == 0){
                continue;
            }
            if(s[i]==' '){
                reverse(temp.begin() , temp.end());
                ans=ans+temp;
                ans.push_back(' ');
                temp = "";
            }
            else{
                temp.push_back(s[i]);
            }
            
        }
        cout<<ans<<endl;
        cout<<ans.length()<<endl;
        cout<<temp<<endl;
        cout<<temp.length()<<endl;
        if(temp.length()!=0){
        reverse(temp.begin() , temp.end());
        ans=ans+temp;
        }
        else{
            ans.pop_back();
        }
        return ans;
    }
};