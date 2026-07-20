class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        int temp = n;
        while(temp!=0){
            int rem = temp%10;
            temp = temp/10;
            if(rem!=0){
                sum+= rem;
                num = (num*10)+rem;
            }

        }
        long long x = 0;
        temp = num;
        while(temp !=0){
            int rem = temp%10;
            temp = temp/10;
            if(rem!=0){
                x = (x*10)+rem;
            }

        }
        return x*sum;
    }
};