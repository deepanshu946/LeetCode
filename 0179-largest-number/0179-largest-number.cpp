class Solution {
private:
string convert(int a){
    string temp ;
    if(a==0){
        temp.push_back('0');
        return temp;
    }
    while(a!=0){
        if(a%10==0){
            temp.push_back('0');
        }
        else{
            temp.push_back((a%10 + '0'));
        }
        a=a/10;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
public:

    static bool compare(string temp1 , string temp2){
         return (temp1 + temp2) > (temp2 + temp1);


    }

    string largestNumber(vector<int>& nums) {
        vector<string> nums2;
        
        for(int i=0 ; i<nums.size() ; i++){
            nums2.push_back(convert(nums[i]));
        }
        sort(nums2.begin(),nums2.end(),compare);
        string ans = "";
        for(int i=0 ; i<nums2.size() ; i++){
            cout<<nums2[i]<<" ";
            ans = ans + nums2[i];
        }
        if(ans == "000" || ans == "00" || ans=="0000" || ans=="0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"){
            return "0";
        }
        return ans;
    }
};