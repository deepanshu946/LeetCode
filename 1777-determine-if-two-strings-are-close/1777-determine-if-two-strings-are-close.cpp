class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()){
            return false;
        }
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0 ; i<word1.length() ; i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        map<int,int> count1;
        map<int,int> count2;
        for(auto i:m1){
            if(m2.find(i.first) == m2.end()){
                return false;
            }
        }
        for(auto i:m1){
            count1[i.second]++;
        }
        for(auto i:m2){
            count2[i.second]++;
        }
        return count1==count2;
        // return true;
    }
};