class Solution {
private:
bool check(vector<int> &t1 , vector<int> &t2){
    for(int i=0 ; i<26 ; i++){
        if(t1[i] != t2[i]){
            return false;
        }
    }
    return true;
}
public:
    bool checkInclusion(string s1, string s2) {
     vector<int> temp1(26,0);
     if(s2.length()< s1.length()){
        return false;
     }
     for(int i=0 ; i<s1.length() ; i++){
        temp1[s1[i]-'a']++;
     }
        vector<int> temp2(26,0);
        for(int i=0 ; i<s1.length() ; i++){
            temp2[s2[i]-'a']++;
        }
        int right = s1.length();
        int left = 0;
        while(right<s2.length()){
            if(check(temp1,temp2)){
                return true;
            }
            temp2[s2[right]-'a']++;
            temp2[s2[left]-'a']--;
            right++;
            left++;


        }
        if(check(temp1,temp2)){
            return true;
        }
        return false;




    }
};