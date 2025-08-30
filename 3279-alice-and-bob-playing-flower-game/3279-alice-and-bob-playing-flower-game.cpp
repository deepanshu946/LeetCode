class Solution {
public:
    long long flowerGame(int n, int m) {
        long long even1 = 0;
        long long odd1=0;
        // for(int i=1 ; i<=n ; i++){
        //     if(i%2==0){
        //         even1++;
        //     }
        //     else{
        //         odd1++;
        //     }
        // }
        if(n%2==0){
            even1 = n/2;
            odd1=n/2;

        }
        else{
            even1= n/2;
            odd1= (n/2) + 1;
        }
        long long even2=0;
        long long odd2=0;
         if(m%2==0){
            even2 = m/2;
            odd2=m/2;

        }
        else{
            even2= m/2;
            odd2= (m/2) + 1;
        }
        // cout<<even1<<" "<<odd1<<" "<<even2<<" "<<odd2<<endl;
        // for(int i=1 ; i<=m ; i++){
        //    if(i%2==0){
        //         even2++;
        //     }
        //     else{
        //         odd2++;
        //     }
        // }
        return (even1*odd2) + (even2*odd1);
            }
};