class Solution {
private:
bool check(string s , string t){
    for(int i=0 ; i<s.length() ; i++){
        if(s[i] != t[i]){
            return false;
        }
    }
    return true;
}
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
    //     sort(dictionary.begin() , dictionary.end());
    //     int i=0;
    //     string word = "";
    //     string ans = "";
    //     bool flag = false;
    //     while(i<sentence.length()){
    //         while(true){
    //             if(sentence[i] == ' ' || sentence[i] == '\0'){
    //                 break;
    //             }
    //             else{
    //                 word = word + sentence[i];
    //             }
    //             i++;
    //         }
    //         for(int j=0 ; j<dictionary.size() ; j++){
    //             if(check(dictionary[j] , word)){
    //                 ans = ans + dictionary[j];
    //                 flag = true;
    //                 break;
    //             }
    //         }
    //         if(!flag){
    //             ans = ans + word;
    //         }
    //         flag = false;
    //         ans = ans + ' ';
    //         word = "";
    //         i++;
    //     }
    //     ans.pop_back();
    //     return ans;
    // }
    unordered_set<string> S(dictionary.begin(), dictionary.end());
        
        // split the sentence & find ans
        string ans, word;
        bool isFound=0;

        for (char c: sentence) {
            if (c!= ' ') {
                word+=c;
                if (!isFound && S.count(word)) {
                    ans+=word;
                    isFound=1;
                }
            } 
            else {
                if (!isFound) ans+=word;
                ans+=' ';
                word="";
                isFound=0;
            }
        }
        if (!isFound)
            ans+=word;

        return ans;
    }

};