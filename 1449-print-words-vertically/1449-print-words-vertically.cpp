class Solution {
public:
    vector<string> printVertically(string s) {
        int words=0;
        vector<string> ans;
        int i=0 ; 
        // for(int i=0 ; i<s.length() ; i++){
        //     if(s[i] == ' '){
        //         words++;
        //     }
        // }
        while(i<s.length()){
            int index = 0;
            while(i<s.length() && s[i] != ' '){
                if(ans.size() <= index){
                    string temp = "";
                    for(int j=0 ; j<words ; j++){
                        temp.push_back(' ');
                    }
                    temp.push_back(s[i]);
                    ans.push_back(temp);
                }
                else{
                    ans[index].push_back(s[i]);
                }
                index++;
                i++;
            }
            // if(index<ans.size())
            while(index < ans.size()){
                ans[index].push_back(' ');
                index++;
            }
            words++;
            i++;
        }
        for(int i=0 ; i<ans.size() ; i++){
            int j=ans[i].length()-1;
            while(j>=0 && ans[i][j] == ' '){
                ans[i].pop_back();
                j--;
            }
        }
        return ans;
    }
};