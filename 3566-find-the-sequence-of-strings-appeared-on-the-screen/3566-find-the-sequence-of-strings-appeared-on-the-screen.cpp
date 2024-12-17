class Solution {
public:
    vector<string> stringSequence(string target) {
        string temp = "";
        vector<string> ans;
        for(int i=0 ; i<target.length() ; i++){
            temp.push_back('a');
            ans.push_back(temp);
            while(temp.back() != target[i]){
                char ch = temp.back();
                temp.pop_back();
                ch++;
                temp.push_back(ch);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};