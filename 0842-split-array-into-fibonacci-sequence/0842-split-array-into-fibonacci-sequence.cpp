class Solution {
private:
void solve(int i , string num , vector<int> &ans , vector<int> &temp){
    if(i==num.length()){
        int count = 0;
        for(int j=0 ; j<temp.size() ; j++){
            string t = to_string(temp[j]);
            count=count+t.length();
        }
        if(count==num.length() && temp.size()>=3){
            ans=temp;

        }
        return;
    }
    long long val = 0;
    for(int ind = i ; ind < num.length() ; ind++){
        val = (val*10 )+ (num[ind]-'0');
        if(val > INT_MAX){
            break;
        }
        if(temp.size()<2){
            temp.push_back(val);
            solve(ind+1,num,ans,temp);
            temp.pop_back();
        }
        else{
            long long a = temp[temp.size()-1];
            long long b = temp[temp.size()-2];
            if(val==a+b){
                temp.push_back(val);
                solve(ind+1,num,ans,temp);
                temp.pop_back();
            }
            else if(val>a+b || val==0){
                break;
            }

        }
    }
}
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        vector<int> temp;
        solve(0,num,ans,temp);
        return ans;
    }
};