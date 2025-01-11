class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string> temp;
        int zero = num2.length()-1;
        for(int i=num2.length()-1 ; i>=0 ; i--){
            int a = num2[i]-'0';
            string s="";
            for(int j=0 ; j<num2.length()-1-i ; j++){
                s.push_back('0');
            }
            int carry = 0;
            for(int j=num1.length()-1 ; j>=0 ; j--){
                int b = num1[j]-'0';
                int c =( a*b)+carry ;
                int d = c%10;
                carry = c/10;
                s.push_back(d+'0');
            }
            s.push_back(carry+'0');
            for(int k=0 ; k<=zero ; k++){
                s.push_back('0');
            }
            zero--;
            temp.push_back(s);
        }
        string ans="";
        int carry = 0;
        for(int i=0 ; i<temp[0].length() ; i++){
            int sum = carry;
            for(int j=0 ; j<temp.size() ; j++){
                sum = sum + temp[j][i]-'0';
            }
            carry = sum/10;
            int x = sum%10;
            ans.push_back(x+'0');
        }
        for(int i=ans.length()-1 ; i>=0 ; i--){
            if(ans[i] != '0'){
                reverse(ans.begin(),ans.end());
                return ans;
            }
            else{
                ans.pop_back();
            }
        }
        return "0";
    }
};