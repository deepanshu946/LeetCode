class Solution {
private:
string solve(int n){
    string temp="";
    while(n!=0){
        if(n%2==0){
            temp.push_back('0');

        }
        else{
            temp.push_back('1');

        }
        n=n/2;

    }
    reverse(temp.begin(),temp.end());
    return temp;
}
public:
    int concatenatedBinary(int n) {
        int ans = 1;
        for(int i=2 ; i<=n ; i++){
            string bin = solve(i);
            for(int j=0 ; j<bin.size() ; j++){
                if(bin[j]=='0'){
                    ans = (ans<<1)%1000000007;
                }
                else{
                    ans = ((ans<<1)+1)%1000000007;
                }
            }
        }
        return ans;
    }
};