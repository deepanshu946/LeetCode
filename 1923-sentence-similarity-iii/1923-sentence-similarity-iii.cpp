class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        if(s2.length() > s1.length()){
            string temp = s2;
            s2=s1;
            s1=temp;
        }    
        // return false;
        int len1 = s1.length();
        int len2 = s2.length();
        bool flag = 0;
        if(s2 == s1.substr(0,len2)  ){
            if(s1[len2]==' ' ){
                return true;
            }
            flag = 1;
        }
        if(s2==s1.substr(len1-len2 , len2)){
            if(s1[len1-len2-1] == ' '){
                return true;
            }
            if(flag==1){
                return false;
            }
        }
        cout<<"i am here"<<endl;
        int spaceindex = 0;
        int i=0;
        int j=0;
        while(s1[i] == s2[j]){
            if(s1[i]==' '){
                spaceindex=i;
            }
            i++;
            j++;
        }
        if(spaceindex==0){
            return false;
        }
        i=len1-1;
        j=len2-1;

        while(j != spaceindex){
            
            if(s1[i] != s2[j]){
                break;
            }
            
            j--;
            i--;
        }
        if(j!=spaceindex ){
            return false;
        }
        if(s2[j]==' ' && s1[i] != ' '){
            return false;
        }
        return true;




    }
};