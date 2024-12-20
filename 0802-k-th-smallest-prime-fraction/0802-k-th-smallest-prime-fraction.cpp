class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<double> pq;
        int n = arr.size();
        vector<vector<double>> temp(n,vector<double>(n,0));
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                double ans = (double)arr[i]/arr[j];
                if(pq.size() < k){
                    pq.push(ans);
                }
                else if(pq.size()==k){
                    if(pq.top()>ans){
                        pq.pop();
                        pq.push(ans);
                    }
                }
                temp[i][j]=ans;
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ;j<n ; j++){
                if(temp[i][j]==pq.top()){
                    return {arr[i],arr[j]};
                }
            }
        }
        return {};
        
        
    }
};