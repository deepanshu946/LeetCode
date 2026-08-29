class Solution {
private:
int gcd(int a , int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
public:
    int maxValidSplits(vector<int>& nums) {
        int fina = 0;

        for(int i=0 ; i<=nums.size() ; i++){
            vector<int> temp;
            // cout<<"here"<<endl;
            for(int j=0 ; j<nums.size() ; j++){
                if(j!=i){
                    temp.push_back(nums[j]);
                }
            }
            // cout<<temp.size()<<endl;
            int ans = 0;
            vector<int> pre;
            pre.push_back(temp[0]);
            int curr = temp[0];

            for(int j=1 ; j<temp.size() ; j++){
                curr = gcd(curr , temp[j]);
                // cout<<curr<<endl;
                pre.push_back(curr);
            }
            int suff = temp[temp.size()-1];
            for(int j=temp.size()-2 ; j>=0 ; j--){
                if(suff == pre[j]){
                    ans++;
                }
                suff = gcd(suff , temp[j]);
            }
            fina = max(fina,ans);

        }
        return fina;
    }
};