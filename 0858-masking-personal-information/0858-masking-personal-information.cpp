class Solution {
private:
bool digit(char s){
    if(s>='0' && s<='9'){
        return true;
    }
    return false;
}
bool uppercase(char ch){
    if(ch>='A' && ch<='Z'){
        return true;

    }
    return false;
}
public:
    string maskPII(string s) {
        int n = s.length();
        if(digit(s[0]) || s[0]=='+' || s[0]=='(' || s[0]=='-' || s[0] == ' ' || s[0]==')'){
            int digits = 0;
            for(int i=0 ; i<n ; i++){
                if(digit(s[i])){
                    digits++;
                }
            }
            string temp = "";
            int j=n-1;
            while(temp.length() != 4){
                if(digit(s[j])){
                    temp.push_back(s[j]);
                }
                j--;
            }
            reverse(temp.begin(),temp.end());
            if(digits == 10){
                return "***-***-"+temp;
            }
            if(digits == 11){
                return "+*-***-***-"+temp;
            }
            if(digits == 12){
                return "+**-***-***-"+temp;
            }
            if(digits == 13){
                return "+***-***-***-"+temp;
            }

        }
        
        else{
            for(int i=0 ; i<n ; i++){
                if(uppercase(s[i])){
                    s[i]=s[i]-'A'+'a';
                }
            }
            int count = 0;
            int i=0;
            while(s[i] != '@'){
                count++;
                i++;
            } 
            char last = s[i-1];
            string temp = "";
            while(i<n){
                temp.push_back(s[i]);
                i++;
            }
            char first = s[0];
            string temp2 = "*****";
            return first + temp2 + last + temp;
        }
        return "";
    }
};