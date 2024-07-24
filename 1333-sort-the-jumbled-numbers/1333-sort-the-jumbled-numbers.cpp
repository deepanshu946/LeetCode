class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        map<int,vector<int>> ans;
        for(int i=0  ; i<nums.size() ; i++){
            int num = nums[i];
            int tempval = nums[i];
            int k=0;
            int val = 0;
            if(num==0){
                val=mapping[num];
            }
            else{
                while(num!=0){
                int digit = num%10;
                num=num/10;
                val = val + (mapping[digit] * pow(10,k));
                k++;
            }
            }
            cout<<val<<endl;
            cout<<num<<endl;
            ans[val].push_back(tempval);
        }
        vector<int> temp;
        for(auto i:ans){
            vector<int> li=i.second;
            for(int j=0 ; j<li.size() ; j++){
                temp.push_back(li[j]);
            }
        }
        return temp;
    }
};