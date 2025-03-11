class Solution {
private:
void solve(int i, string &temp , int len , string &ans , unordered_set<string> &s){
    if(ans != ""){
        return;
    }
    if(i>=len){
        return;
    }
    if(s.find(temp) == s.end()){
        ans = temp;
    }
    solve(i+1,temp,len,ans,s);
    temp[i]='1';
    if(s.find(temp) == s.end()){
        ans = temp;
    }
    solve(i+1,temp,len,ans,s);
    temp[i]='0';
    return;

}
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int si = nums[0].length();
        string temp = "";
        for(int i=0 ; i<si ; i++){
            temp = temp + '0';
        }
        unordered_set<string> s(nums.begin(),nums.end());
        string ans = "";
        solve(0,temp,si,ans,s);
        return ans;

    }
};