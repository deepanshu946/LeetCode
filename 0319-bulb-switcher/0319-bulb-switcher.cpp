class Solution {
public:
    int bulbSwitch(int n) {
        int ans = 0;
        int i=1 ;
        int count = 0 ; 
        while(count<n){
            i=i+2;
            count = count + i;
            ans++;
        }
        return ans;
    }
};