class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<vector<int>> temp(n,vector<int>(2));
        for(int i=0 ; i<startTime.size() ; i++){
            temp[i][0] = startTime[i];
            temp[i][1] = endTime[i];

        }
        int first = temp[0][0];
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        // prefix[0]=0;
        int end = eventTime - temp[n-1][1];
        // suffix[n-1]=0;
        prefix[1]=first;
        suffix[n-2]=end;
        for(int i=2 ; i<n ; i++){
            prefix[i]=max(prefix[i-1],temp[i-1][0]-temp[i-2][1]) ;
        }
        for(int i=n-3 ; i>=0 ; i--){
            suffix[i]= max(suffix[i+1],temp[i+2][0]-temp[i+1][1]);
        }
        int ans = max(first,end);

        for(int i=0 ; i<n ; i++){
            int pre = prefix[i];
            int suf = suffix[i];
            int size = temp[i][1]-temp[i][0];
            if(size <= pre || size<=suf){
                if(i==0){
                    ans = max(ans , size+first+temp[i+1][0]-temp[i][1]);
                }
                else if(i==n-1){
                    ans = max(ans , size+end+temp[i][0]-temp[i-1][1]);
                }
                else{
                    ans = max(ans , size+temp[i][0]-temp[i-1][1]+temp[i+1][0]-temp[i][1]);
                }
            }
            else{
                if(i==0){
                    ans = max(ans , first+temp[i+1][0]-temp[i][1]);
                }
                else if(i==n-1){
                    ans = max(ans , end+temp[i][0]-temp[i-1][1]);
                }
                else{
                    ans = max(ans , temp[i][0]-temp[i-1][1]+temp[i+1][0]-temp[i][1]);
                }
            }
        }
        return ans;




    }
};