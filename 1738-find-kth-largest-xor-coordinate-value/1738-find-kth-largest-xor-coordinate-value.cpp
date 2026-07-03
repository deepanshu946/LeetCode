class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int> , greater<int>> pq;
        for(int j=0 ; j<matrix[0].size() ; j++){
            for(int i=1 ; i<matrix.size() ; i++){
                matrix[i][j] = matrix[i][j]^matrix[i-1][j];
            }
        }
        for(int i=0 ; i<matrix.size() ; i++){
            int ans = 0;

            for(int j=0 ; j<matrix[0].size() ; j++){
                if(j==0){
                    ans = matrix[i][j]; 
                }
                else{
                    ans = ans ^ matrix[i][j];
                }   
                
                if(pq.size()==k && pq.top() < ans){
                    pq.pop();
                    pq.push(ans);
                }
                else if(pq.size()<k){
                    pq.push(ans);
                }
            }
        }
        return pq.top();
    }
};