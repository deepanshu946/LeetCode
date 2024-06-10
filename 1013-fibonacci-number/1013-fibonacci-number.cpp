class Solution {
public:
    int fib(int n) {
        // recursive approach
    //     //base case
    //     if(n==0)
    //     return 0;
    //     if(n==1)
    //     return 1;

    // return fib(n-1)+fib(n-2);   
    if(n==0){
        return 0;
    }
    int prev1 = 1;
    int prev2= 0;
    for(int i=2 ; i<=n ; i++){
        int curr = prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;

    }

};