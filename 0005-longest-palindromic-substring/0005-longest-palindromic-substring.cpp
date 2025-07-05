class Solution {
private:
bool check(int i , int j , string &s){
    while(i<=j){
        if(s[i] != s[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}
public:
    string longestPalindrome(string s) {
        string ans = "";
        if(s.length()==1){
            return s;
        }
        for(int i=0 ; i<s.length() ; i++){
            for(int j=i ; j<s.length() ; j++){
                if(check(i,j,s)){
                    string temp = s.substr(i,j-i+1);
                    if(temp.length()>ans.length()){
                        ans = temp;
                    }
                    
                }
            }
        }
        return ans;
    }
};