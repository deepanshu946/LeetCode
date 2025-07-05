class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right = 0;
        int count = 0;
        int n = s.length();
        vector<int> a(s.length(),-1);
        vector<int> b(s.length(),-1);
        vector<int> c(s.length(),-1);
        if(s[s.length()-1] == 'a'){
            a[s.length()-1]=s.length()-1;
        }
        if(s[s.length()-1] == 'b'){
            b[s.length()-1]=s.length()-1;
        }
        if(s[s.length()-1] == 'c'){
            c[s.length()-1]=s.length()-1;
        }
        for(int i = s.length()-2 ; i>=0 ; i--){
            if(s[i]=='a'){
                a[i]=i;
            }
            else{
                a[i]=a[i+1];
            }
        }
        for(int i = s.length()-2 ; i>=0 ; i--){
            if(s[i]=='b'){
                b[i]=i;
            }
            else{
                b[i]=b[i+1];
            }
        }
        for(int i = s.length()-2 ; i>=0 ; i--){
            if(s[i]=='c'){
                c[i]=i;
            }
            else{
                c[i]=c[i+1];
            }
        }

        for(int i=0 ; i<s.length(); i++){
            int val1=0;
            int val2=0;
            if(s[i]=='a'){
                val1 = b[i];
                val2=c[i];
            }
            if(s[i]=='b'){
                val1 = a[i];
                val2=c[i];
            }
            if(s[i]=='c'){
                val1 = b[i];
                val2=a[i];
            }
            if(val1!=-1 && val2!=-1){
                count = count + s.length()-max(val1,val2);
            }
        }
        // for(int i=0 ; i<s.length();i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0 ; i<s.length();i++){
        //     cout<<b[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0 ; i<s.length();i++){
        //     cout<<c[i]<<" ";
        // }
        // cout<<endl;

        return count;

    }
};