class Solution {
private:
bool isvovel(char ch){
    if(ch=='a' || ch=='e'||ch=='i'||ch=='o' || ch=='u'){
        return true;
    }
    return false;
}
public:
    int maxVowels(string s, int k) {
        int left =0;
        int right = k-1;
        int ans = 0;
        for(int i=0 ; i<k ; i++){
            if(isvovel(s[i])){
                ans++;
            }
        }
        int windowans = ans;
        while(right<s.length()){
            int temp = 0;
            if(isvovel(s[left])){
                windowans -=1;
            }
            right++;
            if(isvovel(s[right])){
                windowans += 1;
            }
            left++;
   
            ans = max(ans , windowans);
        }
        return ans;


    }
};