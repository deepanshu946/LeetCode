class Solution {
public:
    int passThePillow(int n, int time) {
        int dxn = time / (n-1);
        int left = time % (n-1);
        // int a = abs(time-n);
        if(dxn%2 ==0){
            return left+1;
        }
        return n-left;
    }
};