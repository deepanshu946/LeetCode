class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        vector<int> m(26,0);
        vector<int> temp(26,0);
        for(int i=0 ; i<s1.length() ; i++){
            int val = s1[i]-97;
            m[val]++;
            int val2 = s2[i]-97;
            temp[val2]++;
        }
        int left=0;
        int right=s1.length()-1;
        while(right<s2.length()){
            if(temp==m){
                return true;
            }
            int val = s2[left]-97;
            temp[val]--;
            left++;
            right++;
            if(right==s2.length()){
                break;
            }
            val = s2[right]-97;
            temp[val]++;
        }
        return false;

    }
};