class Solution {
private:
int solve(int red , int blue , bool blueturn , int rowsize){
    if(blueturn){
        if(rowsize>blue){
            return 0;
        }
    }
    else{
        if(rowsize>red){
            return 0;
        }
    }
    if(blueturn){
        return 1+solve(red,blue-rowsize,0,rowsize+1);
    }
    else{
        return 1+solve(red-rowsize,blue,1,rowsize+1);
    }

}
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red,blue,0,1),solve(red,blue,1,1));
    }
};