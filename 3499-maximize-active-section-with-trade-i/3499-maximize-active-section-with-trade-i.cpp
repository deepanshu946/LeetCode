class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s.push_back('1');
        reverse(s.begin(),s.end());

        s.push_back('1');
        reverse(s.begin(),s.end());
        cout<<s<<endl;

        int count = 0;
        bool inside10=1;
        int insidecount=0;
        int i=0;
        
        while(i<s.length()){
            if(s[i]=='1' ){
                count++;
                if(i+1>=s.length()) break;
                if(s[i+1]='0'){
                    i++;
                    int insideone=0;
                    int insidezerofirst=0;
                    int insidezerolast=0;
                    while(i<s.length()&& s[i]=='0'){
                        insidezerofirst++;
                        i++;
                    }
                    while(i<s.length()&& s[i]=='1'){
                        insideone++;
                        i++;
                    }
                    while(i<s.length() && s[i]=='0'){
                        insidezerolast++;
                        i++;
                    }

                    if(insidezerofirst != 0 && insideone!=0 && insidezerolast!=0){
                        if(i<s.length()){
                            count+=insidezerofirst+insideone+insidezerolast;
                            cout<<count<<endl;

                        }
                        else{
                            count+=insideone;
                        }
                    }
                    else{
                        count+=insideone;
                    }

                }
                else{
                    i++;
                    count++;
                }
            }
            else{
                i++;
            }
        }
        return count-2;


    }
};