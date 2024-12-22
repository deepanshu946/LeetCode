class Solution {
private:
int solve(int i , vector<string> &words , unordered_map<char,int> &m ,vector<int>& score , int n ){
    if(i>=n){
        return 0;
    }
    int inc = INT_MIN;
    int val = 0;
    bool flag = 1;
    for(int j=0 ; j<words[i].length() ; j++){
        char ch = words[i][j];
        m[ch]--;
        val = val + score[ch-'a'];
        if(m[ch]<0){
            flag=0;
        }
    }
    if(flag){
        inc = val + solve(i+1,words,m,score,n);
    }
    for(int j=0 ; j<words[i].length() ; j++){
        char ch = words[i][j];
        m[ch]++;
    }
    int exc = solve(i+1,words,m,score,n);
    return max(inc,exc);
}
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> m;
        for(int i=0 ; i<letters.size() ; i++){
            m[letters[i]]++;
        }
        int n = words.size();
        return solve(0,words,m,score,n);
    }
};