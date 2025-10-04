class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        int count = 0;
        long long temp = n;
        int last = 0;
        int digits = 0;
        while(temp != 0){
            last = temp%10;
            count = count + temp%10;
            temp = temp/10;
            digits++;
            
        }
        cout<<count<<endl;
        if(count<=target){
            return 0;
        }
        if(last>=target){
            long long temp2 = 1;
            for(int i=0 ; i<digits ; i++){
                temp2 = temp2*10;
            }
            return temp2-n;
        }
        temp = n;
        long long ans = 0;
        long long index = 1;
        while(count > target){
            int l = temp%10;
            temp = temp/10;
            if(index==1){
                ans = ans + 10 - l;
                count = count - l + 1;
                index = index*10;
            }
            else{
                ans = ans + (10 - l - 1)*index;
                count = count - l;
                index = index*10;
            }

        }
        return ans;
        


    }
};