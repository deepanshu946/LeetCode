class Solution {
private:
string convert(int n){
    string ans = "";
    while( n != 0){
        int rem = n%2;
        ans.push_back(rem+'0');
        n = n/2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
public:
    int minBitFlips(int start, int goal) {
        string s = convert(start);
        string e = convert(goal);
        int ans = 0;
        // cout<<s<<endl<<e<<endl;
        int i=s.length()-1;
        int j=e.length()-1;
        while(i>=0 && j>=0){
            if(s[i] != e[j]){
                ans++;
            }
            i--;
            j--;
        }
        while(j>=0){
            if(e[j]=='1'){
                ans++;
            }
            j--;
        }
        while(i>=0){
            if(s[i]=='1'){
                ans++;
            }
            i--;
        }
        return ans;

    }
};