class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n+2 , 0);
        dp[1]=0;
        dp[2]=1;
        if(n<=2){
            return dp[n];
        }
        for(int i=3 ; i<=n ; i++){
            string temp = to_string(i);
            int ans = 0;
            bool flag = 0;
            string temp2= "";
            for(int i=0 ; i<temp.size() ; i++){
                if(temp[i]=='0' || temp[i]=='8' || temp[i]=='1'){
                    temp2= temp2 + temp[i];
                }
                else if(temp[i]=='2'){
                    temp2= temp2 + "5";
                }
                else if(temp[i]=='5'){
                    temp2= temp2 + "2";
                }
                else if(temp[i]=='6'){
                    temp2= temp2 + "9";
                }
                else if(temp[i]=='9'){
                    temp2= temp2 + "6";
                }
                else{
                    flag=1;
                    break;
                }
                
            }
            if(!flag && temp != temp2){
                ans = 1;
            }
            dp[i]=ans + dp[i-1];

        }
        return dp[n];

    }
};