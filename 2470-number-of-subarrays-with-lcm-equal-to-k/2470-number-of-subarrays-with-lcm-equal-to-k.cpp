class Solution {
private:
int gcd(int a , int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            int temp = nums[i];
            if(temp == k){
                ans++;
            }
            for(int j=i+1 ; j<nums.size() ; j++){
                temp = lcm(temp,nums[j]);
                if(temp == k){
                    ans++;
                }
                if(temp > k){
                    // cout<<i<<" "<<j<<endl;
                    break;
                }

            }

        }
        return ans;

    }
};