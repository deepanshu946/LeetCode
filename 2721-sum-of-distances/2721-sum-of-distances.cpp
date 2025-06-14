class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int , vector<long long>> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]].push_back(i);
        }
        vector<long long> ans(nums.size(),0);
        for(auto i:m){
            vector<long long> temp = i.second;
            vector<long long> rtl(temp.size(),0);
            vector<long long> ltr(temp.size(),0);
            for(int j=temp.size()-2 ; j>=0 ; j--){
                rtl[j]=rtl[j+1]+temp[j+1];
                // cout<<rtl[j]<<" ";
            }
            // cout<<endl;
            for(int j=1 ; j<temp.size() ; j++){
                ltr[j]=ltr[j-1]+temp[temp.size()-1]-temp[j-1];
                // cout<<ltr[j]<<" ";
            }
            // cout<<endl;
            for(int j=0 ; j<temp.size() ; j++){
                long long sum=0;
                sum = rtl[j]-((temp.size()-j-1)*temp[j]);
                sum += ltr[j]-((j)*(temp[temp.size()-1]- temp[j]));
                // cout<<sum<<" ";
                ans[temp[j]]=sum;
            }
        }
        return ans;
    }
};