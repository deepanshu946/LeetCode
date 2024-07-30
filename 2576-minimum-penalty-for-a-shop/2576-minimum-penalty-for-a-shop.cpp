class Solution {
public:
    int bestClosingTime(string nums) {
        int n = nums.length();
        vector<int> temp(n+1,0);
        for(int i=1 ; i<=n ; i++){
            if(nums[i-1]=='N'){
                temp[i]=temp[i-1]+1;
            }
            else{
                temp[i]=temp[i-1];
            }
            
        }
        vector<int> temp2(n+1,0);
        int ans = temp[n]+temp2[n] ;
        int time = n;

        for(int i=n-1 ; i>=0 ; i--){
            if(nums[i]=='Y'){
                temp2[i]=temp2[i+1]+1;
            }
            else{
                temp2[i]=temp2[i+1];
            }
        if(temp[i]+temp2[i] <= ans){
            time = i;
            ans = temp[i]+temp2[i];
        }

        }
        return time;

    }
};