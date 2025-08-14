class Solution {
public:
    int addDigits(int num) {
        
        while(num > 9 ){
            int temp = num;
            int ans = 0;
            while(temp != 0){
                ans = ans + temp%10;
                temp = temp/10;

            }
            num = ans;
        }
        return num;
    }
};