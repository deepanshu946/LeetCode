class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int i = 0;
        long long sum = 0;
        for(int j=0 ; j<n ; j++){
            sum = sum + chalk[j];
        }
        k = k % sum;
        while(true){
            if(chalk[i] > k){
                break;
            }
            k = k - chalk[i];
            i = (i+1) % n;
        }
        return i;
    }
};