class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int check = 0;
        int i=0;
        while( i<s.length()){
            if(check==0){
                check=1;
                i++;
                int flag=-1;
                while(check != 0 && i<s.length()){
                    if(s[i] == '('){
                        flag++;
                    }
                    if(s[i] == ')'){
                        flag--;
                    }
                    if(flag==-2 && s[i]==')'){
                        if(check==1){
                        check=0;
                    }
                    }
                    else{
                         ans.push_back(s[i]);
                    }
                    i++;

                }
            }
        }
        return ans;
    }
};