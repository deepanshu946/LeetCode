class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<int,char>> temp;
        vector<int> count(26,0);
        for(int i=0; i<word.length() ; i++){
            count[word[i]-'a']++;
        }
        for(int i=0 ; i<26 ; i++){
            if(count[i] != 0){
                temp.push_back({count[i],i+'a'});
            }
        }
        if(temp.size() < 9){
            return word.length();
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        int ans = 0;
        int strokes = 1;
        int currind = 1;
        for(auto i : temp){
            
            ans = ans + strokes*i.first;
            currind++;
            if(currind==9){
                currind = 1;
                strokes++;
            }
            
        }
        return ans;
    }
};