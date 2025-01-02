class Solution {
private:
bool vovel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        return 1;
    }
    return 0;
}
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> temp(words.size()+1,0);
        int n = words.size();
        for(int i=n-1 ; i>=0 ; i--){
            if(vovel(words[i][0]) && vovel(words[i][words[i].length()-1])){
                temp[i]=1+temp[i+1];
            }
            else{
                temp[i]=temp[i+1];
            }
        }
        vector<int> ans;
        for(int i=0 ; i<queries.size() ;  i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int temp2 = 0;
            if(vovel(words[end][0]) && vovel(words[end][words[end].length()-1])){
                temp2=1;
            }
            ans.push_back(temp[start]-temp[end]+temp2);
        }
        return ans;
    }
};