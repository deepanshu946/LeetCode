class Solution {
public:
    int minFlips(string s) {
        int count1 = 0; //1 se start me kitne changes
        int count2 = 0; // 0 se start me kitne changes
        
        char start1 = '1';
        char start2 = '0';
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]!=start1){
                count1++;
            }
            if(s[i] != start2){
                count2++;
            }
            if(start1 == '1'){
                start1 = '0';
            }
            else{
                start1 = '1';
            }
            if(start2 == '1'){
                start2 = '0';
            }
            else{
                start2 = '1';
            }
        }

        int ans = min(count1,count2);
        s = s+s;
        // cout<<s<<endl;
        int n = s.length();
        int left = 0;
        int right = (n/2) ;
        char prev1 = '1';
        char prev2 = '0';

        while(right < n){
            
            if(s[right]!=start1){
                count1++;
            }
            if(s[right] != start2){
                count2++;
            }
            if(s[left] != prev1){
                count1--;
            }
            if(s[left] != prev2){
                count2--;
            }
            if(start1 == '1'){
                start1 = '0';
            }
            else{
                start1 = '1';
            }
            if(start2 == '1'){
                start2 = '0';
            }
            else{
                start2 = '1';
            }
            if(prev1 == '1'){
                prev1 = '0';
            }
            else{
                prev1 = '1';
            }
            if(prev2 == '1'){
                prev2 = '0';
            }
            else{
                prev2 = '1';
            }
            ans = min(ans , min(count1, count2));
            left++;
            right++;

        }
        // ans = min(ans , min(count1,count2));
        return ans;
        
    }
};