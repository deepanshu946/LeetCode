class Solution {
public:
    int numberOfChild(int n, int k) {
        int count = k%(n-1);
        int dxn = k/(n-1);
        int index ;
        if(dxn % 2 == 0){
            return count;
        }
        else{
            return n-count-1;
        }
    }
};