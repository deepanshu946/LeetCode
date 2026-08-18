class Solution {
public:
    int minFlips(string s) {
        int count1 = 0; //1 se start me kitne changes
        int count2 = 0; // 0 se start me kitne changes
        for(int i=0 ; i<s.length() ; i++){
            char expected1 = (i % 2 == 0) ? '1' : '0';
            char expected2 = (i % 2 == 0) ? '0' : '1';
            if(s[i] != expected1){
                count1++;
            }
            if(s[i] != expected2){
                count2++;
            }
        }
        int n = s.length();
        int ans = min(count1,count2);
        s = s+s;
        // cout<<s<<endl;
        int left = 0;
        int right = n ;

        while(right < s.length()){
            char expected1 = (right % 2 == 0) ? '1' : '0';
            char expected2 = (right % 2 == 0) ? '0' : '1';
            char prevexpected1 = (left % 2 == 0) ? '1' : '0';
            char prevexpected2 = (left % 2 == 0) ? '0' : '1';
            if(s[right]!=expected1){
                count1++;
            }
            if(s[right] != expected2){
                count2++;
            }
            if(s[left] != prevexpected1){
                count1--;
            }
            if(s[left] != prevexpected2){
                count2--;
            }
            ans = min(ans , min(count1, count2));
            left++;
            right++;

        }
        return ans;
        
    }
};