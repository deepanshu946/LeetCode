class Solution {
public:
    long long flowerGame(int n, int m) {
        long long even1 = 0;
        long long odd1=0;
        for(int i=1 ; i<=n ; i++){
            if(i%2==0){
                even1++;
            }
            else{
                odd1++;
            }
        }
        long long even2=0;
        long long odd2=0;
        for(int i=1 ; i<=m ; i++){
           if(i%2==0){
                even2++;
            }
            else{
                odd2++;
            }
        }
        return (even1*odd2) + (even2*odd1);
            }
};