class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0 || c==1){
            return true;
        }
        long long i = 1;
        long long j = sqrt(c);
        while(i<=j){
            if(i*i + j*j == c || i*i == c || j*j ==c){
                return true;
            }
            if(i*i + j*j > c){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};