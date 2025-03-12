class Solution {
private:
int sum(vector<int> &m){
    int sum = 0;
    int maxi = 0;
    for(int i=0 ; i<m.size() ; i++){
        
        sum = sum + m[i];
        maxi = max(maxi,m[i]);
    
    }
    return sum-maxi;
}
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        vector<int> m(26,0);
        while(right < s.length()){
            m[s[right]-'A']++;
            while(sum(m) > k){
                m[s[left]-'A']--;
                left++;
            }
            ans = max(ans , right-left+1);
            right++;
        }
        return ans;
    }
};