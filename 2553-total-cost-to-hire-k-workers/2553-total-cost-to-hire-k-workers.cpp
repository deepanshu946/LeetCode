class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int n) {

        priority_queue<int,vector<int> , greater<int>> pq1;
        int count1 = 0;
        int count2 = 0;
        int size = costs.size();
        // if(k==size){
        //     int sum = 0;
        //     for(int i=0 ; i<size ; i++){
        //         sum = sum + costs[i];
        //     }
        //     return sum;
        // }
        priority_queue<int,vector<int> , greater<int>> pq2;
        for(int i=0 ; i<n ; i++){
            if(count1+count2 < size){
                pq1.push(costs[i]);
                count1++;
            }
            if(count1+count2 < size){
                pq2.push(costs[size-i-1]);
                count2++;
            }
        }
        long long ans = 0;
        while(k--){
            if(pq1.empty()){
                ans = ans + pq2.top();
                pq2.pop();
            }
            else if(pq2.empty()){
                ans = ans + pq1.top();
                pq1.pop();

            }
            else if(!pq1.empty() && !pq2.empty() && pq1.top()<=pq2.top() ){
                ans = ans + pq1.top();
                pq1.pop();
                if(count1 + count2 < size){
                    pq1.push(costs[count1]);
                    count1++;
                }
            }
            else if(!pq1.empty() && !pq2.empty() ){
                ans = ans + pq2.top();
                pq2.pop();
                if(count1 + count2 < size){
                    pq2.push(costs[size - count2-1]);
                    count2++;

                }
            }
        }
        return ans;
        
    }
};