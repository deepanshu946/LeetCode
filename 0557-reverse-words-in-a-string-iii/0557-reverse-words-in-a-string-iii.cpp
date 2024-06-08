class Solution {
private:
void reverse(int i , int j ,string &s){
    while(i<=j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
}
public:
    string reverseWords(string s) {
        int i=0;
        int j=0;
        while(i < s.length()){
            if(s[j]==' ' || s[j]=='\0'){
                reverse(i,j-1,s);
                i=j+1;
            }
            j++;
        }
        return s;
    }
};