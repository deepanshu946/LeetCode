class Solution {
private:
int solve(int curr , bool copy , int count ,int n){
    if(count > n){
        return 1e9;
    }
    if(count == n){
        return 0;
    }
    if(!copy){
        return 1+min(solve(curr,0,count+curr,n),solve(count,1,count,n));
    }
    else{
        return 1+solve(curr,0,count+curr,n);
    }
}
public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        return 1+solve(1,0,1,n);
    }
};