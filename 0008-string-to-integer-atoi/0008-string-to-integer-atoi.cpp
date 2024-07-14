class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool minus=0;
        bool change = 0;
        bool plus=0;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]=='-'){
                if(!minus && !change && !plus){
                    minus=1;
                }
                else{
                    break;
                }
            }
            else if(s[i]=='+'){
                if(!plus && !change && !minus){
                    plus=1;
                }
                else{
                    break;
                }
            }
            else if(s[i]==' '){
                if(!change && !plus && !minus){
                    continue;
                }
                else{
                    break;
                }
            }
            else if(s[i] >= 48 && s[i]<= 57){
                ans = ans*10 + (s[i]-48);
                change = 1;
            } 
            else{
                break;
            }
            if(ans > INT_MAX ){
                if(!minus){
                    return INT_MAX;
                }
                else{
                    return INT_MIN;
                }
            }
        }
        if(minus){
            return -ans;
        }
        return ans;
    }
};