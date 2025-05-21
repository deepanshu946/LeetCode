class Solution {
private:
int solve(vector<int> &store){
    vector<int> temp = store;
    sort(temp.begin(),temp.end());
    int minn=INT_MAX;
    int maxx=INT_MIN;
    for(int i=0 ; i<temp.size() ; i++){
        if(temp[i] != 0){
            minn=min(minn,temp[i]);
            maxx=max(maxx,temp[i]);
        }
    }
    return maxx-minn;
}
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i=0 ; i<s.length() ; i++){
            vector<int> store(26,0);
            for(int j=i ; j<s.length() ; j++){
                store[s[j]-'a']++;
                ans = ans + solve(store);
            }
        }
        return ans;
    }
};