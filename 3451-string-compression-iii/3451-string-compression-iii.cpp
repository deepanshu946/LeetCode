class Solution {
public:
    string compressedString(string word) {
        string ans;
        int i=0 ;
        while(i<word.length()){
            int count = 0;
            int ch = word[i];
            while(i<word.length() && count <9 && word[i]==ch){
                count++;
                i++;
            }
            ans.push_back(count+'0');
            ans.push_back(ch);

        }
        return ans;
    }
};