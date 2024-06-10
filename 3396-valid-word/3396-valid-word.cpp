class Solution {
public:
    bool isValid(string word) {
        if(word.length()>=3){

        }
        else{
            return false;
        }
        int vcount = 0;
        int ccount=0;
        for(int i =0 ; i<word.length(); i++){
            char ch = word[i];
            if((ch >= 48 && ch<=57) || (ch >= 65 && ch<=90) ||(ch >= 97 && ch<=122)){

            }
            else{
                return false;
            }

            if(ch == 'a'|| ch =='e'|| ch =='i'|| ch =='o'|| ch =='u'|| ch =='A'|| ch =='E'|| ch =='I'|| ch =='O'|| ch =='U'){
                vcount++;
            }
            else if(ch >= 48 && ch<=57){

            }
            else{
                ccount++;
            }


        }
        if(ccount==0 || vcount==0){
            return false;
        }

        return true;
    }
};