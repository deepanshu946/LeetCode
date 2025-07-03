class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0;
        for(int i =0 ; i<nums.size() ; i++){
            pq.push(nums[i]);
            sum += nums[i];
        }
        // double temp= 0;
        int count = 0;
        double half = sum/2;
        while(sum > half  ){
            double t = pq.top();
            pq.pop();
            t = t/2;
            sum = sum - t;
            pq.push(t);
            count++;
        }
        return count;

    }
};