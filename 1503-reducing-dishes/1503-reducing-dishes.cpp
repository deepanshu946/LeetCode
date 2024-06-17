class Solution { 
private:
int solve(vector<int> &s , int n){
    vector<int> currindex(n+2,0);
    vector<int> nextindex(n+2,0);
    for(int index = n-1 ; index>=0 ; index--){
        for(int time = n ; time>=1 ; time--){
            int inc = s[index]*(time) + nextindex[time+1];
            int exc = nextindex[time];
            currindex[time]=max(inc,exc);
        }
        nextindex=currindex;
    }
    return nextindex[1];
}
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin() , satisfaction.end());
        // return solve(satisfaction,n);
        int ans=0;
        for(int i=0;i<satisfaction.size();i++){
           int sum=0;
           int count=1;
           for(int j=i;j<satisfaction.size();j++){
              sum+=satisfaction[j]*count;
              count++;
           }
        ans=max(ans,sum);
        }
        return ans;


    }
};