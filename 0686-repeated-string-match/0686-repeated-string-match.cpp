class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int count = 1;
        while(a.length() < b.length()){
            a.append(temp) ;
            count++;
        } 
        if(a.contains(b)){
            return count;
        }
        a = a+temp;
        if(a.contains(b) ){
            return count+1;
        }
        return -1;
    }
};