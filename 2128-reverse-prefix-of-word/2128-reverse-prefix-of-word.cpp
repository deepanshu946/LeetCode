class Solution {
private:
void reverse(int start , int end , string &s){
    if(start==end){
        return;
    }
    while(start<=end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
}
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        while(word[i] != ch && i<word.length()){
            i++;
        }
        if(word[i]==ch)
            reverse(0,i,word);
        return word;
    }
};