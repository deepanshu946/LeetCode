class Solution {
private:
int gcd(int a , int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int temp = numsDivide[0];
        for(int i=1 ; i<numsDivide.size() ; i++){
            temp = gcd(temp,numsDivide[i]);
        }
        cout<<temp<<endl;
        sort(nums.begin(),nums.end());
        for(int i=0 ; i<nums.size(); i++){
            if(temp%nums[i]==0 ){
                return i;
            }
        }
        return -1;
    }
};