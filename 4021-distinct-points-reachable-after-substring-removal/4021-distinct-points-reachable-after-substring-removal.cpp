class Solution {
public:
    int distinctPoints(string s, int k) {
        set<pair<int,int>> se;
        int x = 0;
        int y = 0;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]=='U'){
                y=y+1;
            }
            if(s[i]=='D'){
                y=y-1;
            }
            if(s[i]=='R'){
                x=x+1;
            }
            if(s[i]=='L'){
                x=x-1;
            }
        }
        cout<<x<<endl<<y<<endl;
        int start = 0;
        int end = k;
        int tx= 0;
        int ty = 0;
        for(int i=start ; i<end ; i++){
            if(s[i]=='U'){
                ty=ty+1;
            }
            if(s[i]=='D'){
                ty=ty-1;
            }
            if(s[i]=='R'){
                tx=tx+1;
            }
            if(s[i]=='L'){
            tx=tx-1;
            }
        }
        se.insert({x-tx,y-ty});
        // cout<<x-tx<<endl<<y-ty<<endl;

        while(end<s.length()){
            if(s[start]=='U'){
                ty=ty-1;
            }
            if(s[start]=='D'){
                ty=ty+1;
            }
            if(s[start]=='R'){
                tx=tx-1;
            }
            if(s[start]=='L'){
            tx=tx+1;
            }
            start++;
            if(s[end]=='U'){
                ty=ty+1;
            }
            if(s[end]=='D'){
                ty=ty-1;
            }
            if(s[end]=='R'){
                tx=tx+1;
            }
            if(s[end]=='L'){
            tx=tx-1;
            }
            end++;
        se.insert({x-tx,y-ty});
        // cout<<x-tx<<endl<<y-ty<<endl;

        }
        return se.size();

    
    }
};