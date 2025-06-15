class Solution {
public:
    int maxDiff(int num) {
        string temp = to_string(num);
        int minn = INT_MAX;
        int maxx=INT_MIN;
        for(int x=0 ; x<=9 ; x++){
            for(int y=0 ; y<=9 ; y++){
                string temp2=temp;
                bool nochange=0;
                for(int i=0 ; i<temp2.size() ; i++){
                    if(x==temp2[i]-'0'){
                        if(y==0 && i==0){
                            nochange=1;
                            break;
                        }
                        temp2[i]=y+'0';
                    }
                }
                int numm = stoi(temp2);
                if(numm==0){
                    nochange=1;
                }
                minn=min(numm , minn);
                maxx=max(numm,maxx);
            }
        }
        return maxx-minn;
    }
};