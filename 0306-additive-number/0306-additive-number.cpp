class Solution {
private:
bool solve(string num , __int128 prev1 , __int128 prev2 , int index , int count){
    if(index==num.length() && prev1 != -1 && prev2 != -1 && count>=3){
        return true;
    }

    __int128 temp = 0;
    bool ans = 0;
    for(int i=index ; i<num.length() ; i++){
        temp = temp*10 + num[i]-48;
        if(i-index >= (index+num.length())/2 ){
            break;
        }
        if(prev1==-1 && prev2==-1){
            ans = ans || solve(num,temp,prev2,i+1,count+1);
        }
        else if(prev2==-1){
            ans = ans||solve(num,prev1,temp,i+1,count+1);
        }
        else if(temp == prev1 + prev2){
            ans = ans || solve(num,prev2, temp,i+1,count+1);
        }
        if(temp==0){
            break;
        }
    }
    return ans;
}
public:
    bool isAdditiveNumber(string num) {
        if(num.length()<3){
            return false;
        }
        return solve(num,-1,-1,0,0);
    }
};