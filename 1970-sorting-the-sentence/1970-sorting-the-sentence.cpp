class Solution {
public:
    string sortSentence(string s) {
        char ch = '1';
        string temp = "";
        string ans = "";
        while(true){
            int index = s.find(ch);
            cout<<index<<endl;
            ch++;
            if(index==-1){
                break;
            }
            for(int i=index-1; ; i--){
                if( i==-1 || s[i]==' '){
                    reverse(temp.begin() , temp.end());
                    ans=ans+temp;
                    ans.push_back(' ');
                    temp="";
                    break;
                }
                else{
                    temp = temp+s[i];
                }
            }
            cout<<ans<<endl;


        }
        ans.pop_back();
        return ans;
    }
};